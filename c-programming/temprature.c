#include <stdio.h>

int main()
{
  // TEMPRATURE CONVERSION PROGRAM
  char choice = '\0';
  float fahrenheit = 0.0f;
  float celsius = 0.0f;

  printf("TEMPRATURE CONVERSION PROGRAM\n");
  printf("C. Celsius to Fahrenheit\n");
  printf("F. Fahrenheit to Celsius\n");
  printf("Is the temp in Celsius (C) or Fahrenheit (F):  ");
  scanf("%c", &choice);


  if (choice == 'C'){
    //C to F
    printf("Enter celsius:  ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32; // C to F
    printf("%.1f°C is %.1f°F", celsius, fahrenheit);
  }
  else if (choice == 'F'){
    printf("Enter fahrenheit:  ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5 / 9;  //F to C
    printf("%.1f°F is %.1f°C", fahrenheit, celsius);
  }
  else{
    printf("Invalid choice! please select C or F\n");
  }
  return 0;
}
