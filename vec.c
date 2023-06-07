#include "vec.h"
#include <stdio.h>
#include <stdlib.h>

#define CHUNK 100

Vec new_v() { return (Vec){CHUNK, 0, (int *)malloc(CHUNK * sizeof(int))}; }

void push(Vec *v, int n) {
	if (v->cap == v->len) {
		int *p = (int *)malloc((v->cap + CHUNK) * sizeof(int));
		printf("malloc! size: %d\n", v->cap + CHUNK);

		for (int i = 0; i < v->len; ++i)
			p[i] = v->arr[i];

		free(v->arr);
		v->arr = p;
		v->cap += CHUNK;
	}

	v->arr[v->len] = n;
	++v->len;
}

void clear(Vec *v) { free(v->arr); }

void print(Vec *v) {
	printf("[");

	if (v->len >= 1) {
		for (int i = 0; i < v->len - 1; ++i)
			printf("%d, ", v->arr[i]);

		printf("%d", v->arr[v->len - 1]);
	}

	printf("]\n");
}
