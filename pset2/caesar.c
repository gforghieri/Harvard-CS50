// Giuliano Forghieri
// 6th April 2018
// Problem Set 2 - Caesar

// Caesar's cipher

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ENGLISHALPHA 26

// Command-line argument
int main(int argc, string argv[])
{
    // Store the 2nd element, the "key" in integer k
    int k = atoi(argv[argc - 1]);
    // If without or with more than one command line argument or command line argument is negative
    if (argc <= 1 || argc > 2 || k <= 0)
    {
        printf("Error, give a non-negative integer as command-line argument e.g. ./caesar 5\n");
        return 1;
    }
    // Get plaintext
    string plaintext = get_string("plaintext: ");
    // Encrypt plaintext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // If alphabetical
        if (isalpha(plaintext[i]))
        {
            // If lowercase -a ASCII value i.e. convert to alphabetical, add key, mod26, add remainder to a
            if (islower(plaintext[i]))
            {
                int asctoalpha = plaintext [i] - 'a';
                int remainlow = (asctoalpha + k) % 26;
                printf("%c", remainlow + 'a');
            }
            // If uppercase -A ASCII value i.e. convert to alphabetical, add key, mod26, add remainder to A
            if (isupper(plaintext[i]))
            {
                int asctoalpha = plaintext [i] - 'A';
                int remainup = (asctoalpha + k) % 26;
                printf("%c", remainup + 'A');
            }
        }
        // If not alphabetical simply print out the character
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    // Print a new line at the end
    printf("\n");
}
