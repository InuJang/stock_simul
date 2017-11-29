#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void main()
{
	int fd,fd2;
	int fd3,fd4;
	struct stat s_buf;
	int SZ_BUF = 1024;
	char textbuf[4096];
	char *line;
	char ch;
	int cnt = 0;
	
	fd3 = fopen ("Samsung_Electronics.txt","r+");
	fd4 = fopen ("Samsung.txt","w");
	line = fgets(textbuf,sizeof(textbuf),fd3);
	while((ch = fgetc(fd3))!=EOF)
	{
		if(ch == '\n')
		{
			cnt = 0;
		}
		if(ch == ',')
		{
			cnt++;
		}
		if(cnt == 0)
		{
			fprintf(fd4,"%c",ch);
		}
		if(cnt == 4)
		{	
			fprintf(fd4,"%c",ch);
		}

	}
	close(fd3);
	close(fd4);
}
