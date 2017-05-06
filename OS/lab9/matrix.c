#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_TH 4
#define MX_L 4

int		matrix[MX_L][MX_L];

void*	do_stuff(void* _matrix)
{
	int**	matrix;
	int		i, j;

	matrix = (int**)_matrix;
	for (i = 0; i < MX_L; i++)
	{
		for (j = 0; j < MX_L; j++)
			printf("%d ", matrix[i][1]);
	}
	pthread_exit(NULL);
}

int		main()
{
	pthread_t	threads[NUM_TH];
	long		i, j;
	int			err;
	int			matrix[MX_L][MX_L];

	for (i = 0; i < MX_L; ++i)
		for (j = 0; j < MX_L; ++j)
		{
			matrix[i][j] = 0;
		}

	for (i = 0; i < NUM_TH; ++i)
	{
		err = pthread_create(&threads[i], NULL, do_stuff, (void*)matrix);
		if (err)
		{
			printf("POTATOES!! ERORRESSSDADASDAS\n");
			exit(-1);
		}
	}
	return (0);
}
