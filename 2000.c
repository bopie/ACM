#include <stdio.h>
#include <math.h>

int get_total_icons(int day)
{
	int low;

	low = (sqrt(8 * day) - 1) / 2;
		
	return low * (low + 1) * (2 * low + 1) / 6 + (day - low * (low + 1) / 2) * (low + 1);
}

int main(int argc, char *argv[])
{
	int day, total_icons;

	while (1) {
		scanf("%d", &day);
		if (day == 0)
			break;
		total_icons = get_total_icons(day);
		printf("%d %d\n", day, total_icons);
	}

	return 0;
}
