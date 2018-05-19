// Giuliano Forghieri
// 1st May 2018
// Problem Set 3 - Helper functions for music

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ONEoverEIGHT 0.125

#include "helpers.h"

int octave;
int accidental;
int frequency_rounded;

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    double numerator = fraction[0] - 48.00;
    double denominator = fraction[2] - 48.00;
    return (numerator / denominator) / ONEoverEIGHT;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double worked_frequency = 440.00;
    double distance_from_four = 0;
    // Base case
    if (note[0] == '\0')
    {
        printf("The program has finished\n");
        return 0;
    }
    // Adjust frequency to accidental
    else if (note[1] == '#' || note[1] == 'b')
    {
        octave = note[2] - 48;
        accidental = note[1];

        if (accidental == '#')
        {
            worked_frequency = worked_frequency * pow(2.0, (1.0 / 12.0));
        }

        else if (accidental == 'b')
        {
            worked_frequency = worked_frequency / pow(2.0, (1.0 / 12.0));
        }
    }
    // Else there is no accidental
    else
    {
        octave = note[1] - 48;
    }
    // Adjust frequency to octave
    distance_from_four = octave - 4.00;
    // If higher octave
    if (distance_from_four > 0)
    {
        worked_frequency = worked_frequency * pow(2.00, distance_from_four);
    }
    // If lower octave
    else if (distance_from_four < 0)
    {
        double changesign = distance_from_four * -1.00;
        worked_frequency = worked_frequency / pow(2.00, changesign);
    }
    // Support different letters
    if (note[0] == 'C')
    {
        worked_frequency = worked_frequency / pow(2.00, (9.00 / 12.00));
    }
    else if (note [0] == 'D')
    {
        worked_frequency = worked_frequency / pow(2.00, (7.00 / 12.00));
    }
    else if (note [0] == 'E')
    {
        worked_frequency = worked_frequency / pow(2.00, (5.00 / 12.00));
    }
    else if (note [0] == 'F')
    {
        worked_frequency = worked_frequency / pow(2.00, (4.00 / 12.00));
    }
    else if (note [0] == 'G')
    {
        worked_frequency = worked_frequency / pow(2.00, (2.00 / 12.00));
    }
    else if (note [0] == 'B')
    {
        worked_frequency = worked_frequency * pow(2.00, (2.00 / 12.00));
    }
    // Return the corresponding frequency of the notes rounded to the nearest integer
    frequency_rounded = round(worked_frequency);
    return frequency_rounded;
    frequency(note);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}