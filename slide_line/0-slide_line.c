#include "slide_line.h"

/**
 * slide - Move all non-null numbers
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide left or right
 * Return: void
 */
void slide(int *line, size_t size, int direction)
{
	size_t i;
	int newPosition;

	if (direction == SLIDE_LEFT)
	{
		newPosition = 0;
		for (i = 0; i < size; i++)
		{
			if (line[i] != 0)
			{
				line[newPosition] = line[i];
				if (i != (size_t)newPosition)
				{
					line[i] = 0;
				}
				newPosition++;
			}
		}
	}
	else
	{
		newPosition = size - 1;
		for (i = size; i > 0; i--)
		{
			if (line[i - 1] != 0)
			{
				line[newPosition] = line[i - 1];
				if ((i - 1) != (size_t)newPosition)
				{
					line[i - 1] = 0;
				}
				newPosition--;
			}
		}
	}
}

/**
 * merge - Merge identical numbers
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: Direction to merge left or right
 * Return: void
 */
void merge(int *line, size_t size, int direction)
{
	size_t i;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (line[i] != 0 && line[i] == line[i + 1])
			{
				line[i] += line[i];
				line[i + 1] = 0;
			}
		}
	}
	else
	{
		for (i = size - 1; i > 0; i--)
		{
			if (line[i] != 0 && line[i] == line[i - 1])
			{
				line[i] += line[i];
				line[i - 1] = 0;
			}
		}
	}
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide left or right
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
	{
		return (0);
	}

	slide(line, size, direction);
	merge(line, size, direction);
	slide(line, size, direction);

	return (1);
}
