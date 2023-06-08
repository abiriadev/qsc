#include <stdio.h>
#include <string.h>

#define MX 8

int tmp[MX];

void mgs(int *arr, int len) {
	if (len <= 1)
		return;

	int m = len - len / 2, l = 0, r = m, i = 0;

	mgs(arr, m);
	mgs(arr + m, len / 2);

	memcpy(tmp, arr, len * sizeof(int));

	while (l < m && r < len)
		if (tmp[l] < tmp[r])
			arr[i++] = tmp[l++];
		else
			arr[i++] = tmp[r++];

	if (l < m)
		memcpy(arr + i, tmp + l, (m - l) * sizeof(int));
	else
		memcpy(arr + i, tmp + r, (len - r) * sizeof(int));
}

int main() {
	int arr[] = {4, 7, 2, 3, 8, 6, 5, 1}, len = 8;

	mgs(arr, len);

	printf("o: ");
	for (int i = 0; i < len; ++i)
		printf("%d, ", arr[i]);
	printf("\n");

	return 0;
}
