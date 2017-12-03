#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void DisplayMenu();
void Step_1();
void Step_2();
void Step_3();
void Invest();

long int Mymoney=0;
long int Cornum=-1;
int step=-1;

char Corp[10][11]={
  "SAMSUNG",
  "SK TELECOM",
  "HYUNDAI",
  "DAEWOO",
  "APPLE",
  "GOOGLE",
  "AMAZON",
  "IBM",
  "LOTTE",
  "FACEBOOK"
};

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
       case 1: Step_1();
               break;
       case 2: Step_2();
               break;
       case 3: Invest();
               break;
     }
   }
return 0;

}
void Step_1()
{
   system("clear");
   for( int i=0; i<10; i++)
   {
     printf("Corporation Name : %s\n",Corp[i]);
     printf("Corporation # : %d\n",i);
     printf("\n");
   }
   step=0;
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
  scanf("%ld",&Cornum);
  printf("######## Investment fund is %ld, Corporation is %s ##########\n\n", Mymoney, &Corp[Cornum-1][10]);
  step=0;
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
