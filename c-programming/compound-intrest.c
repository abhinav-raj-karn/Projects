#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main () {
  // compound interest calculator
  
  double principal = 0.0;
  double rate = 0.0;
  int years = 0;
  int timescompounded = 0;
  double total = 0.0;

  printf("compound intrest calculator\n");

  printf("enter the principal (p): ");
  scanf("%lf", &principal);

  printf("enter the intrest rate %% (r): ");
  scanf("%lf", &rate);
  rate = rate / 100;

  printf("enter the number of years (t): ");
  scanf("%d", &years);

  printf("enter number of times compounded per year (n):  ");
  scanf("%d", &timescompounded);


  total = principal * pow(1 + rate / timescompounded, timescompounded * years);
  printf("After %d years, The total amount will be: $%.2lf\n", years, total);

  return 0;
}
