/* 
Michael Porter
CSE-130-50-4248 - Online only 
Wed, August 21: 6:38PM - 8:23PM
Dr. Yampolskiy
Description: ASCII-art representation of Dr.Yampolskiy. This program is also meant to represent my current knowledge with being able to use the main() function, print statements,
			 escape sequences, comments, headers, and another functionality I added with being able to detect the user's operating system through conditional if statements. 
			 I heard from someone about your height so I wanted to do an ASCII art of a gnome, so enjoy. :)
*/
#include <stdio.h> /* Allows the program to use the necessary I/O operations. */
#ifdef _WIN32 /* If the user is using the Windows operating system... */
	#include <windows.h> /* ...uses the header that allows the 'Sleep' function.*/
#else /* If the user is using a Unix-based operating system... */
	#include <unistd.h> /* ...uses the header to allow functionality of the 'sleep' function.*/
#endif /* Declares the end of the conditional code. */

main()
{
	printf("This is my program for Dr.Yampolskiy with my ASCII representation of him.\n");
	printf("Student Name\t| Freshman?\t| Is this representation supposed to be a joke?\nMichael Porter\t| True\t\t| True\n\nYour Operating System is... ");
	#ifdef _WIN64 /* Detects if the user is using Windows x64 operating System.*/
		printf("Windows x64.\n"); /* Displays to the user that they're using Windows x64.*/
		Sleep(10000); /* Pauses the program for 10 seconds to allow the user enough time to read all on-screen text before generating the gnome. (Measured in milliseconds.)*/
	#elif define(_WIN32) /* Detects if the user is using Windows x32 operating System.*/
		printf("Windows x32.\n"); /*Displays to the user that they're using Windows x32.*/
		Sleep(10000); /* Pauses the program for 10 seconds. (Measured in milliseconds.)*/
	#elif defined(__APPLE__) && define(__MACH__) /* Detects both apple and macOS macros to be able to specifically identify if the user is using the macOS operating system.*/
		printf("macOS.\n"); /* Displays to the user that they're using macOS.*/
		sleep(10); /* Uses the Unix-based sleep function to pause the program for 10 seconds. (Measured in seconds.)*/
	#else /* If user is using neither Windows or macOS... */
		printf("Unkown system. \n"); /* Displays to the user that they are using an unknown system... */
		printf("Error: Unable to use a sleep function due to an unknown operating system."); /* and states that it cannot pause the program like how it is able to for Windows and Unix-based systems.*/
	#endif /* Declares the end of the conditional code. */
	/*
		All the print statements below combine together to print the ASCII art of a gnome.
	*/
printf("--------------------------------------------------------------------------------\n");   
printf("                                                             111\n");                                            
printf("                                                          111111\n");                                              
printf("                                                          01  11\n");                                              
printf("                                                          0    1\n");                                              
printf("                                                         11    1\n");                                              
printf("                                                       111     1\n");                                              
printf("                                                   1111       11\n");                                              
printf("                                              111111          11\n");                                              
printf("                                         11111               11\n");                                              
printf("                                    11111                    1\n");                                              
printf("                                1111                        1\n");                                              
printf("                              111                          1\n");                                              
printf("                             11                          11\n");                                              
printf("                           11                          11\n");                                              
printf("                         111                         11\n");                                              
printf("                        11                         11\n");                                              
printf("                      11                         11\n");                                              
printf("                     11                         11\n");                                              
printf("                    11                        111\n");                                              
printf("                   11                         111\n");                                              
printf("                   11                         10\n");                                              
printf("                   11                          11\n");                                              
printf("                  11                            1\n");                                              
printf("                  11                            11\n");                                              
printf("                  1                             11\n");                                              
printf("                  1                              11\n");                                              
printf("                  1                              11\n");                                              
printf("                  1                               1\n");                                              
printf("                  1                               11\n");                                              
printf("                  1 1                            111\n");                                              
printf("                  111                             11\n");                                              
printf("                 11             111111111111        11\n");                                              
printf("               11           1111                     11\n");                                              
printf("              11        1111   1111111111              1\n");                                              
printf("             11     11111  11111         1111           11\n");                                              
printf("          11111         1111                 1111        111111\n");                                              
printf("        11   111111111111                     0111111111111  10\n");                                              
printf("        111111          1                     0          11111\n");                                              
printf("         01             11                   11           11\n");                                              
printf("        11               1                  11             11\n");                                              
printf("       11                 111             111               01\n");                                              
printf("       11                   111111111111111                 11\n");                                              
printf("      11                                                  11101\n");                                              
printf("     11  1                                                 111\n");                                              
printf("   111 111                                                  11\n");                                              
printf("  11 1101                                                    11\n");                                              
printf("10111111                                                      111\n");                                              
printf("     11                                                         111\n");                                              
printf("     1                                                       111111\n");                                              
printf("    11   1                                                   11\n");                                              
printf("    1   10                                                    11\n");                                              
printf("    1 1111          11             11                          11\n");                                              
printf("   1111 11         11              11            11             11 \n");                                              
printf("       11          1                11            11             11\n");                                              
printf("      11          1                 11             111        1111\n");                                              
printf("    111         11       11         111   11         1011111111\n");                                              
printf("   11111111   111111111111 1111111111  1111111111     1111\n");                                              
printf("             111              11           11      1111111111\n");                                                                                                                                                                                         
} /* Declares the end of the main() function. Therefore, marking the end of the program.*/
                                                                                                                                                      
