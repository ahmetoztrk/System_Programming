#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
	if (argc != 2)
    {
		//err_quit("usage: a.out <pathname>");
		printf("usage: a.out <pathname>");
		exit(-1);
    }
	if (access(argv[1], W_OK) < 0)
    {
		//err_ret("access error for %s", argv[1]);
		printf("access error for %s\n", argv[1]);
    }
	else
		printf("write OK\n");
	if (open(argv[1], O_RDONLY) < 0)
    {
		//err_ret("open error for %s", argv[1]);
		printf("open error for %s\n", argv[1]);
    }
	else
		printf("open for reading OK\n");
	exit(0);
}
