// Giuliano Forghieri
// 20 March 2018
// Problem Set 1 - Mario more comfortable

// Print out the mario pyramid
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for the height of the double pyramid and re-prompt if value not correct
    int h;
    do
    {
        h = get_int("Enter a height for the pyramid, something between the positive numbers 1 and 23: ");
    }
    while (h < 0 || h > 23);


    // Print out this many rows
    for (int i = 0; i < h; i++)
    {
        // Print out this many spaces for left pyramid
        for (int j = 0; j < h - 1 - i; j++)
        {
            printf(" ");
        }
        // Print this many # for left pyramid
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        // Print 2 spaces in the middle
        for (int l = 0; l < 2; l++)
        {
            printf(" ");
        }
        // Print this many # for right pyramid
        for (int m = 0; m < i + 1; m++)
        {
            printf("#");
        }
        {
            printf("\n");
        }
    }
}
