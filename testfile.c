#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MyMoney=10000000;
void DisplayMenu();
int main(){
   int select=-1;
   DisplayMenu();
   while(select!=-1){
     scanf("%d",&select);
   }
   if( select == 1 )
   {
     while( select!=0){ 
       system("clear");
       printf("hello world\n");
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
