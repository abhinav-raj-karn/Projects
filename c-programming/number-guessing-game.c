// NUMBER GUESSING GAME

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
  
  srand(time(NULL));
  int guess = 0;
  int tries = 0;
  int min = 1;
  int max = 100;
  int answer = (rand() % (max - min + 1)) + min;

  printf("*** NUMBER GUESSING GAME ***\n");

  do {
    printf("Guess a number between %d - %d: ", min, max);
    scanf("%d", &guess);
    tries++;
    if(guess < answer){
      printf("Too low\n");
    }
    else if(guess > answer){
      printf("too high\n");
    }
    else {
      printf("Correct\n");
    }
  }
  while (guess != answer);
  printf("the answer is %d\n", answer);
  printf("it took you %d tries", tries);
  return 0;
}
