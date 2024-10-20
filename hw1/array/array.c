#include <stdio.h>
#include <locale.h>

void swap(int m, int n, int array[]) {
	int temp = 0;
	int start = 0;
	int end = m - 1;
	while (start < end) {
		temp = array[start];
		array[start] = array[end];
		array[end] = temp;
		start++;
		end--;
	}

	start = m;
	end = m + n - 1;
	while (start < end) {
		temp = array[start];
		array[start] = array[end];
		array[end] = temp;
		start++;
		end--;
	}
	start = 0;
	end = m + n - 1;
	while (start < end) {
		temp = array[start];
		array[start] = array[end];
		array[end] = temp;
		start++;
		end--;
	}
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
	swap(m, n, array);
	for (int i = 0; i < size; i++) {
		printf("%d", array[i]);
	}
	printf("\n\n");
	return 0;
}
