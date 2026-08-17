// gets -- NEVER USE THIS FUNCTION!!!!!!!!!!!!!!!!!


#include <stdio.h>
#include <string.h>
#define BUFFER_LEN 10000
char buffer[10000];

int main()
{
  printf("Welcome to your daily gratitude journal. it's awesome you keep up the practice.\n");

  printf("Enter 3 things that you're greatful for.\n");
  for (int i = 0; i < 3; i++){
    memset(buffer, 0, BUFFER_LEN);
    fgets(buffer, BUFFER_LEN, stdin);
    FILE *fp = fopen("gratitude_db", "a");
    fputs(buffer, fp);
  }
  return 0;
}

