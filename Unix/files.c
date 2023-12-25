#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_MODE       (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char *argv[])
{

    	if(argc != 2)
    	{
        	printf("Correct number of inputs not provided.\n");
        	printf("you should use files with fileName.\n");
        	exit(-1);
    	}
	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
	if(fd < 0)
	{
		printf("Opening file error\n");
		exit(-2);
	}
    	printf("File token: %d\n",fd);
    	printf("Your file has been created successfully.\n");
    	close(fd);
	exit(0);
}
