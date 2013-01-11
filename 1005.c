#include <stdio.h>
#include <math.h>

#define PI 3.1416

int main()
{
	int n, i = 0;
	float x, y, r;

	scanf("%d", &n);
	while (i++ < n) {
		scanf("%f %f", &x, &y);
		printf("Property %d: This property will begin eroding in year %d.\n", i, (int) ceil(PI * (x * x + y * y) / 100));
	}
	printf("END OF OUTPUT.\n");

	return 0;
}
