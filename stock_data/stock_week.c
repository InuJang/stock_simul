#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void write(char *stock_name)
{
	int fd3,fd4,fd5,fd6;
	int SZ_BUF = 1024;
	char textbuf[4096];
	char stockP[4096];
	char tmp[100] = {0,};
	int stock_price[30000] = {0,};
	
	char ch;
	int cnt = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	float stock_change = 0;
	fd3 = fopen ("Samsung_day.txt","w");
	fd4 = fopen ("Samsung.txt","r+");
	fd5 = fopen ("Samsung_week.txt","w");
	fd6 = fopen ("Samsung_month.txt","w");
	while((ch = fgetc(fd4))!=EOF)
	{
		if(ch == '\n')
		{	
			stock_price[cnt3] = atoi(stockP);
			stock_change=(((float)stock_price[0]-(float)stock_price[cnt3])/(float)stock_price[0])*100;
			sprintf(tmp,"%d",(int)stock_change);
			printf("%s \n",tmp);
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

}
void change(char *stock_name)
{
	int fd3,fd4;
	int SZ_BUF = 1024;
	char textbuf[4096];
	char *line;
	char ch;
	int cnt = 0;
	
	fd3 = fopen (stock_name,"r+");
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
void main()
{
	
}
