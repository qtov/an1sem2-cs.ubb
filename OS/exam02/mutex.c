#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN 10
#define NUM_TH 8

typedef struct args
{	
	int start;
	int end;
} targ;

int numbers[LEN];
int count = 0;
pthread_mutex_t mutex;


void*	do_stuff(void* args)
{
	targ* potato;

	potato = (targ*)args;
	int i = 0;
	pthread_mutex_lock(&mutex);
	for (i = potato->start; i < potato->end; i++)
	{
		if (numbers[i] % 2 == 0)
			++count;
		printf("%d_", count);
	}
	pthread_mutex_unlock(&mutex);
	free(potato);

	return (0);
}


int main()
{
	pthread_t t[NUM_TH];

	int i = 0;

	for (i = 0; i < LEN; i++)
		numbers[i] = i;
	for (i = 0; i < 8; i++)
	{
		targ *t_arg;
		t_arg = (targ*)malloc(sizeof(t_arg));
		t_arg->start = (LEN / NUM_TH) * i;
		t_arg->end = (LEN / NUM_TH) * (i + 1);
		pthread_create(&t[i], NULL, do_stuff, t_arg);
	}
	for (i = 0; i < 8; i++)
		pthread_join(t[i], NULL);
	printf("\n%d\n", count);
	return (0);
}
