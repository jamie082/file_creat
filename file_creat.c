#include "apue.h"
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

int errno;

mode_t getumask()
{
	mode_t mask = umask(0);
	umask (mask);

	return mask;
}

int main (void)
{
	mode_t mask = getumask();

	char *path = "temp";

	struct stat SMetaData;

	int fd = (open(path, O_RDONLY)); // file open

	if (open(path, O_CREAT)) // file create
	{
		if (fd < 0) // file successfully created
		{
			printf("Creating file...'%s'\n", path);

			if (errno == EEXIST)
			{
				printf("file exists\n");		
			}

			else
			{
				printf("> File doesn't exist\n");
			}

			stat(path, &SMetaData);
		}

		if (umask(mask) == -1)
		{
			//perror(argv[0]);
			exit(EXIT_FAILURE);
		}

		printf("%i", umask(path));	
		
		else
		{	
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
					printf("unknown? file type\n");
					break;
				}
			}
		}

		return 0;
}
