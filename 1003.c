#include <stdio.h>

int main()
{
	float len, sum;
	int n;

	while (scanf("%f", &len) != EOF) {
		if (len == 0.00)
			break;
		sum = 0;
		for (n = 2; sum < len; n++)
			sum += 1.0 / n;
		printf("%d card(s)\n", n - 2);
	}

	return 0;
}
