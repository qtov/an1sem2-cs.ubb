#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	int f;

	if (fork() == 0)
		execlp("mkfifo", "mkfifo", "test", NULL);

	int i = 4;

	f = open("./test", O_WRONLY);
	write(f, &i, sizeof(int));
	
	close(f);

	return (0);
}
