#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

//open(const char *pathname, int O_CREAT|O_WRONLY|O_TRUNC);
//open(const char *pathname, int O_RDONLY);

int main()
{
	int fd_in,fd_out;
	int nb;
	struct stat s_buf;
	int SZ_BUF = 1024;
	char buf[SZ_BUF];
	fd_in = open("Samsung_Electronics.txt",O_RDONLY);
	if(fd_in == -1)
	{
		perror("In file read failed\n");
		exit(0);
	}
	stat("Samsung_Electronics.txt",&s_buf);
	fd_out = open("test.txt",O_CREAT|O_WRONLY|O_TRUNC,s_buf.st_mode);
	if(fd_out == -1)
	{
		perror("OUT file read failed\n");
		exit(0);
	}
	while(nb = read(fd_in,buf,SZ_BUF));
	{
		write(fd_out,buf,nb);
	}
	printf("cp success\n");
	close(fd_in);
	close(fd_out);
	return 0;
}

