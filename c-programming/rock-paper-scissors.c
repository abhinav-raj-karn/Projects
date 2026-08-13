#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getComputerChoice();
int getUserChoice();
void checkWinner(int userChoice, int computerChoice);

int main() {
  
  srand(time(NULL));

  printf("*** ROCK PAPER SCISSORS ***\n");

  int userChoice = getUserChoice();
  int computerChoice = getComputerChoice();

  switch(computerChoice){
    case 1:
      printf("computer chose ROCK\n");
      break;
    case 2:
      printf("computer chose PAPER\n");
      break;
    case 3:
      printf("computer chose SCISSORS\n");
      break;
  }
  switch(userChoice){
    case 1:
      printf("you chose ROCK\n");
      break;
    case 2:
      printf("you chose PAPER\n");
      break;
    case 3:
      printf("you chose SCISSORS\n");
      break;
  }



  return 0;
}


int getComputerChoice(){

  return (rand() % 3) + 1;
}

int getUserChoice(){

  int choice = 0;

  do{
    printf("Choose an option\n");
    printf("1. ROCK\n");
    printf("2. PAPER\n");
    printf("3. SCISSORS\n");
    printf("Enter your choice:  ");
    scanf("%d", &choice);
  }while(choice < 1 || choice > 3);

  return choice;
}


void checkWinner(int userChoice, int computerChoice){
 return;
}


