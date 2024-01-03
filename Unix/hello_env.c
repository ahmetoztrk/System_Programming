#include <stdio.h>

int main()
{
	extern char **environ;
	printf("environ[0]: %s\n", environ[0]);
	printf("environ[1]: %s\n", environ[1]);
	printf("environ[2]: %s\n", environ[2]);
	printf("environ[3]: %s\n", environ[3]);
	printf("environ[4]: %s\n", environ[4]);
	printf("Hello World!\n");
	return 2;
}
