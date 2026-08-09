#include <stdio.h>
#include <stdbool.h>


int main(){
  // this is a comment
  // test comment lala
  printf("test hello\n");

  // variable = A resuable container for value.
  //            Behaves as if it ere the value it contains.
  // int contains integers
  // to use int in places we can use %d

  int age = 18;
  int year = 2026;
  int quantity = 1;

  printf("You are %d years old\n", age);
  printf("The year is %d.\n", year);
  printf("You have orderd %d orders\n", quantity);

  //float can contain decimal values 
  // to use float in places we can use %f

  float gpa = 2.5;
  float price = 19.99;
  float temp = 23.3;
  printf("Your gpa is %.1f\n", gpa);
  printf("The price is $%.2f\n", price);
  printf("The temperature is %.1f℃C\n", temp);

  // double holds a larger data value
  // it is a long float hence we can use it with %lf

  double pi = 3.14159265358979;
  double e = 2.718281828459045;

  printf("The value of pi is %.15lf\n", pi);
  printf("The calue of e is %.15lf\n", e);

  //char can hold a single characters
  // to use it we can write %c


  char grade = 'C';
  char symbol = '!';
  char currency ='$';

  printf("Your grade is %c.\n", grade);
  printf("Your favorite symbol is %c\n", symbol);
  printf("USA uses %c as its currency\n", currency);

  // in C we dont have strins so we use char variable_name[] = "somthing"; as a string 
  // place holder value of strings are %s 

  char name[] = "Calm";
  char food[] = "Momos";
  char email[] = "example@email.com";

  printf("Hello %s\n", name);
  printf("I like to eat %s\n", food);
  printf("Your email is %s\n", email);

  // bools or boolian are yes or no-- true or false -- 0 or 1 statements 

  bool isOnline = false;
  bool isStudent = true;
  bool forSale = false;
  if(isOnline){
    printf("You are online");
  }
  else{
    printf("You are offline");
  }printf("\n");
  
  if (isStudent){
    printf("you are a student\n");
  }
  else{
    printf("you are not a student\n");
  }
  if (forSale){
    printf("X is for sale\n");
  }
  else{
    printf("x is not for sale\n");
  }
  //printf("%d", isOnline);
  return 0;

  //              SUMMERY 
  //  variable = A reusable container for value.
  //              Behaves as if it were the value it contains.
  //  int = whole numbers (4 bytes in mordern systems)
  //  float =single-percision decimal number (8bytes)
  //  char = single character (1 byte)
  //  char[] =array of characters (size varies)
  //  bool = true or false (1 byte, requires <stdbool.h>)


}





































































