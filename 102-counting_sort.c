#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	
	int *count_array, *output;
	size_t i, max;

	max = 0;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */

	for (i = 0; i < size; i++)
	{
		if ((size_t)array[i] > max)
			max = array[i];
	}

	/* Allocate memory for count_array */

	count_array = malloc((max + 1) * sizeof(int));

	if (count_array == NULL)
		return;

	/* Initialize counting array elements to 0 */
	for (i = 0; i <= max; i++)
	{
		count_array[i] = 0;
	}

	/* Count occurrences of each element in the array */
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]++;
	}

	/* Accumulate the count_array */
	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];

	/* Create the output array */
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count_array);
		return;
	}

	/* Build the output array */
	for (i = 0; i < size; i++)
	{
		output[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	/* Copy the output array to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	/* Print the count_array */
	printf("%d", count_array[0]);
	for (i = 1; i <= max; i++)
		printf(", %d", count_array[i]);

	printf("\n");

	/* Free allocated memory */
	free(count_array);
	free(output);
}
