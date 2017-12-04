#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void main()
{
	int fd,fd2;
	int fd3,fd4,fd5,fd6;
	struct stat s_buf;
	int SZ_BUF = 1024;
	char textbuf[4096];
	char stockP[4096];
	char *line;
	char ch;
	int cnt = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	fd3 = fopen ("Samsung_day.txt","w");
	fd4 = fopen ("Samsung.txt","r+");
	fd5 = fopen ("Samsung_week.txt","w");
	fd6 = fopen ("Samsung_month.txt","w");
	while((ch = fgetc(fd4))!=EOF)
	{
		if(ch == '\n')
		{
			fprintf(fd3,"%s\n",stockP);

			if(cnt3%7 == 0)
			{
				fprintf(fd5,"%s\n",stockP);
			}
			if(cnt3%32 == 0 && ch=='\n')
			{
				fprintf(fd6,"%s\n",stockP);
			}
			cnt2=0;
			cnt = 0;
			cnt3++;
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
