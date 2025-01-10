/*
Michael Porter
Dr. Yampolskiy
CSE 130 Online
Exam 1
Mon, October 7
*/
#include <stdio.h>

#define PI 3.14  // declare PI as a global variable

// Function to get a positive value from the user
float getPositiveValue(const char* prompt) { // Turned this process into a seperate function to reduce repeating code. As you guessed, the function has the user repeat their input until a positive value is obtained.
    float value;
    
    while (1) {
        printf("%s", prompt);
        scanf("%f", &value);
        
        // Check if the value is positive
        if (value > 0) {
            return value;  // Return the valid value
        } else {
            printf("Please enter a positive value.\n");
        }
    }
}

int main() {
    float radius, height, volume;

    // Prompt user for radius and height
    radius = getPositiveValue("Enter the radius of the cylinder: ");
    height = getPositiveValue("Enter the height of the cylinder: ");

    // Calculate the volume of the cylinder
    volume = PI * radius * radius * height;

    // Output the result
    printf("The volume of the cylinder is: %.2f\n", volume);

    return 0;  // Return success
}
