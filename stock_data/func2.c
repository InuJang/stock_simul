#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void change(char *stock_name)
{
	int fd3,fd4;
	int SZ_BUF = 1024;
	char textbuf[4096];
	char *line;
	char ch;
	char txt[5] ={'1','.','t','x','t'} ;
	char stock_change[20]={0,};
	int cnt = 0;
	
	fd3 = fopen (stock_name,"r+");
	while(1)
	{
		ch = *(stock_name+cnt);
		if(ch == '.')
		{
			break;
		}
		*(stock_change+cnt)= ch;
		cnt++;
	}
	strcat(stock_change,txt);
	fd4 = fopen (stock_change,"w");
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
	write_parsing(stock_change);
}



