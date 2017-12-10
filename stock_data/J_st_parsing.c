#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void main()
{
	int fd3,fd4;
	int SZ_BUF = 1024;
	char textbuf[4096];
	char *line;
	char ch;
	char txt[4] ={'.','t','x','t'} ;
	char stock_change[20];
	int cnt = 0;
	fd3= fopen("list.txt","r");
	while(fgets(textbuf,sizeof(textbuf),fd3)!=NULL)
	{
		while(1)
		{
			if(*(textbuf+cnt)=='\n')
			{
				*(textbuf+cnt) = 0;
				break;
			}
			cnt++;
		}
		strcat(textbuf,txt);
		change(textbuf);
		cnt = 0;
	}
	close(fd3);


}
