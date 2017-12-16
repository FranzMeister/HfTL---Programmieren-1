#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "uebung3.h"



int is_leap_year(int year)
{
  int ret=0;
  
  if(year%4 == 0){
    if(year%100 == 0){
      if(year%400 == 0){
        ret = 1;
      }
      else{
        ret = 0;
      }
    }
    else{
      ret = 1;
    }
  }
  else{
    ret = 0;
  }

  return ret;
}

int ggt(int a,int b)
{

  while(a>0 && b>0){
    if(a>b){
      a = a-b;
    }
    else{
      b = b-a;
    }
  }
  if(b==0){
    return a;
  }
  else{
    return b;
  }
}



int daytab [2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
  };

int day_of_year(int year,int month,int day)
{
  int leap=is_leap_year(year);
  
  if(month<1 || month >12){
    return -1;
  } 
  if(day<1 || day>daytab[leap][month]){
    return -1;
  }
  for(int i = 1; i<month; i++){
    day += daytab[leap][i];
  }
 
  return day;
}

