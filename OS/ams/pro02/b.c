#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	srand(getpid());
	mkfifo("./b2a", 0666);
	
	int f, g;
	int num;

	f = open("./a2b", O_RDONLY);
	g = open("./b2a", O_WRONLY);

	do
	{
		read(f, &num, sizeof(int));
		printf("from: %d\n", num);
		if (num < 0) break;
		num -= rand() % 950 + 50;
		printf("to: %d\n", num);
		write(g, &num, sizeof(int));
	} while (num > 0);

	unlink("./b2a");

	return (0);
}
