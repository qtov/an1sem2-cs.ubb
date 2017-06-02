#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define CARNR 10000

pthread_mutex_t mutex;
pthread_cond_t cond;
pthread_mutex_t mutex2;
pthread_t t[100];
int direction = 1;
int car_nr = 0;

void* carz(void* arg)
{
	while (1)
	{
		if (direction == 0)
			return NULL;

		while (direction == 1)
		{
			++car_nr;
			printf("yolo1");
			sleep(1);
		}

		while (direction == -1)
		{
			++car_nr;
			printf("yolo-1");
			sleep(1);
		}
	}
}

void* pthread_do(void* arg)
{
	pthread_attr_t att;
	while (car_nr < CARNR)
	{
		pthread_mutex_lock(&mutex);

		pthread_attr_init(&att);
		pthread_attr_setdetachstate(&att, PTHREAD_CREATE_JOINABLE);


		int i = 0;
		for (i = 0; i < 100; i++)
			pthread_create(&t[i], NULL, carz, NULL);

		sleep(1);
		int tmp = direction;
		direction = 0;

		for (i = 0; i < 100; i++)
			pthread_join(t[i], NULL);

		pthread_attr_destroy(&att);

		direction = -tmp;

		if (car_nr >= CARNR)
			direction = 0;

		pthread_mutex_unlock(&mutex);
		pthread_cond_broadcast(&cond);
	}
	return NULL;
}

int	main()
{
	int i = 0;
	pthread_t tt[3];
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (i = 0; i < 1; i++)
	{
		pthread_create(&tt[i], &attr, pthread_do, NULL);
	}

	pthread_attr_destroy(&attr);

	for (i = 0; i < 1; i++)
		pthread_join(tt[i], NULL);

	return (0);
}
