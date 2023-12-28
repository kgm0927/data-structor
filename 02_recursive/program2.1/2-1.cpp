#include <stdio.h>
#include "C:\Users\kgm09\source\repos\recursive02\program2.2/file.h"

int factorial(int n) {
	printf("factorial(%d)\n", n);
	if (n <= 1)return (1);
	else return (n * factorial(n - 1));
}
int main() {

	int n = factorial(5);
		printf("%d",n);
}