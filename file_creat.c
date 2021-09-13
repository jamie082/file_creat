/* linux file mode prog Jamie Morrissey
 * 9/9/2021 San Diego, CA */

#define FNAME "helloworld"

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
	
	int fun_var[100];
	char *path = "temp.dat";

	int owner_id = 0;
	int group_id = 0;
      	int other_id = 0;

	struct stat SMetaData;

	printf("File Formater v. 0.01!\n\n");
	printf("Error Code: > "); // if false, ask to create file

	int error_value;

	if (error_function(error_value) == 1)
	{
		printf("> True\n");
	}

	
	if(error_function(error_value) == -1)
	{
		printf("> False\n");
		printf("Create file next\n");
		value_function();
	}

	sleep(1);

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

void *value_function () // create file
{
	char buff[] = "this is a test";
	char string[] = "test.test";

	int a = 0;
	int fd;

	while (a < 1) // loop
	{
		if ((fd = open(string, O_CREAT| O_WRONLY)) == -1)
		{
			printf("Opening failed\n");
			exit(0);
		}

		else
		{
			printf("file opening successful\n");
			printf("file descriptor: %d\n", fd);
			if (write(fd, buff, strlen(buff)) == -1)
			{
				printf("Error while writing to file\n%s\n", strerror(errno));
				exit(0);
			}

			else
			{
				printf("wrote %ld bytes to the file:\n", strlen(buff));
			}
		}
		close(fd);
		a++;
	}
}

int error_function ()
{
	char *path = "temp";
	int error_value;

	if (!access(path, F_OK) > 0)
	{
		bool found_f = 00000001;

		printf("File found\n");
		error_value = 1;
	}
	
	else if (access(path, F_OK) != 0)
	{
		bool found_f = 00000000;

		if (!found_f)
		{
			printf("\nFile not found!\n");
			error_value = -1;
		}

		printf("%s\n", strerror(errno));
	}

	return error_value;
}
