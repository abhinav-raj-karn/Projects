// while loop = Continue some code WHILE the condition remains true 
//              Condition must be true for us to enter the loop

#include <stdio.h>

int main() {
   

  int number = 0;

  while(number <= 0){
    printf("Enter a number greater than 0:  ");
    scanf("%d", &number);
  }
  return 0;
}
