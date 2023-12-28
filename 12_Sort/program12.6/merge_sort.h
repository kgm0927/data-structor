#include <stdio.h>

#define MAX_SIZE 10


int sorted[MAX_SIZE];
/* i는 정렬된 왼쪽 리스트에 대한 인덱스
	j는 정렬된 오른쪽 리스트에 대한 인덱스
	k는 정렬된 리스트에 대한 인덱스. */

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left; j = mid + 1; k = left;

	/* 분할 정렬된 list의 합병 */

	while (i<=mid && j<=right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];

	}

	if (i > mid)
		for (l = j; l < right; l++)
			sorted[k++] = list[l];

	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];

	for ( l = left; l <= right; l++)
	{
		list[l] = sorted[l];
	}

}

void merge_sort(int list[], int left, int right) {
	int mid;
	if (left<right)
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid+1,right);
		merge(list, left, mid, right);
	}
}