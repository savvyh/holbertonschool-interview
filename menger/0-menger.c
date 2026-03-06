#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * menger - Draws a 2D Menger Sponge
 * @level: The level of the sponge to draw
 */
void menger(int level)
{
	if (level < 0)
		return;

	if (level == 0)
	{
		printf("#\n");
		return;
	}

	int size = pow(3, level);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int x = i;
			int y = j;
			int is_empty = 0;

			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					is_empty = 1;
					break;
				}
				x /= 3;
				y /= 3;
			}
			if (is_empty)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
