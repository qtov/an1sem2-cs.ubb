#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	srand(getpid());
	mkfifo("./a2b", 0666);
	
	int f, g;
	int num = rand() % 10000 + 5000;

	f = open("./a2b", O_WRONLY);
	g = open("./b2a", O_RDONLY);
	
	write(f, &num, sizeof(int));
	printf("to: %d\n", num);

	while (num > 0)
	{	
		read(g, &num, sizeof(int));
		printf("from: %d\n", num);
		if (num < 0) break;
		num -= rand() % 950 + 50;
		printf("to: %d\n", num);
		write(f, &num, sizeof(int));
	}

	unlink("./a2b");

	return (0);
}
