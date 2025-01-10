/*
Michael Porter
Dr. Yampolskiy
CSE 130 Online
Exam 1
Mon, October 7
*/
#include <stdio.h>

/* Changes that were made to the program:

	I was only able to find 8 errors within the program because there was not provided a description. Only using the context of the program that was provided, I was only able to resolve that the program
	was only supposed to run once so the fBalance variable was not continously updated. The program works just fine when I run it however so if you feel it was missing something, please let me know.

	1. changed "Main(){" to be "main(){" as the main function should be lowercase
	2. changed the main function to return an integer as 'system("pause")' does not reflect traditional C programming.
	3. First if statement missing a beginning curly bracket
	4. fixed scanf function in the first if statement. Missing ampersand.
	5. Added scanf function to get userinput after stating to make a selection. Otherwise program would not proceed after printing "Enter your selection: "
	6. If statements were using incorrect operands. Operands should have been "==" (equal to) instead of "=" (equals).
	7. Third prinf statement in second if statement is missing a semicolon
	8. The program allows for a user to input something other than an integer or float. As apart of this, made it so if a user input an invalid input, the program cleared the input buffer (affected whole program so will not be marked)
*/

int main(){ //1: previously - Main(){ //2: previously - main(){
    int iSelection = 0;
    float fTransAmount = 0.0;
    float fBalance = 100.25;
    
	while (1){ // Continues asking for input until the user inputs a valid data type
		printf("\n\tATM\n");
	    printf("\n1\tDeposit Funds\n");
	    printf("2\tWithdraw Funds\n");
	    printf("\nEnter your selection: ");
	
		if (scanf("%d", &iSelection)){ // Checks to see if the user's input was valid
			if (iSelection == 1 || iSelection == 2){
				// Correct input and valid selection
				break;
			}else{
				// Invalid selection
				printf("Invalid Selection. Please enter 1 for Deposit or 2 for Withdraw. \n");
			}
		} else {
			// Invalid input: non-integer or out-of-range selection
			printf("Invalid input. Please enter 1 for Deposit or 2 for Withdraw.\n");
			while (getchar() != '\n'); // Clear invalid input buffer
		}
	}
    
    
    if (iSelection == 1){ //3: previously - if (iSelection = 1) //6: previously - if (iSelection = 1){
    
    	//Checks for valid user input
    	while(1){
    		printf("\nEnter fund amount to deposit: ");
    	
			if (scanf("%f", &fTransAmount) == 1 && fTransAmount > 0) { //4: previously - scanf("%f", fTransAmount);
	    		//Correct input and valid amount
				printf("\nYour new balance is: $%.2f\n", fBalance + fTransAmount);
				break;
			}else{
				//User input was non-numeric or a negative amount
				printf("Invalid input. Please enter a positive number.\n");
				while (getchar() != '\n'); //clear invalid input buffer
			}
		}
	} //end if
	
	if (iSelection == 2) { //6: previously - if (iSelection = 2) {
		//Gets invalid input for withdraw amount
		while(1){
		
			printf("\nEnter fund amount to withdraw: ");
		
			if(scanf("%f", &fTransAmount) == 1 && fTransAmount > 0){ 
				//Correct input and valid amount
				if (fTransAmount > fBalance){
					printf("\nInsufficient funds\n");
				}else{
					printf("\nYour new balance is $%.2f\n", fBalance - fTransAmount);
				}
				break;
			} else {
				//User input was non-numeric or a negative amount
				printf("Invalid input. Please enter a positive number.\n");
				while (getchar() != '\n'); // Clear invalid input buffer
			} 
		}
	}//end if
    
    return 0; //2: previously - system("pause")
} //end main function