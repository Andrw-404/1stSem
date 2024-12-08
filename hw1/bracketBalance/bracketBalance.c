#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

bool Balance(const char* string) {
	int counter = 0;
	int i = 0;
	while (string[i] != '\0') {
		if (string[i] == '(') {
			counter++;
		}
		else if (string[i] == ')') {
			counter--;
		}
		if (counter < 0) {
			return false;
		}
		i++;
	}
	return counter == 0;
}

int main(void) {
	setlocale(LC_ALL, "Russian");
	const char* string = "((()))";
	if (Balance(string)) {
		printf("Баланс скобок соблюдён\n\n");
	}
	else {
		printf("Баланс скобок нарушен\n\n");
	}
}