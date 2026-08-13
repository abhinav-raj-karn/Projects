#include <stdio.h>

/*
int main() {
  for (int i = 1; i < 4; i++){

    for(int j = 1; j < 10; j++){
      printf("%d ", j);
      }
     printf("\n");

  }
  return 0;
}
*/

/*
int main(){
  for (int i = 1; i <= 10; i++){

    for(int j = 1; j <= 10; j++){
      printf("%3d ", i * j);
    }
    printf("\n");
  }
}
*/

int main(){
  int rows = 0;
  int columns = 0;
  char symbol ='\n';

  printf("Enter the number of rows:  ");
  scanf("%d", &rows);


  printf("Enter the number of columns:  ");
  scanf("%d", &columns);

  printf("Enter the symbol to use:  ");
  scanf(" %c", &symbol);

  for (int i = 0; i < rows; i++){
    for (int i = 0; i < columns; i++){
      printf("%c", symbol);
    }
    printf("\n");
  }
}
