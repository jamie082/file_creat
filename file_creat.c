/* linux file mode prog Jamie M.
 * 2021 */

#include "apue.h"
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

void error_function (void);

int errno;

int main (void)
{
	// pointers & structures
	
	int input;
	char *string[100];
	int fun_var[100];
	char *path = "temp.dat";

	int fd;

	int owner_id = 0, group_id = 0, world_id = 0;

	struct stat SMetaData;

	//int ret_value = error_function ();
	
	strcpy(fun_var, "> ");
	printf("File Formater v. 0.01!\n\nError Code #: %d\nFile Type: \n", path);
	printf("Insert file name to create: ");
	scanf("%s", &string);

	strcat(fun_var, string);
	strcat(fun_var, ".dat");

	printf("%s\n", fun_var);

	if ((fd = creat(path, S_IWGRP | S_ISGID)) < 0) // set file modes
	{
		if (chmod(path, S_IXGRP) == 1)
		{
			printf("%s", path);
		}
	}

	sleep(1);

	printf("*chmod> File mode: ");
	scanf("%d", &owner_id);

	printf("file bits: o:%i:g:%i:o:%i\n", owner_id, owner_id, owner_id);

	error_function();

	stat (path, &SMetaData);

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

void error_function (void)
{
	char *path = "temp";

	if (!access(path, F_OK) > 0)
	{
		printf("File found\n");
	}
	
	else if (access(path, F_OK) != 0)
	{
		printf("File not found\n");
	}

}
