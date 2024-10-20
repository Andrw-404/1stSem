#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>


double linePower(double number, int degree);
double logPower(double number, int degree);

bool testPower() {
	return (linePower(2, 3) == 8) && (linePower(2, -3) == 0.125) && (linePower(0, 2) == 0) && (linePower(5, 0) == 1)
		&& (logPower(2, 3)) == 8 && (logPower(2, -3) == 0.125) && (logPower(0, 2) == 0) && (logPower(5, 0) == 1)
		&& (isnan(linePower(0, -2))) && (isnan(logPower(0, -2)));
}


double linePower(double number, int degree) {
	double result = 1;
	if (degree == 0)
		return 1;
	if (degree < 0) {
		if (number == 0) {
			return NAN;
		}
		number = 1 / number;
		degree = -degree;
	}

	int i = 0;
	while (i < degree) {
		result *= number;
		i++;
	}
	return result;
}

double logPower(double number, int degree) {
	if (degree == 0)
		return 1;

	if (degree < 0) {
		if (number == 0) {
			return NAN;
		}
		number = 1 / number;
		degree = -degree;
	}

	if (degree % 2 == 0) {
		double halfPower = logPower(number, degree / 2);
		return halfPower * halfPower;
	}
	else {
		return number * logPower(number, degree - 1);
	}
}

int main(void) {
	setlocale(LC_ALL, "Russian");

	if (!testPower()) {
		printf("\n!Ошибка. Тест не пройден!\n");
		exit(1);
	}

	double inputNumber = 0;
	int inputDegree = 0;

	printf("Введите число, которое Вы хотите возводить в степень: ");
	scanf_s("%lf", &inputNumber);

	printf("\n");

	printf("Введите степень, в которую Вы хотите возводить заданное Вами число: ");
	scanf_s("%d", &inputDegree);

	double lineAnswer = linePower(inputNumber, inputDegree);
	printf("\n\n===Линейная сложность===\nОтвет: %.7f", lineAnswer);

	double logAnswer = logPower(inputNumber, inputDegree);
	printf("\n\n===Логарифмическая сложность===\nОтвет: %.7f\n\n", logAnswer);
}
