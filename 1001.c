#include <stdio.h>

//multiplicand, multiplier and length of mpd
int multi(int *mpd, int mpr, int len)
{
	int c = 0, i = 0;

	while (i < len || c) {
		mpd[i] = mpd[i] * mpr + c;
		c = mpd[i] / 10;
		mpd[i] %= 10;
		i++;
	}

	return i;	
}

int main()
{
	int base, exp, len, i, n, dot;
	int res[256];
	char snum[6];

	while(scanf("%s %d", snum, &exp) != EOF) {
		base = 0;
	   	len = 1;

		//init the result
		for (i = 0; i < 256; i++)
			res[i] = 0;
		res[0] = 1;

		//trim 0
		for (n = 5; n >= 0; n--)
			if (snum[n] != '0')
				break;
		for (i = 0; i < n + 1; i++) {
			if (snum[i] == '.')
				dot = n - i;
			else
				base = base * 10 + snum[i] - 48;
		}

		//total dot shift
		dot *= exp;
		while (exp--) {
			len = multi(res, base, len);
		}
		
		if (len < dot) {
			printf(".");
			for (i = 0; i < dot - len; i++)
				printf("0");
		}
		for (i = len - 1; i >=0; i--) {
			if (i == dot - 1)
				printf(".");
			printf("%d", res[i]);
		}
		putchar('\n');
	}

	return 0;
}
