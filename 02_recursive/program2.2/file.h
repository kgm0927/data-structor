#include <stdio.h>

double slow_power(double x, int n) {
	int i;
	int cnt = 0;
	double result = 1.0;
	for (i = 0; i < n; i++)
	{
		cnt++;
		result = result * x;
		printf("%d\n", cnt);
	
	}
	return (result);
}
double power(double x, int n) {
	int cnt = 1;
	printf("%d\n", cnt);
	if (n == 0)return 1;
	else if ((n % 2) == 0)
		return power(x * x, n / 2);
	else return x * power(x * x, (n - 1) / 2);
}