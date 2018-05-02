// Giuliano Forghieri
// 25 March 2018
// Problem set 1 - Credit

// Program that checks the validity of a credit card using Hans Peter Luhn's algorithm
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Introduce cnumber, cnumberd and ndigitsa
    long long ccnumber;
    long long ccnumberd;
    long long ccnumberd1;
    long long ccnumberd2;
    int ndigitsa = 0;
    long long ccnumber1 = 0;
    long long ccnumberpartsumm = 0;
    long long ccnumberdigit = 0;
    long long ccnumberseparatedigits = 0;
    long long ccnumberdigitnotbytwo = 0;
    long long ccnumbersumm = 0;
    long long ccnumberfinalsumm = 0;
    // Prompt user for credit card number once and re-prompt while negative or less then 5digit input
    do
    {
        ccnumber = get_long_long("Number: ");
        ccnumberd = ccnumber;
        ccnumberd1 = ccnumber;
        ccnumberd2 = ccnumber;
        while (ccnumber != 0)
        {
            ndigitsa++;
            ccnumber /= 10;
        }
    }
    while (ccnumberd < 0 || ndigitsa < 5);
    // Card number validation using Luhn's algorithm

    // Second-to-last digit multiplied by two, in separate line to not lose the 1st, second-to-last-digit
    ccnumber1 = (ccnumberd /= 10) % 10 * 2;
    if (ccnumber1 > 9)
    {
        // Separate and summ digits if bigger than 9
        ccnumber1 = (ccnumber1 / 10) % 10 + (ccnumber1 % 10);
    }
    ccnumberpartsumm = ccnumberpartsumm + ccnumber1;
    // Second-to-last digit loop, while means to stop if ccnumber is only 1 digit
    while (ccnumberd > 9)
    {
        ccnumberdigit = 0;
        ccnumberseparatedigits = 0;
        ccnumberdigit = (ccnumberd /= 100) % 10 * 2;
        if (ccnumberdigit > 9)
        {
            // Separate and summ digits if bigger than 9
            ccnumberseparatedigits = (ccnumberdigit / 10) % 10 + (ccnumberdigit % 10);
            ccnumberdigit = 0;
        }
        // Add the results of every other digit multiplied by 2 and then its digits together starting from second-to-last digit
        ccnumbersumm = ccnumberdigit + ccnumberseparatedigits + ccnumberpartsumm + ccnumbersumm;
        ccnumberpartsumm = 0;
    }

    // Add the digits which were not multiplied by two together
    while (ccnumberd1 != 0)
    {
        ccnumberdigitnotbytwo = (ccnumberd1 % 10) + ccnumberdigitnotbytwo;
        ccnumberd1 /= 100;
    }
    ccnumberfinalsumm = ccnumbersumm + ccnumberdigitnotbytwo;
    // 4 cases, Amex, Mastercard, Visa and Invalid
    if (ccnumberfinalsumm % 10 == 0 && (ccnumberd2 / 100000000000000) % 10 == 3 && ((ccnumberd2 / 10000000000000) % 10 == 4
            || (ccnumberd2 / 10000000000000) % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (ccnumberfinalsumm % 10 == 0 && (ccnumberd2 / 1000000000000000) % 10 == 5 && ((ccnumberd2 / 100000000000000) % 10 == 1
             || (ccnumberd2 / 100000000000000) % 10 == 2 || (ccnumberd2 / 100000000000000) % 10 == 3 || (ccnumberd2 / 100000000000000) % 10
             == 4 || (ccnumberd2 / 100000000000000) % 10 == 5))
    {
        printf("MASTERCARD\n");
    }
    else if (ccnumberfinalsumm % 10 == 0 && ((ccnumberd2 / 1000000000000) % 10 == 4 || (ccnumberd2 / 10000000000000) % 10 == 4
             || (ccnumberd2 / 100000000000000) % 10 == 4 || (ccnumberd2 / 1000000000000000) % 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
