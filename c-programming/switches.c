#include <stdio.h>

int main ()
{
  // switch = An alternative to using many if-else statements
  //          More efficent w/ fixed integer values
  

  int dayOfWeek = 0;

  printf("Enter the day of the week (1 - 7):  ");
  scanf("%d", &dayOfWeek);
  
  switch(dayOfWeek){
    case 1:
    printf("It is monday\n");
    break;

    case 2:
    printf("It is tuesday\n");
    break;

    case 3:
    printf("It is wednesday\n");
    break;

   case 4:
    printf("It is thursday\n");
    break;

  case 5:
    printf("It is friday\n");
    break;

  case 6:
    printf("it is saturday\n");
    break;

  case 7:
    printf("It is sunday\n");
    break;

  default:
    printf("please Enter (1 - 7)\n");

  }






  return 0;
}
