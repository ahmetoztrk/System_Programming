#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define	BUFFSIZE	4096

int
main(void)
{
	int		n;
	char	buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
        {
			//err_sys("write error");
			printf("write error\n");
			exit(-1);
        }

	if (n < 0)
    {
		//err_sys("read error");
		printf("read error\n");
		exit(-2);
    }

	exit(0);
}
