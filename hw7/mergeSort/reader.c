#define _CRT_SECURE_NO_WARNINGS

#include "list.h"

#include <stdio.h>

void reader(const char* filename, List* list) {
    FILE* file = fopen(filename, "r");
	if (file == NULL) {
		perror("elementsForTask.txt");
		return;
	}
	char name[50];
	char phone[20];
	while (fscanf(file, "%s %s", name, phone) == 2) {
		addContact(list, name, phone);
	}
	fclose(file);
}