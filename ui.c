#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MyMoney=10000000;
void DisplayMenu();

int main(){
   int step=-1;
   char quit[10]={'\0'};

   DisplayMenu();
 
   while(step  != 1 && step != 2 && step != 3){
     scanf("%d",&step);
   }
   if( step == 1 )
   {
     system("clear");
     
     while( step == 1  ){
       printf("hello world\n");
       scanf("%d",&step);
       if( step == 1 ) system("clear");
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
