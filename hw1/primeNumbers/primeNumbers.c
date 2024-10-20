#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

bool isPrimeNumber(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main(void) {
	setlocale(LC_ALL, "Russian");
	int number = 0;
	printf("Введите лимитное значение: ");
	scanf_s("%d", &number);
	printf("\nПростые числа до %d:\n", number);
	for (int i = 2; i <= number; i++)
		if (isPrimeNumber(i)) {
			printf("%d ", i);
		}
	printf("\n\n\n");
	return 0;
}