#include "sort.h"

/**
 * swap_int - swap ints
 * @n1: num1
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
 * selection_sort - selection sort implemented
 * @array: passed array
 * @size: size of array
 *
 */
void selection_sort(int *array, size_t size)
{
	uint i, j, min = 0;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		swap_int(&array[min], &array[i]);
		if (i != min)
			print_array(array, size);
	}
}
