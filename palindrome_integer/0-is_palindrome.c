#include "palindrome.h"

/**
 * is_palindrome - Checks if a number is a palindrome
 * @number: The number to check
 *
 * Return: 1 if number is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long number)
{
	unsigned long original_number = number;
	unsigned long reversed = 0;
	unsigned long digit;

	if (number < 10)
		return (1);

	while (number > 0)
	{
		digit = number % 10;
		reversed = reversed * 10 + digit;
		number = number / 10;
	}

	return (original_number == reversed);
}

