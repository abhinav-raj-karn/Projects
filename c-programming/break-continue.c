// break =  Break out of a loop (STOP)
// continue = Skip current cycle of a loop (SKIP)

#include <stdio.h>

int main()
{
  for(int i = 1; i <= 10; i++){
    if (i == 4){
     // break;  // stops at 3
      continue;  // skips 4 
    }
    printf("%d\n", i);
  }
  return 0;
}


