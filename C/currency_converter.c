
/*
*                                                       SUBJECT
*
* Write down a program that converts currency given in EUROS to an another one. Firstly, user types in the value in EUROS 
* and afterwards user types a letter corresponding to a code of an another currency. The codes and changing rates are: 
* u for USD (US Dollar). Change rate: 1.19978
* c for CAD (Canadian Dollar) Change rate: 1.41748
* The program will run until the user wont enter 0 as a value in EUROS and the q for the code. If user enters a code different 
* to those of above, program will convert EUROS to FRF (French Francs) with a change rate of 6.55957. 
*
*
*/


#include <stdio.h>

#define USD 1.19978
#define CAD 1.41748
#define FRF 6.55957

int main() {
  double userInputEuros = 0.0;
  double previousValueEur = 0.0;
  char code = 0;
  
  do {
    
  printf("\n\n");
  printf("ONLINE EXCHANGE RATE (type 0 and q to quit followed by ENTER)\n");
  printf("....................\n");
  printf("Enter amount in EUR: ");

  scanf("%lf%*c", &userInputEuros);

  previousValueEur = userInputEuros;

  printf("Give the code of currency to convert to: ");
  scanf("%c%*c", &code);

  switch (code) {
    case 'u':
      userInputEuros /= USD;
      printf("The amount of %lf EUR is : %lf in USD", previousValueEur, userInputEuros);
      break;
    case 'U': 
      userInputEuros /= USD;
      printf("The amount of %lf EUR is : %lf in USD", previousValueEur, userInputEuros);
      break;
    case 'c':
      userInputEuros /= CAD;
      printf("The amount of %lf EUR is : %lf in CAD", previousValueEur, userInputEuros);
      break;
    case 'C':
      userInputEuros /= CAD;
      printf("The amount of %lf EUR is : %lf in CAD", previousValueEur, userInputEuros);
      break;
    case 'q':
      break;
    default:
      userInputEuros /= FRF;
      printf("The amount of %lf EUR is : %lf in FRF", previousValueEur, userInputEuros);
      break;
  }
} while (userInputEuros != 0 || code != 'q');
  return 0;
}
