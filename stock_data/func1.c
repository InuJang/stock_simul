#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void write_parsing(char *stock_name)
{
	int fd3,fd4,fd5,fd6;
	int SZ_BUF = 1024;
	char textbuf[4096];
	char stockP[4096];
	char tmp[100] = {0,};
	int stock_price[30000] = {0,};
	char day[10] ={"_day.txt"};
	char week[10] = {"_week.txt"};
	char month[10] = {"_month.txt"};
	char ch;
	int cnt = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	char *line;
	float stock_change = 0;
	char d[20] = {0,};
	char w[20] = {0,};
	char m[20] = {0,};
	fd4 = fopen (stock_name,"r+");
	
	while(1)
	{
		ch = *(stock_name+cnt);
		if(ch == '.')
		{
			break;
		}
		*(d+cnt)= ch;
		*(w+cnt)= ch;
		*(m+cnt)= ch;
		cnt++;
	}
	strcat(d,day);
	strcat(w,week);
	strcat(m,month);
	fd3 = fopen (d,"w");
	fd5 = fopen (w,"w");
	fd6 = fopen (m,"w");
	cnt = 0;
	line = fgets(textbuf,sizeof(textbuf),fd4);
	while((ch = fgetc(fd4))!=EOF)
	{
		if(ch == '\n')
		{	
			stock_price[cnt3] = atoi(stockP);
			stock_change=(((float)stock_price[0]-(float)stock_price[cnt3])/(float)stock_price[0])*100;
			sprintf(tmp,"%d",(int)stock_change);
			fprintf(fd3,"%s",stockP);
			fprintf(fd3,",%s%%\n",tmp);
			

			if(cnt3%7 == 0)
			{
				fprintf(fd5,"%s",stockP);
				fprintf(fd5,",%s%%\n",tmp);
				
			}
			if(cnt3%32 == 0 && ch=='\n')
			{
				fprintf(fd6,"%s",stockP);
				fprintf(fd6,",%s%%\n",tmp);
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
	close(fd5);
	close(fd6);
	return;
}

