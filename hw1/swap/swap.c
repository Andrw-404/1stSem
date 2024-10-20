#include <stdio.h>

void swap(int* left, int* right) {
	if (left != right) {
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}

void main() {
	int a = 3;
	int b = 5;
	swap(&a, &b);
	printf("a = %d; b = %d\n", a, b);
}