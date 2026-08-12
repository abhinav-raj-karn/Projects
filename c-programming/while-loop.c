// while loop = Continue some code WHILE the condition remains true 
//              Condition must be true for us to enter the loop

//              WHILE LOOP ARE GOOD FOR USER INPUTS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {

// WITH INT


  int number = 0;

  do{
    printf("Enter a number greater than 0:  ");
    scanf("%d", &number);
  }while(number <= 0);


// WITH STRING


  char name[50] = "";

  printf("Enter your name: ");
  fgets(name, sizeof(name), stdin);
  name[strlen(name) - 1] = '\0';

  while (strlen(name) == 0){

    printf("Name cannot be enpty! Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';
  }
  printf("Hello, %s\n", name);


// WITH BOOLEIN

  bool isRunning = true;
  char responce = '\0';

  while(isRunning){

    printf("You are playing a game\n");
    printf("Would you like to continue? (Y = yes, N = no): ");
    scanf(" %c", &responce);

    if(responce != 'Y' && responce != 'y'){
      isRunning = false;
    }
  }
  printf("You exit the game\n");



  return 0;
}
