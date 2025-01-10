/*
Michael Porter
CSE-130-50-4248
Matthew Scobee
Mon, August 26
CurrencyXRate

Description: This program asks the user to input their desired amount they wish to spend in USD and using hard-coded curreny exchange rates taken from xe.com (uses midmarket rates), prints
             and displays the converted values into a table.
*/

#include <stdio.h>

/*
	Exchange Rates taken from https://xe.com/currencyconverter/
	
	The exchange rates listed on that site update very often so by the time this program is
	looked at, the exchange rates will be different as they use midmarket rates and their site
	updates every 10 minutes.
	These rates were obtained from the site Mon, August 26, 10:30AM
*/

//US Dollar Exchange Rates (USD):
float usdToGbp = 0.75724968; // Exchange rate from the US Dollar to the British Pound.
float usdToCad = 1.3467704; // Exchange rate from the US Dollar to the Canadian Dollar.
float usdToEur = 0.89481125; //Exchange rate from the US Dollar to the Euro.
float usdToAud = 1.4740937; // Exchange rate from the US Dollar to the Austrialian Dollar.
float usdToJpy = 144.50491; // Exchange rate from the US Dollar to the Japanese Yen.

//British Pound Exchange Rates (GBP):
float gbpToUsd = 1.32057; // Exchange rate from the British Pound to the US Dollar.
float gbpToCad = 1.778514; // Exchange rate from the British Pound to the Canadian Dollar.
float gbpToEur = 1.1817055; // Exchange rate from the British Pound to the Euro.
float gbpToAud = 1.9471403; // Exchange rate from the British Pound to the Australian Dollar.
float gbpToJpy = 190.609; // Exchange rate from the British Pound to the Japanese Yen.

//Canadian Dollar Exchange Rates (CAD):
float cadToUsd = 0.742517; // Exchange rate from the Canadian Dollar to the US Dollar.
float cadToGbp = 0.562267; // Exchange rate from the Canadian Dollar to the British Pound.
float cadToEur = 0.66442786; // Exchange rate from the Canadian Dollar to the Euro.
float cadToAud = 1.0948024; // Exchange rate from the Canadian Dollar to the Australian Dollar.
float cadToJpy = 107.1651; //Exchange rate from the Canadian Dollar to the Japanese Yen

//Euro Exchange Rates (EUR):
float eurToUsd = 1.11755; // Exchange rate from the Euro to the US Dollar.
float eurToGbp = 0.846235; // Exchange rate from the Euro to the British Pound.
float eurToCad = 1.50505; // Exchange rate from the Euro to the Canadian Dollar.
float eurToAud = 1.647848; // Exchange rate from the Euro to the Australian Dollar.
float eurToJpy = 161.38585; //Exchange rate from the Euro to the Japanese Yen.

//Australian Dollar Exchange Rates (AUD):
float audToUsd = 0.678408; // Exchange rate from the Australian Dollar to the US Dollar.
float audToGbp = 0.513574; // Exchange rate from the Australian Dollar to the British Pound.
float audToCad = 0.913337; // Exchange rate from the Australian Dollar to the Canadian Dollar.
float audToEur = 1.647848; // Exchange rate from the Australian Dollar to the Euro.
float audToJpy = 97.88473; // Exchange rate from the Australian Dollar to the Japanese Yen.

//Japanese Yen Exchange Rates (JPY):
float jpyToUsd = 0.00692018; // Exchange rate from the Japanese Yen to the US Dollar.
float jpyToGbp = 0.00524633; // Exchange rate from the Japanese Yen to the British Pound.
float jpyToCad = 0.00933140; // Exchange rate from the Japanese Yen to the Canadian Dollar.
float jpyToEur = 0.00619633; // Exchange rate from the Japanese Yen to the Euro.
float jpyToAud = 0.0102161; // Exchange rate from the Japanese Yen to the Australian Dollar.

// Function to print and display the conversion table. Takes in the Amount variable.
void printConversionTable(float amount)
{
	printf("________________________________________________________\n"); // Ceiling of the table.
    printf("|     | USD | GBP | CAD | EUR | AUD | JPY |\n"); // Header row of the table. Displays the currencies and their columns. Following rows will also have a column for the currency as well.
    printf("| USD |%.3f|%.3f|%.3f|%.3f|%.3f|%.3f|\n", // prints the currency conversion as a float value limited to 3 decimals. Takes the calculations from the next line.
			amount, amount * usdToGbp, amount * usdToCad, amount * usdToEur, amount * usdToAud, amount * usdToJpy); // takes and stores the float values that are necessary for the calculation and printing for the conversion table. Previous line uses this line.
    printf("| GBP |%.3f|%.3f|%.3f|%.3f|%.3f|%.3f|\n", // prints the currency conversion as a float value limited to 3 decimals. Takes the calculations from the next line.
			amount * gbpToUsd, amount, amount * gbpToCad, amount * gbpToEur, amount * gbpToAud, amount * gbpToJpy); // takes and stores the float values that are necessary for the calculation and printing for the conversion table. Previous line uses this line.
    printf("| CAD |%.3f|%.3f|%.3f|%.3f|%.3f|%.3f|\n", // prints the currency conversion as a float value limited to 3 decimals. Takes the calculations from the next line.
			amount * cadToUsd, amount * cadToGbp, amount, amount * cadToEur, amount * cadToAud, amount * cadToJpy); // takes and stores the float values that are necessary for the calculation and printing for the conversion table. Previous line uses this line.
    printf("| EUR |%.3f|%.3f|%.3f|%.3f|%.3f|%.3f|\n", // prints the currency conversion as a float value limited to 3 decimals. Takes the calculations from the next line.
			amount * eurToUsd, amount * eurToGbp, amount * eurToCad, amount, amount * eurToAud, amount * eurToJpy); // takes and stores the float values that are necessary for the calculation and printing for the conversion table. Previous line uses this line.
    printf("| AUD |%.3f|%.3f|%.3f|%.3f|%.3f|%.3f|\n", // prints the currency conversion as a float value limited to 3 decimals. Takes the calculations from the next line.
			amount * audToUsd, amount * audToGbp, amount * audToCad, amount * audToEur, amount, amount * audToJpy); // takes and stores the float values that are necessary for the calculation and printing for the conversion table. Previous line uses this line.
    printf("| JPY |%.3f|%.3f|%.3f|%.3f|%.3f|%.3f|\n", // prints the currency conversion as a float value limited to 3 decimals. Takes the calculations from the next line.
			amount * jpyToUsd, amount * jpyToGbp, amount * jpyToCad, amount * jpyToEur, amount * jpyToAud, amount); // takes and stores the float values that are necessary for the calculation and printing for the conversion table. Previous line uses this line.    
	printf("________________________________________________________\n"); // Bottom of the table.
} // End of the printConversionTable method.

int main(){ // Beginning of the Main Function where the user enters the amount of foreign currency they desire and the program prints the conversion table.
	float amount; // Declares and initializes the amount variables as a float.
	
	printf("Supported Currencies:\nUS Dollar (USD),\nBritish Pound (GBP),\nEuro (EUR),\nCanadian Dollar (CAD),\nAustrailian Dollar (AUD),\nJapanese Yen (JPY).\n\n"); // Informs the user of which currencies the program supports
	
	printf("DISCLAIMER: Program only lists midmarket currency exchange rates as of Monday, August 26, 2024. If you would like more current rates, visit; 'https://xe.com/'\n\n"); // Provides a disclaimer to the user that the midmarket exchange rates the program provides may not be current and to visit a trusted website to view the current rates. 
	
	printf("Enter the amount in USD: "); // prints and displays the user input asking for the user to input the amount of foreign currency they desire in USD.
	scanf("%f", &amount); // stores the user's answer to the previous question inside the amount variable as a float value.
	
	printConversionTable(amount); // calls upon the printConversionTable method and allows the amount variable to carry over.
	
	return 0; // signifies the end of the main function and end of the program.
} // end of the main method.