#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	int		c;

	while ((c = getc(stdin)) != EOF)
		if (putc(c, stdout) == EOF)
        {
			//err_sys("output error");
			printf("output error\n");
			exit(-1);
        }

	if (ferror(stdin))
    {
		//err_sys("input error");
		printf("input error\n");
		exit(-2);
    }

	exit(0);
}
