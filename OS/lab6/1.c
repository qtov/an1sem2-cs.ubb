#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	pid_t	pid;
	int		i;
	pid = fork();
	if (pid == -1)
	{
		//eroare
		perror("EROOR!!!\n");
		exit(1);
	}
	else if (pid == 0)
	{
		//cod proces fiu
		for (i=0; i<10;i++)
		{
			//sleep(2);
			printf("Proces fiu %d, cu parintele %d, iteratia %d\n", getpid(), getppid(), i);
		}
		exit(1);
	}
	else
	{
		//cod proces parinte
		for (i=0; i<10;i++)
		{
			//sleep(1);
			printf("\tproces parinte %d, am creat fiul: %d, iteratia %d\n", getpid(), pid, i);
		}
	}
	printf("Sfarsit program\n");

	return (0);
}
