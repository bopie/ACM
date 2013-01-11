#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAXSIZE 200

typedef struct CIRCLE {
	int len;
	int *value;
	struct CIRCLE *next;
} Circle;

void cipher(Circle *node, char *txt, int k)
{
	int shift;
	char cipher[MAXSIZE];

	while (node != NULL) {
		int i;
		shift = k % node->len;
		for (i = 0; i < node->len; i++)
			cipher[node->value[(i + shift) % node->len]] = txt[node->value[i]];
		node = node->next;
	}
	memcpy(txt, cipher, sizeof(char) * MAXSIZE);
}

Circle* findCircle(Circle *node, int *seq, int n)
{
	Circle *head, *pre;
	int circle[MAXSIZE];
	char flag[MAXSIZE];
	//circle index
	int i;

	//init flag
	memset(flag, 0, MAXSIZE);

	//init head
	if (node == NULL) {
		if (node == NULL)
			node = (Circle *) malloc(sizeof(Circle));
		head = node;
	}

	for (i = 0; i < n; i++) {
		int idx, start, ci = 0;

		if (flag[i] == 1)
			continue;


		idx = i;
		start = i;
		while (seq[idx] != start) {
			circle[ci] = idx;
			flag[idx] = 1;
			idx = seq[idx];
			ci++;
		}
		circle[ci] = idx;
		flag[idx] = 1;

		if (node == NULL) {
			node = (Circle *) malloc(sizeof(Circle));
			pre->next = node;
		}
		node->len = ci + 1;
		node->value = (int *) malloc(sizeof(int) * node->len);
		memcpy(node->value, circle, sizeof(int) * node->len);
		pre = node;
		node = node->next = NULL;
	}

	return head;
}

int main()
{
	int n, k, seq[MAXSIZE], i, len;
	char txt[MAXSIZE];

	while (scanf("%d", &n)) {
		Circle *circle = NULL;
		if (n == 0)
			break;
		for (i = 0; i < n; i++) {
			scanf("%d", &seq[i]);
			seq[i]--;
		}
		circle = findCircle(circle, seq, n);

		while (scanf("%d ", &k)) {
			if (k == 0)
				break;
			gets(txt);
			len = strlen(txt);
			for (i = len; i < n; i++)
				txt[i] = ' ';

			cipher(circle, txt, k);
			for (i = 0; i < n; i++)
				putchar(txt[i]);
			putchar('\n');
		}
		putchar('\n');

		while (circle != NULL) {
			Circle *tmp = circle;
			circle = circle->next;
			free(tmp->value);
			free(tmp);
		}
	}

	return 0;
}
