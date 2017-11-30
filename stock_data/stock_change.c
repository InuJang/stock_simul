#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void itoa(int val, char * buf)
{
	char *p = buf;
	while(val<=10)
	{
		*p++ = (val%10)+'0';
		val/=10;
	}
	*p = '\0';

	return buf;

}
void main()
{
	int fd,fd2;
	int fd3,fd4;
	struct stat s_buf;
	int SZ_BUF = 1024;
	char textbuf[4096];
	char stockP[4096];
	int stock_price[30000] = {0,};
	float stock_change = 0;
	char tmp[100] = {0,};
	char *line;
	char ch;
	int cnt = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	fd3 = fopen ("Samsung_final.txt","w");
	fd4 = fopen ("Samsung_test.txt","r+");
	line = fgets(textbuf,sizeof(textbuf),fd4);
	while((ch = fgetc(fd4))!=EOF)
	{
		
		if(ch == '\n')
		{
		
			stock_price[cnt3] = atoi(stockP);
			if(cnt3 != 0)
			{
				//printf("%f\n",(float)stock_price[0]/(float)stock_price[cnt3]*100);
				stock_change=((float)stock_price[0]/(float)stock_price[cnt3])*100;
				//printf("%f\n",stock_change);
				
				sprintf(tmp,"%d",(int)stock_change);
				//printf("%s",tmp);
				fprintf(fd3,"%s%%",tmp);
				fprintf(fd3,"   --%d week change rate",cnt3);
				fprintf(fd3,"\n");
				
			}
			cnt3++;
			cnt2=0;
			cnt = 0;
		}
		if(ch=='.')
		{
			cnt++;
		}
		if(cnt == 0)
		{
			stockP[cnt2] = ch;
			cnt2++;
		}

	}
	close(fd3);
	close(fd4);
}
