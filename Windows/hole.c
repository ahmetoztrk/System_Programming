#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FILE_MODE 644

char	buf1[] = "abcdefghij";
char	buf2[] = "ABCDEFGHIJ";

int
main(void)
{
	int		fd;

	if ((fd = creat("file.hole", FILE_MODE)) < 0)
    {
		//err_sys("creat error");
		printf("create error\n");
		exit(-1);
    }

    printf("fd: %d\n",fd);

	if (write(fd, buf1, 10) != 10)
    {

		//err_sys("buf1 write error");
		printf("bufl write error\n");
		exit(-2);
	/* offset now = 10 */
    }

	if (lseek(fd, 16384, SEEK_SET) == -1)
    {

		//err_sys("lseek error");
		printf("lseek error\n");
		exit(-3);
	/* offset now = 16384 */
    }

	if (write(fd, buf2, 10) != 10)
    {
		//err_sys("buf2 write error");
		printf("buf2 write error\n");
		exit(-4);
	/* offset now = 16394 */
    }

	exit(0);
}
