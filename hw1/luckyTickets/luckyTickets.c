#include <stdio.h>

int main(void) {
	int array[28] = { 0 };
	for (int i = 0; i < 10; ++i) {
		for (int k = 0; k < 10; ++k) {
			for (int j = 0; j < 10; ++j) {
				++array[i + j + k];
			}
		}
	}
	int numberOfTickets = 0;
	for (int i = 0; i < 28; ++i) {
		numberOfTickets += array[i] * array[i];
	}
	printf("Number of tickets = %d\n", numberOfTickets);
	return 0;
}