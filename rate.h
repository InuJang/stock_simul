#ifndef
#include RATE_H
#endif

#include <stdio.h>
#include <stlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


long float Samsung(long float money,long float rate, long float result)
{
   result= (1-rate)*money; //this is current my invest ment
   printf("This is Samsung Profit of investment %lf",result);
   return result;
}
long float LGdisp(long float money,long float rate, long float result)
{
   result = (1-rate)*money;
   printf("This is LGdisp Profit of investment %lf",result);
   return result;
}
void Display_my_Profit()
{ 
   Samsung(money,rate,result);
   LGdisp(money,rate,result);
}
