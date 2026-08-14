/*

1. Simple billing system (best next project)
Menu:
Add item price
View current bill
Apply discount
Checkout
Exit

*/


#include <stdio.h>



int main() {
// Add item price
  float item1 = 0.0f;
  float item2 = 0.0f;
  float item3 = 0.0f;
  float total = 0.0f;

  printf("Enter the price of items\n");
  printf("ITEM 1: ");
  scanf("%f", &item1);

  printf("ITEM 2: ");
  scanf("%f", &item2);

  printf("ITEM 3: ");
  scanf("%f", &item3);

  total = item1 + item2 + item3;

  printf("%f", total);

  return 0;
}
