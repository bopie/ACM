#include <stdio.h>

int okay(int k, int c)
{
	int n = 2 * k, i = 0;

	while (n > k) {
		i = (i + c - 1) % n;
		if (i < k)
			return 0;
		n--;
	}	

	return 1;
}

int main()
{
	int i, j, k, table[13], flag;

	for (i = 1; i < 14; i++) {
		flag = 0;
		for (j = i + 1; ; j += 2 * i) {
			for (k = 0; k < i; k++) {
				if (okay(i, j + k)) {
					table[i - 1] = j + k;
					flag = 1;
				}
			}
			if (flag == 1)
				break;
		}
	}
	while (scanf("%d", &k), k)
		printf("%d\n", table[k - 1]);

	return 0;
}
