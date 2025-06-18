#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int length = 0;
	int i = 0;
	int j = 0;
	int *array = malloc(sizeof(int) * length);

	while (current != NULL)
	{
		array[i] = current->n;
		current = current->next;
		i++;
		length++;
	}

	for (j = 0; j < length / 2; j++)
	{
		if (array[j] != array[length - j - 1])
		{
			free(array);
			return (0);
		}
	}

	free(array);
	return (1);
}
