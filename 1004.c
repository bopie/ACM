#include <stdio.h>

int main()
{
	float sum = 0, mval;

	while (scanf("%f", &mval) != EOF)
		sum += mval;

	printf("$%1.2f", sum / 12);

	return 0;
}
