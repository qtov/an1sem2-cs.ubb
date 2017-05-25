#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int glob;
int glob_count;
pthread_attr_t attr;
pthread_mutex_t mutex;
pthread_cond_t cond;

void* thread_do(void* arg) //w/o cond -> slower
{
	do
	{
		int* index;

		index = (int*)arg;

		if (*index == glob && glob_count < 20)
		{
			pthread_mutex_lock(&mutex);

			int new_num = rand() % 10;
			while (new_num == *index)
				new_num = rand() % 10;

			++glob_count;
			printf("Threadul %d schimba nr %d in %d\n", *index, glob, new_num);
			glob = new_num;

			pthread_mutex_unlock(&mutex);
		}
	} while (glob_count < 20);

	free(arg);
	return NULL;
}

void* pthread_do(void* arg) //cond -> faster
{
	while (glob_count < 20)
	{
		pthread_mutex_lock(&mutex);
		int* index = (int*)arg;

		while (*index != glob && glob_count < 20)
			pthread_cond_wait(&cond, &mutex);

		if (glob_count < 20)
		{
			int new_num = rand() % 10;
			while (new_num == *index)
				new_num = rand() % 10;

			printf("Threadul %d schimba nr %d in %d\n", *index, glob, new_num);
	
			glob = new_num;
			++glob_count;
		}

		pthread_mutex_unlock(&mutex);
		pthread_cond_broadcast(&cond);
	}

	free(arg);
	return NULL;
}

int	main()
{
	pthread_t t[10];

	srand(time(NULL));
	glob = rand() % 10;
	glob_count = 0;

	int i;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	printf("Initial %d\n", glob);
	for (i = 0; i < 10; i++)
	{
		int* p;
		p = (int*)malloc(sizeof(int));
		*p = i;
		pthread_create(&t[i], &attr, pthread_do, p);
	}

	pthread_attr_destroy(&attr);

	for (i = 0; i < 10; i++)
		pthread_join(t[i], NULL);

	printf("%d -- schimbari totale.\n", glob_count);

	return (0);
}
