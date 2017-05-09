#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int f;
	int i = 0;

	f = open("./test", O_RDONLY);
	read(f, &i, sizeof(int));
	close(f);
	printf("%d\n", i);
	return(0);
}
