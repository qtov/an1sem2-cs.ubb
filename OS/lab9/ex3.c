#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define NUM_TH 4

void *BusyWork (void *t) {
	int i;
	long tid;
	double res = 0.0;
	tid = (long) t;
	printf ("Start thread %ld...\n", tid);
	for (i = 0; i < 1000000; i++) {
		res += sin(i) * tan(i);
	}
	//sleep(2);
	printf ("Sfarsit thread %ld. Rezultatul este %e\n", tid, res);
	pthread_exit ((void *) t);
}

int main (int argc, char *argv[]) {
	pthread_t thread[NUM_TH];
	pthread_attr_t attr;
	int rc;
	long t;
	void *status;

	// Initializare thread si setare status
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_JOINABLE);

	for (t = 0; t < NUM_TH; t++) {
		printf ("Proces main: se creaza thread-ul %ld\n", t);
		rc = pthread_create (&thread[t], &attr, BusyWork, (void *) t);
		if (rc) {
			printf ("ERROR; codul de retur pentru pthread_create() este %d\n", rc);
			exit (-1);
		}
		//sleep(2);
	}

	//Eliberez atributele si astept dupa celelalte thread - uri
	pthread_attr_destroy (&attr);
	for (t = 0; t < NUM_TH; t++) {
		rc = pthread_join (thread[t], &status);
		if (rc) {
			printf ("ERROR; codul de retur pentru pthread_join() este %d\n", rc);
			exit (-1);
		}
		printf("Proces main: am terminat join cu thread-ul %ld avand statusul %ld\n",
				t, (long) status);
		//sleep(1);
	}

	printf ("Proces main: gata!\n");
	pthread_exit (NULL);
}
