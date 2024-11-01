#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool removingDuplicateCharacters(const char* filename, char* output) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		perror("elementsForTask.txt");
		return false;
	}
	char current = 0;
	char last = 0;
	int index = 0;

	while ((current = fgetc(file)) != EOF) {
		if (current != last) {
			output[index++] = current;
			last = current;
		}
	}
	output[index] = '\0';
	fclose(file);
	return true;
}

bool checkOutput(const char* output, const char* expected) {
	return strcmp(output, expected) == 0;
}

int main(void) {
	char output[100] = " ";
	char* testFilename = "fileForTask.txt";
	const char* expected = "afgba";
	if (!removingDuplicateCharacters(testFilename, output)) {
		return 1;
	}
	if (!checkOutput(output, expected)) {
		printf("Ошибка\n");
		return 1;
	}
	printf("%s\n", output);
}