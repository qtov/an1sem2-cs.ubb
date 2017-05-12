#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int f, g;
	int err;

	err = mkfifo("./a2b", 666);
	//err = mkfifo("./b2a", 666);

	srand(getpid());

	f = open("./a2b", O_WRONLY);
	//g = open("./b2a", O_RDONLY);

	printf("here\n");

	int num = rand() % 10000 + 5000;
	int to_take;
	write(f, &num, sizeof(int));
	//while (num > 0)
	//{
		//read(g, &num, sizeof(int));
		to_take = rand() % 950 + 50;
		num -= to_take;
		printf("%d\n", num);
		//write(f, &num, sizeof(int));
	//}

	close(f);
	//close(g);

	return (0);
}
