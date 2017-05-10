#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_TH 4

void* thread_do(void* arg)
{
  int *i = (int*)arg;
  printf("thread potato %d\n", *i);
  free(i);
  pthread_exit(NULL);
}

int main()
{
  int i = 0;
  pthread_t t[NUM_TH];
  for (i = 0; i < NUM_TH; i++)
  {
    int *j = (int*)malloc(sizeof(int));
    *j = i;
    pthread_create(&t[i], NULL, thread_do, j);
  }
  for (i = 0; i < NUM_TH; i++)
   pthread_join(t[i], NULL);
  return (0);
}a