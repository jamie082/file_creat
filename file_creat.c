#include "apue.h"
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

extern int errno;

int main (void)
{
	const char *path = "temp.file";

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

	else if (open(path, O_CREAT) == -1)  // (open(path, O_CREAT) == 1)
	{
		printf("File created\n");
	}

	/* simple error handeling, if directory is write permission  */

	else
	{
		printf("%d ", errno);
		printf("%s\n", strerror(errno));
	}

	exit(1);
}
