typedef struct {
	int cap;
	int len;
	int *arr;
} Vec;

Vec new_v();

void push(Vec *v, int n);

void clear(Vec *v);

void print(Vec *v);
