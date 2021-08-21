#include "apue.h"
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

extern int errno;

int main (void)
{
	char *path = "temp.file";

	printf("Creating file...'%s'\n", path);

	if (open(path, O_CREAT) == 1)  // creat file
	{
		printf("True\n");
	}

	else if (chmod(path, S_IRUSR)) // True
	{
		printf("Directory is write protected\n"); // only printing if directory is -w
		printf("%d ", errno);
		printf("%s\n", strerror(errno));
	}

	/* output mode of file */

	else if (open(path, O_CREAT) == -1)
	{
		if (fd = 1)
		{
			printf("File created\n");
		}

		switch (S_IRUSR) // print out permissions of temp.file
		{
			case S_IRWXU:
				printf("read, write, and execute by user (owner)");
				break;
			case S_IRWXG:
				printf("read, write, and execute by group");
				break;
			case S_IRWXO:
				printf("read, write, and execute by other (world)");
				break;
		}

		else
		{
			printf("Directory is write protected\n");
			printf("%d ", errno);
			printf("%s\n", strerror(errno));
		}
	}

	exit(1);
}
