#include "palindrome.h"

/**
 * is_palindrome - Checks whether or not a given unsigned integer is a palindrome
 * @n: The number to be checked
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long reversed = 0;
    unsigned long original = n;

    while (original != 0)
    {
        unsigned long remainder = original % 10;
        reversed = reversed * 10 + remainder;
        original /= 10;
    }

    return (reversed == n);
}
