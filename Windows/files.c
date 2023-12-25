#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <share.h>

int
main(int argc, char *argv[])
{
    int fd;
    if(argc != 2)
    {
        printf("Correct number of inputs not provided.\n");
        printf("You should use files with fileName.\n");
        exit(-1);
    }
    if(_sopen_s(&fd, argv[1], _O_RDWR | _O_CREAT, _SH_DENYNO, _S_IREAD | _S_IWRITE))
    {
        printf("File creation failed\n");
        exit(-2);
    }
    printf("File token: %d\n",fd);
    printf("Your file has been created successfully.");
    close(fd);
	exit(0);
}
