#include "sort.h"

/**
 * swap_int - swap two integers
 * @n1: num 1
 * @n2: num2
 */
void swap_int(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

/**
 * shell_sort - sort with knuths sequence
 * @array: array paassed
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	uint i, j, g;
	int tmp;

	g = 1;
	if (!array || size < 2)
		return;
	while ((g * 3) + 1 < size)
	{
		g = g * 3 + 1;
	}
	while (g > 0)
	{
		for (i = g; i < size; i++)
		{
			tmp = array[i];

			for (j = i; j >= g && array[j - g] > tmp; j -= g)
				array[j] = array[j - g];
			array[j] = tmp;
		}
		print_array(array, size);
		g = (g - 1) / 3;
	}
}
