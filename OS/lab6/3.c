#include <stdio.h>
#include <unistd.h>

int	main()
{
	printf("rezultatul comenzii \"ls -l\"\n");
	execl("/bin/ls", "/bin/ls", "-l", NULL);
	//execlp("ls", "ls", "-l", NULL);
	printf("Daca ajung aiic -> eroare la execl()\n");
	return (2);
}
