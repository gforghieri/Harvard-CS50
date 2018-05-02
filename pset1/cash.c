// Giuliano Forghieri
// 21 March 2018
// Problem set 1 - Cash

// Program that calculates the minimum number of coins required to give the user change
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Prompt the user for change owed
    int ncoins = 0;
    float change;
    int a;
    int b;
    int c;
    int d;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    // Change*100 then rounded and assigned to changec
    int changec = round(change * 100.0);
    // Add number of quarters
    for (a = changec; changec >= 25; changec -= 25)
    {
        ncoins++;
    }
    // Add number of dimes
    for (b = changec; changec >= 10; changec -= 10)
    {
        ncoins++;
    }
    // Add number of nickels
    for (c = changec; changec >= 5; changec -= 5)
    {
        ncoins++;
    }
    // Add number of pennies
    for (d = changec; changec >= 1; changec -= 1)
    {
        ncoins++;
    }
    printf("%i\n", ncoins);

}
