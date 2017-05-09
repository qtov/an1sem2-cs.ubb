#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 1000
#define TH_NUM 8
int	vector[SIZE];
int sum = 0;
pthread_t t[TH_NUM];

typedef struct q_st
{
	int a;
	int b;
} tq;

void*	thread_do(void* sum)
{
	int* size = (int*)sum;
	printf("%d\n", *size);
}

void	start_threads(int i, int left, int right)
{
	if (left < right)
	{
		
	}
	else
	{
		pthread_create(&t[i], NULL, thread_do, );
	}
}

int		main()
{
	int i;

	srand(getpid());

	for (i = 0; i < SIZE; i++)
	{
		vector[i] = rand() % 100;
	}

	start_threads(0, 0, 1000);

	for (i = 0; i < TH_NUM; i++)
		pthread_join(t[i], NULL);
	return (0);
}