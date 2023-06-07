#include "vec.h"
#include <stdio.h>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void qs(int *arr, int len) {
	int piv = arr[(len - 1) / 2], l = 0, r = len - 1;

	printf("inp: ");
	print(&(Vec){0, len, arr});

	while (l <= r) {
		while (arr[l] < piv)
			++l;

		while (arr[r] > piv)
			--r;

		if (l <= r) {
			swap(arr + l, arr + r);
			++l;
			--r;
		}
	}

	printf("out: ");
	print(&(Vec){0, len, arr});

	if (r > 0)
		qs(arr, r + 1);

	if (l < len - 1)
		qs(arr + l, len - r - 1);
}

int main() {
	int a;
	Vec v = new_v();
	while (scanf("%d", &a) == 1)
		push(&v, a);

	qs(v.arr, v.len);

	print(&v);
	clear(&v);

	return 0;
}
