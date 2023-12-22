#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/utime.h>
#include <windows.h>

#define MAXLINE 256

int
main(void)
{
	char	buf[MAXLINE];
	char    buf2[MAXLINE];
	pid_t	pid;
	int		status;

	printf("%% ");	/* print prompt (printf requires %% to print %) */
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0; /* replace newline with null */

    sprintf(buf2, "%s /k %s", "cmd.exe", buf);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    memset(&si, 0, sizeof(si));
    si.cb = sizeof(si);

    CreateProcess(NULL,
                 buf2,
                 NULL,
                 NULL,
                 FALSE,
                 CREATE_NEW_CONSOLE,
                 NULL,
                 NULL,
                 &si,
                 &pi );
		printf("%% ");
	}
	exit(0);
}
