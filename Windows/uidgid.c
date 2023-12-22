#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>

int
main(void)
{
    char buffer[256];
    DWORD buffer_len = 256;
    GetUserNameA(buffer, & buffer_len);
    printf("%s\n",buffer);
	exit(0);
}
