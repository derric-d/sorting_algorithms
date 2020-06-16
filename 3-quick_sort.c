#include "sort.h"

/**
 * swap_int - swap ints
 * @n1: num 1
 * @n2: num 2
 */
void swap_int(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

/**
 * lomuto_part - lomuto partion algo
 * @array: passed
 * @low: low part idx
 * @hi: hi part idx
 * @size: size passed
 * Return: idx for partition
 */
int lomuto_part(int array[], int low, int hi, size_t size)
{
	int pivot, i, j;

	pivot = array[hi];
	i = (low - 1);

	for (j = low; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			++i;
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[i + 1])
	{
		swap_int(&array[i + 1], &array[hi]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * qs_helper - called by qs
 * @array: passed - to sort
 * @low: low bound
 * @hi: hi bound
 * @size: size of array
 */
void qs_helper(int *array, int low, int hi, size_t size)
{
	int p_idx;

	if (low < hi)
	{
		p_idx = lomuto_part(array, low, hi, size);
		qs_helper(array, low, p_idx - 1, size);
		qs_helper(array, p_idx + 1, hi, size);
	}
}
/**
 * quick_sort - qs caller
 * @array: passed structure
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs_helper(array, 0, size - 1, size);
}
