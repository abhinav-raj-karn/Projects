#include <stdio.h>
#include <string.h>
#define BUFFER_LEN 10000
char buffer[10000];

int main()
{
  printf("Welcome to your daily hatered journal. it's fucking awesome that you are keep dooing worse in your life.\n");

  printf("Enter 3 things that you hate about yourself.\n");
  for (int i = 0; i < 3; i++){
    memset(buffer, 0, BUFFER_LEN);
    fgets(buffer, BUFFER_LEN, stdin);
    FILE *fp = fopen("hate_db", "a");
    fputs(buffer, fp);
  }
  return 0;
}
