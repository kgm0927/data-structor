#include <stdio.h>

void insertion_sort(int list[], int n) { //�������� �˰���


	int i, j, key;

	for ( i = 0; i < n; i++)
	{
		key = list[i];

		for (j  = i-1; j>=0 && list[j]>key; j--)
		{
			list[j + i] = list[j];
		}

		list[j + 1] = key;
	}
}