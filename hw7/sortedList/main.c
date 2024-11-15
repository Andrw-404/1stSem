#include "testsForList.h"
#include "sortedList.h"
#include "testsForTask.h"

#include <locale.h>
#include <stdio.h>

int main(void) {
	setlocale(LC_ALL, "Rus");
	if (!testAdd() || !testAddLast() || !testCreateList() || !testGetValue()
		|| !testIsEmpty() || !testIsLast() || !testSetValue() || !testMakeACircularList()) {
		printf("!!!the list did not pass the tests!!!\n\n\n");
		return 1;
	}
	if (!testForAdd() || !testForRemove()) {
		printf("!Программа не прошла тесты!\n\n\n");
		return 1;
	}
	int choice = 0;
	Value value = 0;
	List* list = createList();
	do {
		printf("\n\n======\n0 – Выйти\n1 – Добавить значение в сортированный список\n2 – Удалить значение из списка\n3 – Распечатать список\n\n\n");
		printf("Введите ваш выбор: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 0:
			printf("Вы вышли из программы\n");
			break;
		case 1:
			printf("Введите значение, которое хотите добавить: ");
			scanf_s("%d", &value);
			addElements(value, list);
			break;
		case 2:
			printf("Введите значение, которое хотите удалить: ");
			scanf_s("%d", &value);
			removeElement(value, list);
			break;
		case 3:
			printList(list);
			break;
		default:
			printf("Неправильный ввод\n");
		}
	} while (choice != 0);
}
