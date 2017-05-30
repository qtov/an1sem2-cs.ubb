#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

pthread_attr_t attr;
int count = 0;
pthread_mutex_t mutex;

void* pthread_do(void* arg)
{
	char* str;
	FILE* f;
	int chr;

	str = (char*)arg;
	f = fopen(str, "r");
	if (f == NULL)
		return NULL;

	while ((chr = fgetc(f)) != EOF)
	{
		pthread_mutex_lock(&mutex);
		if (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u')
			++count;
		if (chr == 'A' || chr == 'E' || chr == 'I' || chr == 'O' || chr == 'U')
			++count;
		pthread_mutex_unlock(&mutex);
	}

	free(str);
	fclose(f);
	return NULL;
}

int	main(int argc, char **argv)
{
	int i = 0;
	pthread_t t[argc - 1];
	
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	for (i = 0; i < argc - 1; i++)
	{
		char* str;

		str = (char*)malloc(sizeof(char) * strlen(argv[i + 1]) + 1);
		strcpy(str, argv[i + 1]);
		pthread_create(&t[i], &attr, pthread_do, (void*)str);
	}
	pthread_attr_destroy(&attr);

	for (i = 0; i < argc - 1; i++)
		pthread_join(t[i], NULL);

	printf("%d -- total\n", count);

	return (0);
}
