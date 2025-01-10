/*
Michael Porter
Dr. Yampolskiy
CSE 130-50-4248 Online
Tue, September 17, 2024
Description:
	This program uses the user's name, age, and favorite color to make a story. 
	The ending of the story is completely randomized by randomly choosing an ending from a predefined array of possible endings.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
	//Variable declaration
	char name[50];
	int age;
	char color[50];
	
	//predefined story endings
    const char *messages[] = {
        "laptop",
        "bicycle",
        "Toyota Corolla",
        "guitar",
        "phone",
        "book collection",
        "coffee mug",
        "backpack",
        "camera",
        "smartwatch",
        "drone",
        "skateboard",
        "fitness tracker",
        "headphones",
        "gaming console",
        "tablet"
    };
	
	//gets the number of objects
	int numObjects = sizeof(messages) / sizeof(messages[0]);
	
	// seed the random number generator
	srand(time(NULL));
	
	
	//asks the user for their name, age, and favorite color
	printf("What is your name? ");
	scanf("%s", name);
	
	printf("How old are you? ");
	scanf("%d", &age);
	
	printf("What is your favorite color? ");
	scanf("%s", color);
	
	//generates a random index from story endings
	int randomIndex = rand() % numObjects;
	
	//Generate the random story
	printf("%s is a %d year old who likes their %s %s...\n", name, age, color, messages[randomIndex]);
}