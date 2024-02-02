#include "sort.h"
/**
 * counting_sort - name of the function
 * Description: using the counting sort algorithm
 * @array: the array sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *array_temp;
	int j, count = 0, max = 0;

	/* Quitte la fonction si aucun tableau à trier */
	if (array == NULL || size < 2)
		return;

	/* cherche valeur max des valeurs à trier */
	for (i = 0; i < size; i++)
		max = (array[i] > max) * (array[i] - max) + max;

	/* créé un tableau tempon d'entier de taille max + 1(pour le 0) */
	array_temp = malloc(sizeof(int) * (max + 1));
	if (array_temp == NULL)
		return;

	/* rempli tableau tempon */
	/* où valeur = nb de valeur de array <= à l'index de tempon */
	for (j = 0; j <= max; j++)
	{
		for (i = 0; i < size; i++)
			count = count + (j == array[i]);

		array_temp[j] = count;
	}

	print_array(array_temp, max + 1);

	/* Lit tableau tempon et remplie le tableau array avec les valeurs triées */
	i = 0;
	for (j = 0; j <= max ; j++)
	{
		if (array_temp[j] > array_temp[j - 1])
			array[i++] = j;
	}

	free(array_temp);
}
