#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int
main(void)
{
	struct _stat		statbuf;

	/* turn on set-group-ID and turn off group-execute */

	if (_stat("test.txt", &statbuf) < 0)
    {
		//err_sys("stat error for foo");
		printf("stat error for test.txt\n");
		perror("test");
		exit(-1);
    }
	if (chmod("test.txt", (statbuf.st_mode & ~_S_IWRITE)) < 0)
    {
        printf("chmod error for test.txt.\n");
        perror("test");
        exit(-2);
		//err_sys("chmod error for foo");
    }

	/* set absolute mode to "rw-r--r--" */

	if (chmod("test2.txt", _S_IREAD) < 0)
    {
		//err_sys("chmod error for bar");
        printf("chmod error for test2.txt.\n");
        perror("error");
        exit(-2);
    }

	exit(0);
}
