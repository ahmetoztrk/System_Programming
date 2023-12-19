#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent	*dirp;

	if (argc != 2)
    {
		//err_quit("usage: myls directory_name");
		printf("usage: myls directory_name\n");
		exit(-1);
    }

	if ((dp = opendir(argv[1])) == NULL)
    {
		//err_sys("can't open %s", argv[1]);
		printf("Hata: can't open %s\n", argv[1]);
		exit(-2);
    }
	while ((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	exit(0);
}
