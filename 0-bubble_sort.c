#include "sort.h"

/**
 * swap - swap two ints
 * @n1: 1st int
 * @n2: 2nd int
 */
void swap_int(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}


/**
 * bubble_sort - sort array
 * @array: passed array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	uint i = 0;
	uint j = 0;
	char f = 1;

	if (!array || size == 1)
		return;

	for (i = 0; i < size - 1 && f; i++)
	{
		f = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_int(&array[j], &array[j + 1]);
				print_array(array, size);
				f = 1;
			}
		}
	}

}
