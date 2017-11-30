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
	char stockP[4096];
	char *line;
	char ch;
	int cnt = 0;
	int cnt2 = 0;
	fd3 = fopen ("Samsung_test.txt","w");
	fd4 = fopen ("Samsung.txt","r+");
	line = fgets(textbuf,sizeof(textbuf),fd4);
	while((ch = fgetc(fd4))!=EOF)
	{
		if(ch == '\n')
		{
			fprintf(fd3,"%s",stockP);
			fprintf(fd3,"\n");
			cnt2=0;
			cnt = 0;
		}
		if(ch == ',')
		{
			cnt++;
		}
		else if(cnt >= 1)
		{
			stockP[cnt2] = ch;
			cnt2++;
		}
	}
	close(fd3);
	close(fd4);
}
