#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
void DisplayMenu();
void Step_1();
void Step_2();
void Step_3();
void Invest();
void CorpList();
void Samsung_day();

char Corp[5][10];
long int Mymoney=0;
long int Cornum=-1;
char step=0;
int fd;
int main(void){
   printf("**********************************************************\n");
   printf("******This is Stock Simulation of Embeddedsw Project******\n");
   printf("**********************************************************\n");

   printf("\nPress the number\n");
   DisplayMenu();
   while(step!='q')
   {
     scanf("%c",&step);
     if(step=='1')
     {
        CorpList();
     }
     if(step=='2')
     {
        Step_2();
     }
     if(step=='3')
     {
        Invest();
     }
   }

   //Samsung_day();

return 0;

}

void Step_2()
 {
   char stock_name[100][20];
   char textbuf[1000];
   char txt[10] = {"1_day.txt"};
   char txt2[20] = {"1_week.txt"};
   char txt3[20] = {"1_month.txt"};
   char tmp[100];
   char tmp2[100];
   char route[100] = {"./stock_data/"};
   char tmp_d[100][100] ={0,};
   char tmp_w[100][100] ={0,};
   char tmp_m[100][100] ={0,};
   char ch;
   int cnt = 0;
   int cnt2 = 0;
   int cnt3 = 0;
   int fp2;
   int flag=0;
   char *line;
   int num = 0;
   system("clear");
   fd=fopen("./stock_data/list.txt", "r");
   printf("**********************************************************\n");
   printf("***** corporation, current price, chang rate per day *****\n");
   printf("**********************************************************\n");
   while(fgets(textbuf,sizeof(textbuf),fd)!=NULL)
   {
        strcpy(tmp_d[cnt2],route);
        strcpy(tmp_w[cnt2],route);
        strcpy(tmp_m[cnt2],route);
	memset(tmp2,0,sizeof(tmp2));
	memset(tmp,0,sizeof(tmp));
	cnt = 0;
	while(1)
	{
		if(*(textbuf+cnt)=='\n')
		{
			*(textbuf+cnt) = 0;
			break;
		}
		cnt++;
	}
	printf("%d. ",cnt2+1);
	printf("%s,",textbuf);
	strcat(tmp_d[cnt2],textbuf);
	strcat(tmp_d[cnt2],txt);
	strcat(tmp_w[cnt2],textbuf);
	strcat(tmp_w[cnt2],txt2);
	strcat(tmp_m[cnt2],textbuf);
	strcat(tmp_m[cnt2],txt3);
	//printf("%s  ,       \n",tmp_m[cnt2]);
	strcpy(stock_name[cnt2],tmp_d[cnt2]);
	//printf("%s",tmp_d[cnt2]);


	fp2 = fopen(tmp_d[cnt2],"r");
	cnt2++;
	while(1)
	{
		ch = fgetc(fp2);
		if(ch ==',')
		{
			flag++;
			cnt3 = 0;
		}
		if(flag==0)
		{
			tmp[cnt3] = ch;
			cnt3 ++;
		}
		if(flag==2)
		{
			if(ch=='\n')
			{
				flag++;
			}
			tmp2[cnt3] = ch;
			cnt3++;
		}
		if(flag>=3)
		{
			fclose(fp2);
			break;
		}
	}
	printf("%s",tmp);
	printf("%s\n",tmp2);
	cnt3=0;
	flag=0;
   }
   close(fd);
   printf("if want more stock data, choose Coperation number\n");
   printf("if return to previous menu, press q\n");
   
   while(step!='q')
   {
	scanf("%c",&step);
	if(step >'0'&&step<'9')
	{
		
   		system("clear");
		printf("choose number day /week /month \n");
		printf("if return to main menu, press q\n");
		printf("1. day ratio\n");
		printf("2. week ratio\n");
		printf("3. month ratio\n");		
		scanf("%d",&num);
		if(num==1)
		{
			fp2 = fopen(tmp_d[step-'1'],"r");
			while((ch = fgetc(fp2))!=EOF)
			{
				printf("%c",ch);
			}
		}
		else if(num==2)
		{
			fp2 = fopen(tmp_w[step-'1'],"r");
			while((ch = fgetc(fp2))!=EOF)
			{
				printf("%c",ch);
			}
		}
		else if(num==3)
		{
			fp2 = fopen(tmp_m[step-'1'],"r");
			while((ch = fgetc(fp2))!=EOF)
			{
				printf("%c",ch);
			}
		}
		close(fp2);
		break;
	}
	else
	{
		printf("you select wrong number \n");
	}
   }
   printf("if return to main menu, press q\n");
   while(step!='q')
   {
	scanf("%c",&step);
   }
   step=-1;
   system("clear");
   DisplayMenu();
}

void Invest()
{
   char stock_name[100][20];
   char textbuf[1000];
   char txt[10] = {"1_day.txt"};
   char txt2[10] = {".txt"};
   char tmp[100];
   char tmp2[100];
   char route[100] = {"./stock_data/"};
   char route2[100] = {"./my_stock/my_"};
   char tmp_d[100][100] ={0,};
   char my_stock[100]={0,};
   char price[50]={0,};
   int price2 = 0;
   int price3 = 0;
   int cor_num =0;
   char ch;
   int cnt = 0;
   int cnt2 = 0;
   int cnt3 = 0;
   int sel = 0;
   int fd;
   int fp3;
   int fp2;
   int flag=0;
   char *line;
   int num = 0;
   system("clear");
   fd=fopen("./stock_data/list.txt", "r");
  while(fgets(textbuf,sizeof(textbuf),fd)!=NULL)
   {
        strcpy(tmp_d[cnt2],route);
	memset(tmp2,0,sizeof(tmp2));
	memset(tmp,0,sizeof(tmp));
	cnt = 0;
	while(1)
	{
		if(*(textbuf+cnt)=='\n')
		{
			*(textbuf+cnt) = 0;
			break;
		}
		cnt++;
	}
	strcpy(stock_name[cnt2],textbuf);
	printf("%d. ",cnt2+1);
	printf("%s,",textbuf);
	strcat(tmp_d[cnt2],textbuf);
	strcat(tmp_d[cnt2],txt);


	fp2 = fopen(tmp_d[cnt2],"r");
	cnt2++;
	while(1)
	{
		ch = fgetc(fp2);
		if(ch ==',')
		{
			flag++;
			cnt3 = 0;
		}
		if(flag==0)
		{
			tmp[cnt3] = ch;
			cnt3 ++;
		}
		if(flag==2)
		{
			if(ch=='\n')
			{
				flag++;
			}
			tmp2[cnt3] = ch;
			cnt3++;
		}
		if(flag>=3)
		{
			fclose(fp2);
			break;
		}
	}
	printf("%s",tmp);
	printf("%s\n",tmp2);
	cnt3=0;
	flag=0;
   }
   printf("1.Select the Corporation Number\n");
   scanf("%d",&cor_num);
   strcat(my_stock,route2);
   strcat(my_stock,stock_name[cor_num-1]);
   strcat(my_stock,txt2);
   printf("%s \n",my_stock);
   if(access(my_stock,0)==0)
   {
      printf("file is already exist\n");
      printf("automatically remake file\n");
      fp3 = fopen(my_stock,"w");
   }
   else
   {
      fp3 = fopen(my_stock,"w");
      printf("%s\n",my_stock);
      printf("open complete\n");
   }
   printf("2. How many will you buy stock?\n");
   fp2 = fopen(tmp_d[cor_num-1],"r");
   flag = 0;
   cnt3 = 0;
   while(1)
   {
	ch = fgetc(fp2);
	if(ch ==',')
	{
      	        printf("%s for one, just write number\n",price);
		break;
	}
	price[cnt3] = ch;
	cnt3++;
   }

   scanf("%d",&price2);
   price3 = atoi(price);
   printf("you bought %d, is %d $ \n", price2,price2*price3);
   scanf("%c",&step);
   step = -1;
   fprintf(fp3,"%d",price3*price2);
   DisplayMenu();
}

void DisplayMenu(){

   printf("1. Comfirm the corporation\n");
   printf("2. Check the price-earnings ratio of corporations\n");
   printf("3. Invest!!! \n");
   printf("**********************************************************\n");
   printf("**********************************************************\n");
   printf("**********************************************************\n");
   step=-1;
 
   printf("if quit this program, press q \n");
}
void CorpList()
{

   char data;
   char textbuf[1024];
   fd=fopen("./stock_data/list.txt", "r");
   system("clear");
   step=0;
   printf("**********************************************************\n");
   printf("***************THIS IS LIST OF CORPORATION****************\n");
   printf("**********************************************************\n");

   while(fgets(textbuf,sizeof(textbuf),fd)!=NULL)
   {
      printf("%s",textbuf);
   }
   printf("**********************************************************\n");
   printf("**********************************************************\n");
   printf("**********************************************************\n");
   printf("if return to previous menu, press q\n");
   while(step!='q')
   {
	scanf("%c",&step);
   }
   fd = fclose(fd);
   step = 0;
   system("clear");
   DisplayMenu();
}
void Samsung_day()
{
  char s_buf[1024]={'\0'};
  int s_fd;
  ssize_t s_ret;
  char ch;
  char stockP[365][100];
  char stockR[365][100];
  int cnt = 0;
  int cnt2 = 0;
  int cnt3 = 0;
  int cnt4 = 0;
  s_fd=fopen("./stock_data/Samsung_Electronic1_day.txt","r+");
      while((ch = fgetc(s_fd))!=EOF)
      {
	 if(ch == '\n')
         {
    	    printf("%s,%s%%\n",stockP[cnt4],stockR[cnt4]);
            cnt = 0;
            cnt2 = 0;
            cnt3 = 0;
	    cnt4++;
	    continue;
         }
	 if(ch == ',')
         {
            cnt++;
	    continue;
         }
	 if(ch== '%')
	 {
	    continue;
	 }
	 if(cnt == 0)
	 {
	    stockP[cnt4][cnt2] = ch;
	    cnt2++;
	 }
	 if(cnt == 1)
	 {
	    stockR[cnt4][cnt3] = ch;
	    cnt3++;
	 }
      }
      fclose(s_fd);
}
