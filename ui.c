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


long int Mymoney=0;
long int Cornum=-1;
int step=-1;

int main(void){
   /*
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
   */
   Samsung_day();

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
   ssize_t ret;
   char buf[1024]={'\0'};
   fd=open("/home/jungjunkim/embeddedsw_project/stock_simul/stock_data/list.txt", O_RDONLY);
   if(fd==-1) perror("open");
   while(ret != NULL){
      ret=read(fd,buf,50);
   }
   printf("**********************************************************\n");
   printf("***************THIS IS LIST OF CORPORATION****************\n");
   printf("**********************************************************\n");
   printf("%s",buf);
   printf("**********************************************************\n");
   printf("**********************************************************\n");
   printf("**********************************************************\n");
}
void Samsung_day()
{
  char s_buf[1024]={'\0'};
  int s_fd;
  char *result;
  ssize_t s_ret;
  s_fd=open("/home/jungjunkim/embeddedsw_project/stock_simul/stock_data/Samsung_day.txt",O_RDONLY);
  if(s_fd==-1) perror("open");
  while(s_ret != NULL){
      s_ret=read(s_fd,s_buf,1);
      result=strtok(s_buf,"p");
      write(1,s_buf,1);
  }
}
