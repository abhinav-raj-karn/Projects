#include <stdio.h>
#include <stdbool.h>

int main () {
  float price = 10.00;
  bool isStudent = false;  // 10% discount
  bool isSenior = true; //

  if (isStudent){
    printf("You get a student discount of 10%\n");
    price *= 0.9;
  }
  printf("The price of ticket will be $%.2f\n", price);
}
