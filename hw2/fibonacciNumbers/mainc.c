#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

bool testFibonacci() {
	int value = 9;
	int expected = 34;
	if (recursiveFibonacci(value) != expected) {
		printf("Ошибка");
		return false;
	}

	if (iterativelyFibonacci(value) != expected) {
		printf("Ошибка");
		return false;
	}
	return true;
}


unsigned int recursiveFibonacci(int n) {
	if (n < 2)
		return n;
	else
		return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

unsigned int iterativelyFibonacci(int n) {
	int fib1 = 0;
	int fib2 = 1;
	if (n < 2)
		return n;
	else {
		for (int i = 1; i < n; ++i) {
			int c = fib1 + fib2;
			fib1 = fib2;
			fib2 = c;
		}
		return fib2;
	}
}

int main(void) {
	setlocale(LC_ALL, "Russian");
	if (!testFibonacci())
		return 1;

	int number = 0;

	clock_t recursiveStart = clock();
	printf("Введите количество выводимых чисел Фибоначчи: ");
	scanf_s("%d", &number);
	printf("\n---Рекурсия---\n\n");
	for (int i = 0; i < number; i++) {
		printf("%lu ", recursiveFibonacci(i));
	}
	clock_t recursiveEnd = clock();
	double recursiveTime = (double)(recursiveEnd - recursiveStart) / CLOCKS_PER_SEC;

	clock_t iterativelyStart = clock();
	printf("\n\n---Итерация---\n\n");
	for (int l = 0; l < number; l++) {
		printf("%lu ", iterativelyFibonacci(l));
	}
	clock_t iterativelyEnd = clock();
	double iterativelyTime = (double)(iterativelyEnd - iterativelyStart) / CLOCKS_PER_SEC;

	printf("\n\n\n");

	printf("Время выполнения рекурсивного варианта: %.5f\n", recursiveTime);
	printf("Время выполнения итеративного варианта: %.5f\n", iterativelyTime);

	return 0;
}