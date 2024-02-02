#include "sort.h"
/**
 * shell_sort - sorts an array of integers using the Shell sort algorithm
 * Description: whit Knuth sequence
 * @array: the array to sort
 * @size: size of the array
*/
void shell_sort(int array[], int size)
{
	int tempon, j, i, interval = 1;

	if (array == NULL || size < 2)
		return;
	/* Calcul de l'intervalle max selon la séquence de Knuth*/
	while (interval * 3 + 1 < size)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			tempon = array[i];
			j = i;

			/* Tri par insertion */
			while (j >= interval && array[j - interval] > tempon)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = tempon;
		}
		print_array(array, size);

		/* Calcul l'interval inférieur*/
		interval = (interval - 1) / 3;
	}
}
