#include "apue.h"
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

int errno;

int main (void)
{
	char *path = "temp.file";

	struct stat SMetaData;

	printf("Creating file...'%s'\n", path);

	if (chmod(path, S_IRUSR)) // True
	{
		printf("Directory is write protected\n"); // only printing if directory is -w
		printf("%d ", errno);
		printf("%s\n", strerror(errno));
	}

	int fd = (open(path, O_RDONLY) == 1); // file open

	if (open(path, O_CREAT) == 1) // file create
	{
		if (fd) // file successfully created
		{
			printf("File opened successfully\n"); // print file created (successfully)

			if (open(path, O_CREAT) == 1)
			{
				perror("File is already open\n");
			}

			stat(path ,&SMetaData);
		
			switch (SMetaData.st_mode & S_IFMT) // print permissions of file
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
					printf("unknown?\n");
					break;
				}
		}
			

		if (!fd) // file error
		{
			perror("Error! Directory is write protected\n");
			printf("%d ", errno);
			printf("%s\n", strerror(errno));
		}
	}

	return 0;
}
