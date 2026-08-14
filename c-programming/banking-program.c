// BANKING PROGRAM

#include <stdio.h>

void CheckBalance(float balance);
float deposit();
float withdraw(float balance);

int main() {
  
  int choice = 0;
  float balance = 0.0f;

  printf("*** WELCOME TO THE BANK ***\n");

  do {

    printf("\nSelect an option\n");
    printf("\n1. Check Balance\n");
    printf("\n2. Deposit Money\n");
    printf("\n3. Withdraw Money\n");
    printf("\n4. Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        CheckBalance(balance);
        break;
      case 2:
        balance += deposit();
        break;
      case 3:
        balance -= withdraw(balance);
        break;
      case 4:
        printf("\nThank you for using the bank!\n");
        break;
      default:
        printf("\nInvalid choice! Please select 1 - 4\n");

    }

  } while (choice != 4);


  return 0;
}


void CheckBalance(float balance){
  printf("\nYour current balance is: $%.2f\n", balance);
}

float deposit(){
  float amount = 0.0f;

  printf("\nEnter amount to deposit: $");
  scanf("%f", &amount);

  if (amount < 0){
    printf("Invalid amount\n");
    return 0.0f;
  }
  else{
    printf("Successfully deposited $%.2f\n", amount);
    return amount;
  }
}

float withdraw(float balance){
  
  float amount = 0.0f;
  printf("\nEnter amount to withdraw: $");
  scanf("%f", &amount);
  if (amount < 0){
    printf("Invalid amount\n");
    return 0.0f;
  }
  else if(amount > balance) {
    printf("Insufficient funds! your balance is $%.2f\n", balance);
    return 0.0f;
  }
  else{
    printf("Successfully withdrew $%.2f\n", amount);
    return amount;
  }

}


