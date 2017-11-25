#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int MyMoney=10000000;

void DisplayMenu();

int main(){
   //int step=-1;
   
   DisplayMenu();
   char step[50]={'\0'};
   pid_t pid;
   pid=fork();
   if( pid < 0 ) perror("pid");
   else if( pid == 0 ){
      printf("quit\n");
      gets(step);
   } 

   while(1){

    //while(step  != 1 && step != 2 && step != 3){
    //  scanf("%d",&step);
    //}

    if( step == 1 )
    {
      system("clear");
      printf("1\n");
    }
    else if( step == 2 )
    {
      system("clear");
      printf("2\n");
    }
    else if( step == 3 )
    {
     system("clear");
     printf("3\n");
    }


  }

   return 0;
}

void DisplayMenu(){
   printf("**********************************************************\n");
   printf("******This is Stock Simulation of Embeddedsw Project******\n");
   printf("**********************************************************\n");
   printf("1. Comfirm the corporation\n");
   printf("2. Check the price-earnings ratio of corporation\n");
   printf("3. Invest!!! \n");\
   printf("**********************************************************\n");
   printf("**********************************************************\n");
   printf("**********************************************************\n");
}
