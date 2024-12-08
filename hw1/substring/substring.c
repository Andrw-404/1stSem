#include <stdio.h>
#include <string.h>
#include <locale.h>

int OccurrenceOfASubstring(const char* S, const char* S1) {
	int counter = 0;
	int lenS = strlen(S);
	int lenS1 = strlen(S1);

	if (lenS1 > lenS)
		return 0;

	for (int i = 0; i <= lenS - lenS1; ++i) {
		int j = 0;
		for (j = 0; j < lenS1; ++j) {
			if (S[i + j] != S1[j])
				break;
		}
		if (j == lenS1)
			counter++;
	}
	return counter;
}

int main(void) {
	setlocale(LC_ALL, "Russian");
	int result = OccurrenceOfASubstring("adgdadmfad", "ad");
	printf("Количество вхождений подстроки в строку: %d\n", result);
	return 0;
}
