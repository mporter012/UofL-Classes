/*
Michael Porter
Dr. Roman Yampolskiy
CSE-130-50-4248 | Online
Monday, September 9, 2024
Description:
    A simple calculator in the C programming language that performs various arithmetic operations
    and checks for prime numbers. Provides support for addition, subtraction, multiplication, division
    exponentation, modulus, prime checking functions, and factorials. The program also features a menu for user I/O
    and does not end until the user specifies they want to exit the program.
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to perform addition
float addition(float x, float y){
    float result; // Variable to store the result of the addition
    
    // Displaying the operation to the user
    printf("The equation is 'x+y'\n");
    
    // Taking input from the user for the first operand
    printf("x: ");
    scanf("%f", &x);
    
    // Taking input from the user for the second operand
    printf("y: ");
    scanf("%f", &y);
    
    // Calculating the result of x + y
    result = x + y;
    
    // Displaying the result
    printf("%f + %f = %f\n", x, y, result); // Fixed order of x and y
    return result; // Returning the result
}

// Function to perform subtraction
float subtraction(float x, float y){
    float result; // Variable to store the result of the subtraction
    
    // Displaying the operation to the user
    printf("The equation is 'x-y'\n");
    
    // Taking input from the user for the first operand
    printf("x: ");
    scanf("%f", &x);
    
    // Taking input from the user for the second operand
    printf("y: ");
    scanf("%f", &y);
    
    // Calculating the result of x - y
    result = x - y;
    
    // Displaying the result
    printf("%f - %f = %f\n", x, y, result); // Fixed order of x and y
    return result; // Returning the result
}

// Function to perform multiplication
float multiplication(float x, float y){
    float result; // Variable to store the result of the multiplication
    
    // Displaying the operation to the user
    printf("The equation is 'x*y'\n");
    
    // Taking input from the user for the first operand
    printf("x: ");
    scanf("%f", &x);
    
    // Taking input from the user for the second operand
    printf("y: ");
    scanf("%f", &y);
    
    // Calculating the result of x * y
    result = x * y;
    
    // Displaying the result
    printf("%f * %f = %f\n", x, y, result); // Fixed order of x and y
    return result; // Returning the result
}

// Function to perform division
float division(float x, float y){
    float result; // Variable to store the result of the division
    
    // Displaying the operation to the user
    printf("The equation is 'x/y'\n");
    
    // Taking input from the user for the numerator
    printf("x: ");
    scanf("%f", &x);
    
    // Taking input from the user for the denominator
    printf("y: ");
    scanf("%f", &y);
    
    // Checking for division by zero
    if (y == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0; // Return 0 or handle error as needed
    }
    
    // Calculating the result of x / y
    result = x / y;
    
    // Displaying the result
    printf("%f / %f = %f\n", x, y, result); // Fixed order of x and y
    return result; // Returning the result
}

// Function to perform exponential operation
int exponential(int x, int y){
    int result; // Variable to store the result of the exponentiation
    
    // Displaying the operation to the user
    printf("The equation is 'x^y'\n");
    
    // Taking input from the user for the base
    printf("x: ");
    scanf("%f", &x);
    
    // Taking input from the user for the exponent
    printf("y: ");
    scanf("%f", &y);
    
    // Calculating the result of x^y
    result = pow(x, y);
    
    // Displaying the result
    printf("%f ^ %f = %f\n", x, y, result); // Fixed order of x and y
    return result; // Returning the result
}

// Function to perform modulus operation (integer only)
int modulus(int x, int y){
    int result; // Variable to store the result of the modulus operation
    
    // Displaying the operation to the user
    printf("The equation is 'x % y'\n");
    
    // Taking input from the user for the first operand
    printf("x: ");
    scanf("%d", &x);
    
    // Taking input from the user for the second operand
    printf("y: ");
    scanf("%d", &y);
    
    // Calculating the result of x % y
    result = x % y;
    
    // Displaying the result
    printf("%d %% %d = %d\n", x, y, result); // Fixed format specifier for integer
    return result; // Returning the result
}

// Function to check if a number is prime
bool isPrime(int x){
    // Checking if x is less than or equal to 1
    if (x <= 1){
        return false; // Numbers less than or equal to 1 are not prime
    }
    
    // Displaying factors of x
    printf("Factors of %d: 1", x);
    
    bool is_prime = true; // Assume the number is prime until proven otherwise
    for (int i = 2; i <= x / 2; i++){ // Loop from 2 to x/2
        if (x % i == 0){ // Check if i is a factor of x
            printf(", %d", i); // Print the factor
            if (i != x) {
                is_prime = false; // If i is not x, then x is not prime
            }
        }
    }
    printf("\n");
    
    return is_prime; // Return whether the number is prime or not
}

// Function to calculate factorial of a non-negative integer
long long factorial(int n){ //The long long data type is used for numbers that are larger integer values than the standard integer data type.
    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return -1; // Return an error value
    }
    
    long long result = 1; // Initialize result to 1
    
    for (int i = 1; i <= n; i++) {
        result *= i; // Multiply result by i
    }
    
    return result; // Return the computed factorial
}

// Function to calculate Fibonacci numbers up to the nth position
void fibonacci(int n, unsigned long long **fib_array){ //unsigned long long means that it can only use non-negative integers such as zero and positive values unlike the regular long long data type
    if (n < 0) {
        printf("Error: Fibonacci is not defined for negative numbers.\n");
        return;
    }
    
    // Allocate memory for the array based on user input
    *fib_array = (unsigned long long *)malloc((n + 1) * sizeof(unsigned long long));
    if (*fib_array == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    if (n == 0) {
        (*fib_array)[0] = 0; // Base case
        return;
    }
    
    if (n == 1) {
        (*fib_array)[0] = 0; // Base case
        (*fib_array)[1] = 1; // Base case
        return;
    }
    
    (*fib_array)[0] = 0; // F(0)
    (*fib_array)[1] = 1; // F(1)
    
    for (int i = 2; i <= n; i++) {
        (*fib_array)[i] = (*fib_array)[i - 1] + (*fib_array)[i - 2]; // Compute the next Fibonacci number
    }
}

// Function to print the calculator menu
void printMenu(){
    printf("---------------------------------------\n");
    printf("Calculator Menu: \n");
    printf("(1) Addition\n");
    printf("(2) Subtraction\n");
    printf("(3) Multiplication\n");
    printf("(4) Division \n");
    printf("(5) Exponential (Integers Only)	)\n");
    printf("(6) Modulus (Integers Only)\n");
    printf("(7) Test if prime (integers only)\n");
    printf("(8) Factorial (Integers Only)\n");
    printf("(9) Fibonacci (Integers Only)\n");
	printf("(10) Print Menu\n");
    printf("(11) Exit\n");
    printf("---------------------------------------\n");
}

// Main function
int main(){
    int choice; // Variable to store the user's menu choice
    choice = 0; // Initialize choice to 0
    printMenu(); // Display the menu
    
    // Loop until the user chooses to exit
    while (choice != 10){
        float x, y; // Variables to store user input for operands
        float result; // Variable to store the result of the operation
        int int_x, int_y; // Variables to store integer input for modulus and prime checking
        unsigned long long *fib_array = NULL; // Pointer to store the Fibonacci sequence array //does this so that the array only goes to where the user wants

        
        // Prompt the user for a choice of operation
        printf("Please choose an operation: ");
        scanf("%d", &choice);
        
        // Perform the operation based on the user's choice
        if (choice == 1){
            result = addition(x, y);
            printf("Result: %f\n", result);
        }
        else if (choice == 2){
            result = subtraction(x, y);
            printf("Result: %f\n", result);
        }
        else if (choice == 3){
            result = multiplication(x, y);
            printf("Result: %f\n", result);
        }
        else if (choice == 4){
            result = division(x, y);
            printf("Result: %f\n", result);
        }
        else if (choice == 5){
            result = exponential(x, y);
            printf("Result: %f\n", result);
        }
        else if (choice == 6){
            // For modulus operation, use integer variables
            printf("x: ");
            scanf("%d", &int_x);
            printf("y: ");
            scanf("%d", &int_y);
            result = modulus(int_x, int_y);
            printf("Result: %d\n", (int)result); // Cast to int for display
        }
        else if (choice == 7){
            // For prime checking, use integer variables
            printf("x: ");
            scanf("%d", &int_x);
            bool prime_result = isPrime(int_x);
            printf("Is Prime: %s\n", prime_result ? "True" : "False");
        }
        else if (choice == 8){
            // For factorial, use integer variable
            printf("Enter a non-negative integer: ");
            scanf("%d", &int_x);
            long long fact_result = factorial(int_x);
            if (fact_result != -1) {
                printf("Factorial of %d is %lld\n", int_x, fact_result);
            }
        }
        else if (choice == 9){
            // For Fibonacci, use integer variable
            printf("Enter the position in Fibonacci sequence: ");
            scanf("%d", &int_x);
            if (int_x >= 0) {
                fibonacci(int_x, &fib_array);
                printf("Fibonacci number at position %d is %llu\n", int_x, fib_array[int_x]);
                free(fib_array); // Free allocated memory
            } else {
                printf("Error: Position cannot be negative.\n");
            }
        }
        else if (choice == 10){
            printMenu(); // Print the menu again
        }
        else if (choice == 11){
            printf("Goodbye!\n"); // Exit message
            break; // Exit the loop
        }
        else {
            printf("Invalid choice. Please try again.\n"); // Handle invalid choices
        }
    }
    
    return 0; // Indicate successful completion
}
