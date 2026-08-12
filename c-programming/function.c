  // function = A reusable section of code that can be invoked "called"
  //            Arguments can be sent to a function so that it can use them

#include <stdio.h>
#include <string.h>



void happyBirthday(char name[50], int age){

   printf("\nHappy birthday to you");
   printf("\nHappy birthday to you");
   printf("\nHappy birthday dear %s!", name);
   printf("\nYou are %d years old!\n", age);
}

int main() {

    char name[50] = "";
    int age = 0;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    printf("Enter your age: ");
    scanf("%d", &age);

    happyBirthday(name, age);
  return 0;
}
