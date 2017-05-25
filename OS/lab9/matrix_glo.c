#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_TH 8
#define MX_L 2000

int		a[MX_L][MX_L], b[MX_L][MX_L], c[MX_L][MX_L];

struct param
{
	int start_linie, sf_linie;
};

void	init_matrix()
{
	int i, j;

	for (i = 0; i < MX_L; ++i)
		for (j = 0; j < MX_L; ++j)
		{
			a[i][j] = rand() % 10;
			b[i][j] = rand() % 10;
		}
}

void*	do_stuff(void* arg)
{
	struct param *p = (struct param*)arg;
	int i,j,k;

	for (i = p->start_linie; i < p->sf_linie; ++i)
	{
		for (j = 0; j < MX_L; ++j)
		{
			int s = 0;

			for (k = 0; k < MX_L; ++k)
			{
				s += a[i][k] * b[k][i];
			}
			c[i][j] = s;
		}
	}
	pthread_exit(NULL);
}

int		main()
{
	int				i, start_l, sf_l;
	pthread_t		t[NUM_TH];
	struct param	par[NUM_TH];

	srand(getpid());
	init_matrix();
	time_t start = time(NULL);
	for (i = 0; i < NUM_TH; i++)
	{
		int rc;
		par[i].start_linie = i * (MX_L / NUM_TH);
		par[i].sf_linie = (i + 1) * (MX_L / NUM_TH);
		rc = pthread_create(&t[i], NULL, do_stuff, &par[i]);
		if (rc)
		{
			perror("ERRORSRSRSRS\n");
			exit(-1);
		}
	}
	for (i = 0; i < NUM_TH; ++i)
	{
		pthread_join(t[i], NULL);
	}
	time_t end = time(NULL);
	printf("%lu - A DURAT\n", end - start);
	return (0);
}
