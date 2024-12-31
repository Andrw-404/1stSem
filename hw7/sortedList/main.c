#include "testsForList.h"
#include "list.h"
#include "testsForTask.h"

#include <locale.h>
#include <stdio.h>

int main(void) {
	setlocale(LC_ALL, "Rus");
	if (!testAddLast() || !testCreateList() || !testGetValue()
		|| !testIsEmpty() || !testIsLast() || !testSetValue()) {
		printf("!!!the list did not pass the tests!!!\n\n\n");
		return 1;
	}
	if (!testForAdd() || !testForRemove()) {
		printf("!��������� �� ������ �����!\n\n\n");
		return 1;
	}
	int choice = 0;
	Value value = 0;
	List* list = createList();
	do {
		printf("\n\n======\n0 � ����� \n");
		printf("1 � �������� �������� � ������������� ������\n");
		printf("2 � ������� �������� �� ������\n");
		printf("3 � ����������� ������\n");

		printf("\n������� ��� �����: ");
		scanf_s("%d", &choice);
		printf("\n");

		switch (choice) {
		case 0:
			printf("�� ����� �� ���������\n");
			break;
		case 1:
			printf("������� ��������, ������� ������ ��������: ");
			scanf_s("%d", &value);
			addElements(value, list);
			break;
		case 2:
			printf("������� ��������, ������� ������ �������: ");
			scanf_s("%d", &value);
			removeElement(value, list);
			break;
		case 3:
			printList(list);
			break;
		default:
			printf("������������ ����\n");
		}
	} while (choice != 0);
}
