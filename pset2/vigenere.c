// Giuliano Forghieri
// 8th April 2018
// Problem set 2 - Vigenère

// Vigenère's cipher
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int j = 0;
bool validcmdinput;

// Ask for command-line argument
int main(int argc, string argv[])
{
    // Store key in string k and count its characters integer m
    string k = argv[argc - 1];
    int m = strlen(k);
    // Check if command-line argument is alphabetical and if there is command-line argument
    for (int g = 0; g < m; g++)
    {
        if (isalpha(k[g]) && argc == 2)
        {
            validcmdinput = true;
        }
        // Error if argc is no greater than one or greater than 2 or k is non alphabetical
        else
        {
            validcmdinput = false;
            printf("Error, correct usage example: ./vigenere bacon\n");
            return 1;
        }
    }
    // If valid input, execute
    if (validcmdinput == true)
    {
        // Get plaintext
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        // Encryption loop
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // If char is uppercase in plaintext
            if (isupper(plaintext[i]))
            {
                int keytoalpha = tolower(k[j]) - 'a';
                int plaintoalpha = plaintext[i] - 'A';
                int remain = (keytoalpha + plaintoalpha) % 26;
                printf("%c", remain + 'A');
                // Recycling keyword until full plaintext encrypted
                if (j == m - 1)
                {
                    j = 0;
                }
                else
                {
                    j++;
                }
            }
            // If char is lowercase in plaintext
            else if (islower(plaintext[i]))
            {
                int keytoalpha = tolower(k[j]) - 'a';
                int plaintoalpha = plaintext[i] - 'a';
                int remain = (keytoalpha + plaintoalpha) % 26;
                printf("%c", remain + 'a');
                // Recycling keyword until full plaintext encrypted
                if (j == m - 1)
                {
                    j = 0;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }
}
