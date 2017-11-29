#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void DisplayMenu();
void Step_1();
void Step_2();
void Step_3();

int main(){

   DisplayMenu();
   int step=-1;
   
   printf("\nPress the number\n");
   
   while(1)
   {
     scanf("%d",&step);
     switch(step)
     {
       case 1: Step_1();
               break;
       case 2: Step_2();
               break;
       case 3: Step_3();
               break;
     }
    step=-1;  
   } 



   return 0;
}
void Step_1()
{
   printf("11111");

}
void Step_2()
{ 
   printf("22222");

}
void Step_3()
{ 
   printf("33333");

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
