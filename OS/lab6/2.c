#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main()
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Erorare!!\n");
		exit(1);
	}
	else if (pid == 0)
	{
		//cod fiu
		printf("Proces fiu %d\n", getpid());
	}
	else
	{
		//cod parinte
		printf("proces parinte %d\n", getpid());
		wait(0);
		printf("gata parinte\n");
	}
	return (0);
}
