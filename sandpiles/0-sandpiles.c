#include "sandpiles.h"
#include <stdbool.h>
#include <stdio.h>

/**
 * grid_sum - Add two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void grid_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] += grid2[x][y];
		}
	}
}

/**
 * print_grid - Print a sandpile grid
 * @grid: 3x3 grid
 *
 */
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Check if a sandpile is stable
 * @grid: 3x3 grid
 * Return: true if the grid is stable, false otherwise
 */

bool is_stable(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] > 3)
			{
				return (false);
			}
		}
	}
	return (true);
}

/**
 * toppling - Topple a sandpile
 * @grid: 3x3 grid
 */

void toppling(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] > 3)
			{
				grid[x][y] -= 4;
				if (x > 0)
				{
					grid[x - 1][y] += 1;
				}
				if (x < 2)
				{
					grid[x + 1][y] += 1;
				}
				if (y > 0)
				{
					grid[x][y - 1] += 1;
				}
				if (y < 2)
				{
					grid[x][y + 1] += 1;
				}
			}
		}
	}
}

/**
 * sandpiles_sum - Add two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid_sum(grid1, grid2);
	while (!is_stable(grid1))
	{
		print_grid(grid1);
		toppling(grid1);
	}
}
