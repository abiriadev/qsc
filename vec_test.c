#include "vec.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	Vec v = new_v();

	for (int i = 0; i < 50; ++i) {
		push(&v, i);
		// printf("cap: %d, len: %d\n", v.cap, v.len);
		print(&v);
	}

	clear(&v);

	return 0;
}
