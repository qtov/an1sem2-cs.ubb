int main()
{
	int f[2];

	pipe(f);
	if (fork() == 0)
	{
		int a;
		read(f[0], &a, sizeof(int));
		printf("%d\n", a);
		exit(0);
	}
	int b = 3;
	write(f[1], &b, sizeof(int));
	return (0);
}
