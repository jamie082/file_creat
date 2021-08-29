/* linux prog Jamie M 
 * 2021 */


#include "apue.h"
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

int errno;

mode_t getumask()
{
	mode_t mask = umask(S_IRWXG);
	umask (mask);

	return mask;
}

int main (void)
{
	mode_t mask = getumask();

	char *path = "temp";

	struct stat SMetaData;

	int fd = (open(path, O_RDONLY)); // file open

	if (umask(mask) == -1)
	{
		perror(path);
		exit(EXIT_FAILURE);
	}

	//printf("%d\n", mask);

	if (open(path, O_CREAT)) // file create
	{
		int rc;

		rc = chmod(path, 6244);

		printf("%i\n", umask(rc));

		if (fd == 0) // file successfully created
		{
			sleep(1);

			printf("Creating file...1....2.....3..ERROR!\n'%s'\n", path);
				
			if (errno != EEXIST)
			{
				printf("File doesn't exist\n");
			}

			stat(path, &SMetaData);
		}

		else if (fd > 1) // file unsuccessfully created
		{	
			printf("File exists\n");

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
