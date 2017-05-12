#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int f, g;

	srand(getpid());

	g = open("./a2b", O_RDONLY);
	f = open("./b2a", O_WRONLY);

	int num;
	int to_take;

	do
	{
		read(g, &num, sizeof(int));
		to_take = rand() % 950 + 50;
		num -= to_take;
		printf("%d\n", num);
		write(f, &num, sizeof(int));
	} while (num > 0);

	return (0);
}