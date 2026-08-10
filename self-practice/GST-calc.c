#include <stdio.h>

int main () {
  

  float item1 = 0.0f;
  float item2 = 0.0f;
  float item3 = 0.0f;
 

  printf("Enter price of Item 1: ");
  scanf("%f", &item1);

  printf("Enter price of Item 2: ");
  scanf("%f", &item2);

  printf("Enter price of Item 3: ");
  scanf("%f", &item3);


  float subtotal = item1 + item2 + item3;
  printf("\nsubtotal:     %.2f\n", subtotal);
 
  float gst = subtotal * 0.18;
  printf("GST:          %.2f\n", gst);

  printf("---------------\n");
  float finaltotal = subtotal + gst;
  printf("Final Total: %.2f\n", finaltotal);

  return 0;
}
