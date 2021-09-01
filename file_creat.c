/* linux prog Jamie M.
 * 2021 */

#include "apue.h"
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <unistd.h>

void my_function (void);

int errno;

mode_t getumask()
{
	mode_t mask = umask(S_IRWXG);
	umask (mask);

	return mask;
}

int main (void)
{
	/*
	bool x = true;
	bool y = false;
	*/
	// pointers & structures

	mode_t mask = getumask();

	char *path = "temp.dat";

	struct stat SMetaData;

	/*
	int fd;
       	int rc = chmod(path, 6444);
	*/

	sleep(1);

	printf("File Format v. 0.01!\n\nFile Name: %s\nError Code #: \nFile Type: ", path);

	my_function();

	stat(path, &SMetaData);

	switch (SMetaData.st_mode & S_IFMT) // print permissions of file
	{	
		{
			case S_IFBLK:
				printf("block device\n");
				break;
			case S_IFCHR:
				printf("character device\n");
				break;
			case S_IFDIR:
				printf("directory\n");
				break;
			case S_IFIFO:
				printf("FIFO/pipe\n");
				break;
			case S_IFLNK:
				printf("symlink\n");
				break;
			case S_IFREG:
				printf("regular file\n");
					break;
			case S_IFSOCK:
				printf("socket\n");
				break;
			default:
				printf("unknown? file type\n");
				break;
			}
	}

	return 0;
}

void my_function (void)
{
	char *path = "temp";

	if (!access(path, F_OK) > 0)
	{
		printf("File found\n");
	}
	
	
	if (access(path, F_OK) == -1)
	{
		printf("File not found\n");
	}
}
