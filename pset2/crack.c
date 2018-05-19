// Giuliano Forghieri
// 9th April 2018
// Problem set 2 - Crack

// Run the programme by ./newcrack 'insert one of the following hashes'

// anushree:50xcIMJ0y.RXo = YES
// brian:50mjprEcqC/ts = CA
// bjbrown:50GApilQSG3E2 = UPenn (takes a while)
// lloyd:50n0AAUD.pL8g = lloyd (takes a while)
// malan:50CcfIk1QrPr6 = maybe (takes a while)
// maria:509nVI8B9VfuA = TF
// natmelo:50JIIyhDORqMU = nope
// rob:50JGnXUgaafgc = ROFL
// stelios:51u8F0dkeDSbY = NO
// zamyla:50cI2vYkF0YU2 = LOL


// A program that cracks passwrods
#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Requisites of the crypt() function
#include <unistd.h>

// Declare counter integer
int counter = 0;

// Declare a global array to 5 all null characters
char test[5] = {'\0', '\0', '\0', '\0', '\0'};

// Command-line argument
int main(int argc, string argv[])
{
    // Declaration of incrementChar function
    void incrementChar(char string[], int index);

    // If invalid command-line argument print error
    if (argc != 2)
    {
        printf("Error, correct usage: ./crack 'hash'\n");
        return 1;
    }
    // Get Salt
    char salt[3];
    strncpy(salt, argv[1], 2);
    salt[2] = '\0';

    // Crack the password using brute force
    do
    {
        // Compares until next null character
        if (strcmp(crypt(test, salt), argv[1]) == 0)
        {
            // Print password
            printf("Password found: %s\n", test);
            return 0;
        }

        // Increment letter
        incrementChar(test, 0);
    }
    while (test[4] == '\0');

    // When reaches this line of code print password not found
    printf("Password not found\n");
    return 0;
}
// Function definition with recursion
void incrementChar(char string[], int index)
{
    if (string[index] == '\0')
    {
        string[index] = 'A';
    }
    else if (string[index] == 'z')
    {
        string[index] = 'A';
        incrementChar(string, index + 1);
        // To inform user that program is running in the background
        counter++;
        if (counter == 25000)
        {
            printf("Loading...\n");
            counter = 0;
        }
    }
    else
    {
        string[index]++;
    }
}
