#include <stdio.h>
#include <stdbool.h>

int main () {
  // logicl operator = Used to combine or modify boolean expression.

  // && = AND
  // || = OR
  // ! = NOT

/* 
   
    // && = AND

  int temp = 100000;

  if (temp > 0 && temp < 30){
    printf("The temperature is GOOD\n");
  }
  else{
    printf("The temperature is BAD\n");
  }

  // || = OR

  if (temp <= 0 || temp >= 30){
    printf("The temperature is BAD\n");
  }
  else{
    printf("The temperature is GOOD\n");
  }

 */

  bool isSunny = true;

  if (!isSunny){
    printf("it is CLOUDY outside\n");
  }
  else {
    printf("It is SUNNY outside\n");
  }
  return 0;
}
