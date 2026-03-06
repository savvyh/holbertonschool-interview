#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_subarray - Prints a subarray of integers
 *
 * @array: The subarray to print
 * @size: Number of elements in subarray
 */
void print_subarray(int *array, size_t size)
{
	size_t i;

	if (size == 0)
		return;
	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
}

/**
 * merge - Merges two sorted subarrays into one
 *
 * @array: The array containing both subarrays
 * @left: Starting index of left subarray
 * @mid: Ending index of left subarray
 * @right: Ending index of right subarray
 * @temp: Temporary array for merging
 */
void merge(int *array, size_t left, size_t mid, size_t right, int *temp)
{
	size_t i = left, j = mid + 1, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_subarray(array + left, mid - left + 1);
	printf("\n");
	printf("[right]: ");
	print_subarray(array + j, right - j + 1);
	printf("\n");

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i <= mid)
		temp[k++] = array[i++];
	while (j <= right)
		temp[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_subarray(array + left, right - left + 1);
	printf("\n");
}

/**
 * merge_sort_helper - Recursively splits array and merges
 *
 * @array: The array to sort
 * @left: Starting index of current subarray
 * @right: Ending index of current subarray
 * @temp: Temporary array for merging
 */
void merge_sort_helper(int *array, size_t left, size_t right, int *temp)
{
	size_t mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		merge_sort_helper(array, left, mid, temp);
		merge_sort_helper(array, mid + 1, right, temp);
		merge(array, left, mid, right, temp);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *
 * @array: Array to sort
 * @size: Number of elements in array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_helper(array, 0, size - 1, temp);
	free(temp);
}
