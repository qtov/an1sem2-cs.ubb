#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void* thread_do(void *arg)
{
	char*	user;
	int		status;

	user = (char*)arg;
	char cmd[100];

	strcpy(cmd, "./lab11.sh ");
	strcat(cmd, user);
	status = system(cmd);

	if (WEXITSTATUS(status) == 0)
	{
		strcpy(cmd, "echo \"");
		strcat(cmd, user);
		strcat(cmd, ": `ps -u ");
		strcat(cmd, user);
		strcat(cmd, " | wc -l`\"");
		system(cmd);

	}
	else
	{
		printf("Userul %s nu este logat.\n", user);
	}

	free(user);
	return NULL;
}

int main(int argc, char** argv)
{
	FILE* f;
	char line[100];
	int n = 0;
	int i;

	f = fopen(argv[1], "r");

	while(fgets(line, 100, f))
		++n;
		
	rewind(f);
	pthread_t t[10];

	while (fgets(line, 100, f))
	{
		char *user;
		user = (char*)malloc(sizeof(char) * strlen(line));

		strcpy(user, line);
		user[strlen(user) - 1] = '\0';
		
		pthread_create(&t[i], NULL, thread_do, user);
		++i;
	}

	rewind(f);

	for (i = 0; i < n; i++)
	{
		pthread_join(t[i], NULL);
	}


	fclose(f);

	return (0);
}
