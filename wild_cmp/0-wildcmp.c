#include "holberton.h"

/**
 * wildcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0') {
        return (1);
    }
    if (*s1 == '\0' && *s2 == '*') {
        return (1);
    }
    return (0);
}