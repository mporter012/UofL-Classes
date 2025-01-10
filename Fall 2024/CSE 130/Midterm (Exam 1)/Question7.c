/*
Michael Porter
Dr. Yampolskiy
CSE 130 Online
Exam 1
Mon, October 7
*/
#include <stdio.h>

// Function Prototype
int myPower(int coefficient, int power);

// Function Definition
int myPower(int coefficient, int power) {
    int result = 1; 

    
    for (int i = 1; i <= power; i++) {
        result *= coefficient;  // Multiply result by coefficient
    }

    return result;  
}

// Main Function
int main() {
    int coefficient, power;

    printf("m (coefficient): ");
    scanf("%d", &coefficient);
    printf("n (power): ");
    scanf("%d", &power);

    // Call myPower and print the result
    printf("%d raised to the power of %d is: %d\n", coefficient, power, myPower(coefficient, power));

    return 0;  // Return success
}
