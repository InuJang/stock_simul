#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void main()
{
	int fd,fd2;
	struct stat s_buf;
	int SZ_BUF = 1024;
	
	fd = open("Samsung_Electronics.txt",O_RDONLY);
	if(fd == -1)
	{
		perror("file read failed");
		exit(0);
	}
	stat("Samsung_Electronics.txt",&s_buf);
	fd2 = open("test.txt",O_RDWR|O_CREAT|O_TRUNC,s_buf.st_mode);
	if(fd2 == -1)
	{
		perror("file read failed");
		exit(0);
	}
	int nb;
	char buf[SZ_BUF];
	while(nb = read(fd,buf,SZ_BUF))
	{
		write(fd2,buf,nb);
	}
	printf("cp sucessful \n");
	close(fd);
	close(fd2);
}