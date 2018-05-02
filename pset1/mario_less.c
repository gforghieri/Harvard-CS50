// Giuliano Forghieri
// 19 March 2018
// Problem Set 1

// Print out the mario pyramid
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for the height of the pyramid and re-prompt if value not correct
    int h;
    do
    {
        h = get_int("Enter a height for the pyramid, something between the positive numbers 1 and 23: ");
    }
    while (h < 0 || h > 23);


    // Print out this many rows
    for (int i = 0; i < h; i++)
    {
        // Print out this many spaces
        for (int j = 0; j < h - 1 - i; j++)
        {
            printf(" ");
        }
        // Print this many #
        for (int k = 0; k < i + 2; k++)
        {
            printf("#");
        }
        {
            printf("\n");
        }
    }
}




