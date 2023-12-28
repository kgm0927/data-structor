#include <stdio.h>
#define SIZE 6
#define _CRT_SECURE_NO_WARNINGS


void get_integer(int list[]) {
	printf("6개의 정수를 입력하세요.");
	for (int i = 0; i < SIZE; i++) {
		scanf("%d", &list[i]);
	}
}

int cal_sum(int list[]) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += *(list + i);
	}
	return sum;
}

int main(void) {
	int list[SIZE];
	get_integer(list);
	printf("합=%d \n", cal_sum(list));

	return 0;
}