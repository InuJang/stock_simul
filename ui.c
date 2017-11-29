#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void DisplayMenu();
void Step_1();
void Step_2();
void Step_3();
void Invest(int money);

int Mymoney=0;
int Cornum=-1;
int step=-1;
char Corporation[15][2]={SAMSUNG,HYUNDAI};
int main(){

   DisplayMenu();
 
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
       case 3: Invest(Mymoney);
               break;
     }
    step=-1;
   }



   return 0;
}
void Step_1()
{
   system("clear");
   printf("This is Stock corporation\n");
}
void Step_2()
{
   system("clear");
   printf("22222\n");
}
void Step_3()
{
  system("clear");
  printf("33333\n");
}
void Invest(int money)
{
  printf("1.Press the Initial investment\n");
  scanf("%d",&Mymoney);
  printf("2.Press the Corporation Number\n");
  scanf("%d",&Cornum);
  printf("Investment fund is %d, Corporation is %s",Mymoney,Corporation[15][Cornum]);
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
}
