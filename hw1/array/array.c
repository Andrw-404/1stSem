#include <stdio.h>
#include <locale.h>


void reverseSegments(int *start, int *end) {
	--end;
	while (start < end) {
		if (start != end) {
			*start ^= *end;
			*end ^= *start;
			*start ^= *end;
		}
		start++;
		end--;
	}
	}

void mainSwap(int m, int n, int array[]) {
	reverseSegments(array, array + m);
	reverseSegments(array + m, array + m + n);
	reverseSegments(array, array + m + n);
}

int main(void) {
	setlocale(LC_ALL, "Russian");
	int array[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int m = 4;
	int n = 5;
	int size = sizeof(array) / sizeof(array[0]);
	printf("Исходный массив: \n");
	for (int i = 0; i < size; i++) {
		printf("%d", array[i]);
	}
	printf("\n\n");
	printf("Массив после преобразования:\n");
	mainSwap(m, n, array);
	for (int i = 0; i < size; i++) {
		printf("%d", array[i]);
	}
	printf("\n\n");
	return 0;
}
