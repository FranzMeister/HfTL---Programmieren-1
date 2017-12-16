#include "uebung2.h"
#include <math.h>
#include <stdio.h>

int main(){
  double result;
  int test_array[] = {1, 7, 5, 23, 42, -13, 28};
  int test_array_length = sizeof(test_array)/sizeof(int);

  result = min(test_array, test_array_length);
  printf("min: %0.0f\n", result);
  
  result = max(test_array, test_array_length);
  printf("max: %0.0f\n", result);
  
  result = min_index(test_array, test_array_length);
  printf("min_index: %0.0f\n", result);
  
  result = max_index(test_array, test_array_length);
  printf("max_index: %0.0f\n", result);
  
  result = sum(test_array, test_array_length);
  printf("sum: %0.0f\n", result);
  
  result = average(test_array, test_array_length);
  printf("average: %0.0f\n", result);
  
  result = stddev(test_array, test_array_length);
  printf("stddev: %0.0f\n", result);
}

double min(int *array,int length)
{
  double ret;

  if(length <= 0)
    return NAN;


  ret = array[0];

  for(int i = 0; i < length; i++){
    if(array[i] < ret)
      ret = array[i];
  }


  return ret;
}

double max(int *array,int length)
{
  double ret;
  if(length <= 0)
    return NAN;
  ret = array[0];
  for(int i = 0; i < length; i++){
    if(array[i] > ret)
      ret = array[i];
  }
  return ret;
}


double min_index(int *array,int length)
{
  double ret;
  int min;
  if(length <= 0)
    return NAN;
  min = array[0];
  ret = 0;
  for(int i = 0; i < length; i++){
    if(array[i] < min)
      ret = i;
  }
  return ret;
}

double max_index(int *array,int length)
{
  double ret;
  if(length <= 0)
    return NAN;

  double max_nr = max(array, length);
  for(int i = 0; i < length; i++){
    if(array[i] == max_nr)
      return i;
  }
  return ret;
}

double sum(int *array,int length)
{
  double ret;
  double zahl = 0;
  if(length <= 0)
  {  
    return NAN;
  }
  for(int i = 0; i < length; i++){
    zahl += array[i];
  }
  return zahl;
}

double average(int *array,int length)
{
  double ret = 0;
  if(length <= 0)
    return NAN;
  for(int i = 0; i < length; i++){
    ret += array[i];
  }
  ret /= length;
  return ret;
}

double stddev(int *array,int length)
{
  double ret = 0;
  if(length <= 0)
    return NAN;

  double avg = average(array, length);

  int i = 0;
  double qsum = 0;

  for(i = 0; i < length; i++){
    qsum += pow((array[i]-avg), 2);
  }
  double qs = pow((length - 1), -1)*qsum;
  double s = sqrt(qs);

  ret = s;

  return ret;
}