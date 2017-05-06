#include <pthread.h>
#include <stdio.h>

void*	say_here(void* i)
{
	printf("%ld -this one\n", (long)i);
	pthread_exit(NULL);
}

int	main()
{
	long		i;
	int			msg;
	pthread_t	thread[7];
		

	for (i = 0; i < 7; i++)
	{
		printf("creez\n");
		msg = pthread_create(&thread[i], NULL, say_here, (void*)i);
		if (msg)
		{
			printf("errors\n");
			exit(-1);
		}
		pthread_exit(NULL);
	}
	return (0);
}
