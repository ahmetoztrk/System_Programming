#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

#define RW (_S_IREAD | _S_IWRITE)

int
main(void)
{
	_umask(0);
	if (creat("foo", RW) < 0)
    {
        printf("creat error for foo\n");
        exit(-1);
		//err_sys("creat error for foo");
    }
	_umask(_S_IWRITE);
	if (creat("bar", RW) < 0)
    {
        printf("creat error for bar\n");
        exit(-2);
		//err_sys("creat error for bar");
    }
	exit(0);
}
