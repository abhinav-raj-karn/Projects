/*

1. Simple billing system (best next project)
Menu:
Add item price
View current bill
Apply discount
Checkout
Exit


Start
  |
Initialize variables
  |
do
  |
Show menu
  |
Read choice
  |
switch(choice)
  |
  +-- Add item
  |
  +-- View bill
  |
  +-- Apply discount
  |
  +-- Checkout
  |
  +-- Exit
  |
while(choice != 5)

*/

#include <stdio.h>



int main() {
  float item1 = 0.0f;
  float item2 = 0.0f;
  float item3 = 0.0f;
  float total = 0.0f;
  float discount_percent = 0.0f;
  int itemCount = 0;
  int discountApplied = 0;

  printf("Enter the price of items\n");
  printf("ITEM 1: $");
  scanf("%f", &item1);

  printf("ITEM 2: $");
  scanf("%f", &item2);

  printf("ITEM 3: $");
  scanf("%f", &item3);

  total = item1 + item2 + item3;

  printf("Your total is $%.2f\n", total);

  printf("Enter discount percentage: ");
  scanf("%f", &discount_percent);

  total = total * discount_percent / 100;
  printf("total payble amount: $%.2f\n", total);

  return 0;
}
