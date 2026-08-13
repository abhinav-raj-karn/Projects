#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL));

 //  printf("%d\n", rand());   // random number 
 // printf("%d\n", RAND_MAX);   // maximum value
  
  int min = 1;
  int max = 6;

  int randomNum = (rand() % max) + min;

  printf("%d\n", randomNum);
  return 0;
}
