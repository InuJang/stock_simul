#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
int step=-1;

int main(void){

   DisplayMenu();

   printf("\nPress the number\n");

   while(1)
   {
     if(step!=0) scanf("%d",&step);
     switch(step)
     {
       case 0: DisplayMenu();
               break;
       case 1: CorpList();;
               break;
       case 2: Step_2();
               break;
       case 3: Invest();
               break;
     }
   }

   //Samsung_day();

return 0;

}

void Step_2()
{
   system("clear");
   printf("22222\n");
   step=-1;
}

void Invest()
{
  printf("1.Press the Initial investment\n");
  scanf("%ld",&Mymoney);
  printf("2.Press the Corporation Number\n");
  //scanf("%ld",&Cornum);
  //printf("######## Investment fund is %ld, Corporation is %s ##########\n\n", Mymoney, &Corp[Cornum][11]);
}

void DisplayMenu(){
   printf("**********************************************************\n");
   printf("******This is Stock Simulation of Embeddedsw Project******\n");
   printf("**********************************************************\n");
   printf("1. Comfirm the corporation\n");
   printf("2. Check the price-earnings ratio of corporation\n");
   printf("3. Invest!!! \n");
   printf("**********************************************************\n");
   printf("**********************************************************\n");
   printf("**********************************************************\n");
   step=-1;
}
void CorpList()
{
   system("clear");
   int fd;
   char data;
   int i=0;
   int j=0;
   fd=fopen("./stock_data/list.txt", "r+");
   if(fd==-1) perror("open");
   while((data = fgetc(fd))!=EOF){
      if(data == '\n')
      {
         j=0;
         i++;
         continue;
      }
      Corp[i][j]=data;
      j++;
      printf("%s",Corp[i][j]);
   }
   printf("**********************************************************\n");
   printf("***************THIS IS LIST OF CORPORATION****************\n");
   printf("**********************************************************\n");
 //   printf("%s",buf);
   printf("**********************************************************\n");
   printf("**********************************************************\n");
   printf("**********************************************************\n");
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
  s_fd=fopen("./stock_data/Samsung_day.txt","r+");
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
