// variable scope = refers to where a variable is recognized and accessible.
//                  variable can share the same name if 
//                  they're in diffent scopes {}


#include <stdio.h>

int add(int x, int y){
  int result = x + y;
  return result;
}

int subtract(int x, int y){
  int result = x - y;
  return result;
}

int main(){
 
  int result = subtract(3, 4);
  
  printf("%d\n", result);

  return 0;
}
