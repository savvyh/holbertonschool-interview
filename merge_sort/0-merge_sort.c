#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * merge_sort - Sorts an array of integers in ascending order
 *
 * @array: Array to sort
 * @size: Number of elements in array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;
	size_t curr_size, left_start, mid, right_end, i, j, k, p;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	for (curr_size = 1; curr_size < size; curr_size *= 2)
	{
		for (left_start = 0; left_start < size; left_start += 2 * curr_size)
		{
			mid = left_start + curr_size - 1;
			right_end = left_start + 2 * curr_size - 1;

			if (mid >= size)
				mid = size - 1;
			if (right_end >= size)
				right_end = size - 1;

			if (mid < right_end)
			{
				i = left_start;
				j = mid + 1;
				k = left_start;

				printf("Merging...\n");
				printf("[left]: ");
				for (p = left_start; p <= mid; p++)
				{
					if (p > left_start)
						printf(", ");
					printf("%d", array[p]);
				}
				printf("\n");
				printf("[right]: ");
				for (p = mid + 1; p <= right_end; p++)
				{
					if (p > mid + 1)
						printf(", ");
					printf("%d", array[p]);
				}
				printf("\n");

				while (i <= mid && j <= right_end)
				{
					if (array[i] <= array[j])
						temp[k++] = array[i++];
					else
						temp[k++] = array[j++];
				}
				while (i <= mid)
					temp[k++] = array[i++];
				while (j <= right_end)
					temp[k++] = array[j++];

				for (i = left_start; i <= right_end; i++)
					array[i] = temp[i];

				printf("[Done]: ");
				for (p = left_start; p <= right_end; p++)
				{
					if (p > left_start)
						printf(", ");
					printf("%d", array[p]);
				}
				printf("\n");
			}
		}
	}

	free(temp);
}