// return = returns a value back to where you call a function

#include <stdio.h>
#include <stdbool.h>

/*
double cube(double num){
  return num * num * num;
}

double square(double num){
  return num * num;
}


int main() {
  double x = cube(2);
  double y = cube(3);
  double z = cube(4);

  printf("%lf\n", x);
  printf("%lf\n", y);
  printf("%lf\n", z);

  return 0;
}
*/

bool ageCheck(int age){
  
  if(age >= 18){
    return true;
  }
  else {
    return false;
  }

}

int main(){

  int age = 12;

  if(ageCheck(age)){
    printf("You may sign up");
  }
  else {
    printf("You must be 18+ to sign up");
  }

  return 0;
}
