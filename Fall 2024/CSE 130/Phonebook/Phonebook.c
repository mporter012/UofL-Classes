/*
Michael Porter
Dr. Yampolskiy
Wed, October 10, 2024
Description: This program acts as a phonebook for the user. 
Allows adding, deleting, displaying contacts, sorting, finding phone numbers, 
deleting all entries, saving contacts to a file, and loading contacts from a file.
If no file is specified by the user, a default file will be used. If the default file
is not found, it will be created.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FRIENDS 100 // Maximum number of friends the phone book can hold
#define MAX_NAME_LEN 50 // Maximum length of names (first and last)
#define PHONE_LEN 15    // Maximum length of phone numbers
#define DEFAULT_FILE "default_phonebook.txt" // Default file to store/retrieve contacts

// Structure to hold contact information
typedef struct {
    char firstName[MAX_NAME_LEN];
    char lastName[MAX_NAME_LEN];
    char phoneNumber[PHONE_LEN];
} Contact;

// Function declarations
void saveToFile(Contact phoneBook[], int size, const char* fileName);
int loadFromFile(Contact phoneBook[], const char* fileName);

int main() {
    Contact phoneBook[MAX_FRIENDS]; // Array to hold added contacts
    int size = 0; // Number of contacts in the phone book
    int choice;
    char fileName[100]; // File name to save or load contacts

    // Seed for random number generation, used for generating random entries
    srand(time(NULL));

    // Ask the user if they want to load from a specific file or use the default
    printf("Enter file name to load contacts (or press Enter to use default): ");
    fgets(fileName, sizeof(fileName), stdin);
    // Remove newline character from the input
    fileName[strcspn(fileName, "\n")] = '\0';

    // Load contacts from the specified file or default file
    if (strlen(fileName) == 0) {
        size = loadFromFile(phoneBook, DEFAULT_FILE); // Use default if no file is specified
    } else {
        size = loadFromFile(phoneBook, fileName);
    }

    // Main menu loop
    while (1) {
        // Display the main menu
        printf("\nPhone Book Application\n");
        printf("1) Add Friend\n");
        printf("2) Delete Friend\n");
        printf("3) Show Phone Book\n");
        printf("4) Sort Phone Book\n");
        printf("5) Find Phone Number\n");
        printf("6) Print Random Entry\n");
        printf("7) Delete All Entries\n");
        printf("8) Save Contacts to File\n");
        printf("9) Exit\n");
        printf("What do you want to do: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character after scanf

        switch (choice) {
            case 1:
                // Add a new friend to the phone book
                if (size >= MAX_FRIENDS) { // Check if phone book is full
                    printf("Phone book is full.\n");
                } else {
                    Contact newFriend;

                    // Get user input for the new contact
                    printf("Enter First Name: ");
                    scanf("%s", newFriend.firstName);
                    printf("Enter Last Name: ");
                    scanf("%s", newFriend.lastName);
                    printf("Enter Phone Number: ");
                    scanf("%s", newFriend.phoneNumber);

                    // Add new friend to phone book and increment the size
                    phoneBook[size] = newFriend;
                    size++;
                    printf("Friend added successfully.\n");
                }
                break;

            case 2:
                // Delete a friend from the phone book
                if (size == 0) {
                    printf("Phone book is empty.\n");
                } else {
                    char firstName[MAX_NAME_LEN], lastName[MAX_NAME_LEN];

                    // Get name of friend to delete
                    printf("Enter First Name of Friend to Delete: ");
                    scanf("%s", firstName);
                    printf("Enter Last Name: ");
                    scanf("%s", lastName);

                    int found = 0; // Flag to check if the friend was found
                    // Loop through phone book to find the friend by name
                    for (int i = 0; i < size; i++) {
                        if (strcmp(phoneBook[i].firstName, firstName) == 0 && strcmp(phoneBook[i].lastName, lastName) == 0) {
                            // Shift the remaining contacts to delete the contact
                            for (int j = i; j < size - 1; j++) {
                                phoneBook[j] = phoneBook[j + 1];
                            }
                            size--; // Decrease the size of the phone book
                            printf("Friend deleted successfully.\n");
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Friend not found.\n");
                    }
                }
                break;

            case 3:
                // Show all contacts in the phone book
                if (size == 0) {
                    printf("Phone book is empty.\n");
                } else {
                    printf("Phone Book Entries:\n");
                    // Loop through the phone book and display all entries
                    for (int i = 0; i < size; i++) {
                        printf("%s %s: %s\n", phoneBook[i].firstName, phoneBook[i].lastName, phoneBook[i].phoneNumber);
                    }
                }
                break;

            case 4:
                // Sort the phone book by first name or last name
                if (size == 0) {
                    printf("Phone book is empty.\n");
                } else {
                    int sortByFirstName, sortByLastName;

                    // Ask the user which field to sort by
                    printf("Sort by First Name (1 for Yes, 0 for No): ");
                    scanf("%d", &sortByFirstName);
                    printf("Sort by Last Name (1 for Yes, 0 for No): ");
                    scanf("%d", &sortByLastName);

                    // Simple bubble sort to sort by selected field
                    for (int i = 0; i < size - 1; i++) {
                        for (int j = 0; j < size - i - 1; j++) {
                            if ((sortByFirstName && strcmp(phoneBook[j].firstName, phoneBook[j+1].firstName) > 0) || 
                                (sortByLastName && strcmp(phoneBook[j].lastName, phoneBook[j+1].lastName) > 0)) {
                                // Swap the two contacts if necessary
                                Contact temp = phoneBook[j];
                                phoneBook[j] = phoneBook[j+1];
                                phoneBook[j+1] = temp;
                            }
                        }
                    }
                    printf("Phone book sorted.\n");
                }
                break;

            case 5:
                // Find and display the phone number of a specific friend
                if (size == 0) {
                    printf("Phone book is empty.\n");
                } else {
                    char firstName[MAX_NAME_LEN], lastName[MAX_NAME_LEN];

                    // Ask for the name of the contact to find
                    printf("Enter First Name: ");
                    scanf("%s", firstName);
                    printf("Enter Last Name: ");
                    scanf("%s", lastName);

                    int found = 0; // Flag to track if the friend is found
                    // Loop through the phone book to find the contact
                    for (int i = 0; i < size; i++) {
                        if (strcmp(phoneBook[i].firstName, firstName) == 0 && strcmp(phoneBook[i].lastName, lastName) == 0) {
                            printf("Phone number for %s %s: %s\n", firstName, lastName, phoneBook[i].phoneNumber);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Contact not found.\n");
                    }
                }
                break;

            case 6:
                // Print a random entry from the phone book
                if (size == 0) {
                    printf("Phone book is empty.\n");
                } else {
                    int randomIndex = rand() % size; // Generate random index
                    printf("Random Entry: %s %s: %s\n", phoneBook[randomIndex].firstName, phoneBook[randomIndex].lastName, phoneBook[randomIndex].phoneNumber);
                }
                break;

            case 7:
                // Delete all entries in the phone book
                size = 0; // Reset the size of the phone book to 0
                printf("All entries deleted.\n");
                break;

            case 8:
                // Save contacts to a file
                printf("Enter file name to save contacts (or press Enter to use default): ");
                fgets(fileName, sizeof(fileName), stdin);
                fileName[strcspn(fileName, "\n")] = '\0';

                // Save to the specified file or default file
                if (strlen(fileName) == 0) {
                    saveToFile(phoneBook, size, DEFAULT_FILE); // Use default if no file is specified
                } else {
                    saveToFile(phoneBook, size, fileName);
                }
                break;

            case 9:
                // Exit the program
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Function to save phone book to a file
void saveToFile(Contact phoneBook[], int size, const char* fileName) {
    FILE *file = fopen(fileName, "w"); // Open the file in write mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Write each contact to the file
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %s %s\n", phoneBook[i].firstName, phoneBook[i].lastName, phoneBook[i].phoneNumber);
    }

    fclose(file); // Close the file
    printf("Contacts saved to file: %s\n", fileName);
}

// Function to load phone book from a file
int loadFromFile(Contact phoneBook[], const char* fileName) {
    FILE *file = fopen(fileName, "r"); // Open the file in read mode
    if (file == NULL) {
        // If file not found, attempt to create it
        printf("File '%s' not found. Creating new file.\n", fileName);
        file = fopen(fileName, "w"); // Create the file
        if (file == NULL) {
            printf("Error creating file.\n");
            return 0;
        }
        fclose(file); // Close the newly created file
        return 0; // Return empty phonebook
    }

    int i = 0; // Index for phone book entries
    // Read each contact from the file
    while (fscanf(file, "%s %s %s", phoneBook[i].firstName, phoneBook[i].lastName, phoneBook[i].phoneNumber) == 3) {
        i++;
        if (i >= MAX_FRIENDS) {
            printf("Phone book limit reached. Some contacts may not be loaded.\n");
            break;
        }
    }

    fclose(file); // Close the file
    printf("Contacts loaded from file: %s\n", fileName);
    return i; // Return the number of contacts loaded
}
