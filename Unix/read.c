#include "apue.h"

static void sig_alrm(int);

int main(void)
{
    int n;
    char line[MAXLINE];

    // Set up the signal handler for SIGALRM
    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
        err_sys("signal(SIGALRM) error");

    // Set an alarm for 10 seconds
    alarm(10);

    // Attempt to read from standard input
    if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
        err_sys("read error");

    // Retrieve the remaining time of the alarm, if any
    int remaining_time = alarm(0);
    printf("%d seconds remaining before the alarm\n", remaining_time);

    // Write the read input to standard output
    write(STDOUT_FILENO, line, n);

    // Exit the program
    exit(0);
}

// Signal handler for SIGALRM
static void sig_alrm(int signo)
{
    // Nothing to do, just return to interrupt the read
}

