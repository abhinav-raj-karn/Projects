#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL));

 //  printf("%d\n", rand());   // random number 
 // printf("%d\n", RAND_MAX);   // maximum value
  
  int min = 50;
  int max = 100;

  int randomNum = (rand() % (max - min + 1)) + min;

  printf("%d\n", randomNum);
  return 0;
}
