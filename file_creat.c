/* linux file mode prog Jamie Morrissey
 * 9/9/2021 San Diego, CA */

#include "apue.h"
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

int error_function ();
void *value_function ();

int errno;

int main (void)
{
	// pointers & structures
	
	char *string[100];
	int fun_var[100];
	char *path = "temp.dat";

	int fd;

	int owner_id = 0;
	int group_id = 0;
      	int other_id = 0;

	struct stat SMetaData;

	strcpy(fun_var, "> ");
	printf("File Formater v. 0.01!\n\n");
	printf("Error Code: > "); // if false, ask to create file

	int a = 0;
	int error_value = 0;

	error_function();

	if (error_function(error_value) == 1)
	{
		printf("> True\n");
		value_function();
	}

	strcat(fun_var, string);
	strcat(fun_var, ".dat");

	printf("%ls\n", fun_var);
	
	if ((fd = creat(path, S_IWGRP | S_ISGID)) < 0) // set file modes
	{
		if (chmod(path, S_IXGRP) == 1)
		{
			printf("%s", path);
		}
	}

	sleep(1);

	char input[25];

	printf("What's file name you want?: ");
	scanf("%d", &input);

	int od=open(input, O_CREAT, 400);

	printf("*chmod> File mode: ");
	scanf("%d %d %d", &owner_id, &group_id, &other_id);

	printf("file bits: o:%d:g:%d:o:%d\n", owner_id, group_id, other_id);

	stat (path, &SMetaData);

	printf("File type: ");

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

void *value_function ()
{
	int error_value = 0;
	char *string;

	if ((error_value) == -1)
	{
		printf("Insert file name to create: ");
		scanf("%s", &string);
	}
}

int error_function ()
{
	char *path = "temp";
	int error_value = 0;

	if (!access(path, F_OK) > 0)
	{
		bool found_f = 0000001;

		printf("File found\n");
		error_value = 1;

		return error_value;
	}
	
	else if (access(path, F_OK) != 0)
	{
		bool found_f = 0000000;

		if (!found_f)
		{
			printf("\nFile not found!\n");
			error_value = -1;

			return error_value;
		}

		printf("%s\n", strerror(errno));
	}
}
