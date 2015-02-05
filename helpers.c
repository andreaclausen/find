/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int beginning = 0;
    int ending = n - 1;
    // while length of list > 0
    while (ending >= beginning)
    {
        // look at middle of list
        int middle = (beginning + ending) / 2;
        if (values[middle] == value)
        {
            // if number found, return true
            return true;
        }
        
        // else if middle higher, search left
        else if (values[middle] > value)
        {
            ending = middle - 1;
        }
        
        // else if middle lower, search right
        else
        {
            beginning = middle + 1;
        }
    }    
    // return false
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Loop through all elements
    for (int i = 0; i < n; i++)
    {
        // Record current minimum and its index
        int smallest = values[i];
        int index = i;
        
        // Compare minimum to all numbers to its right to find absolute minimum
        for (int j = i + 1; j < n; j++)
        {
            // Update current minimum if a smaller number comes up
            if (smallest > values[j])
            {
                smallest = values[j];
                index = j;
            }
        }
        
        // Move absolute minimum to sorted part of the array        
        values[index] = values[i];
        values[i] = smallest;        
    }
    return;
}
