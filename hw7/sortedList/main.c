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
		printf("!��������� �� ������ �����!\n\n\n");
		return 1;
	}
	int choice = 0;
	Value value = 0;
	List* list = createList();
	do {
		printf("\n\n======\n0 � �����\n1 � �������� �������� � ������������� ������\n2 � ������� �������� �� ������\n3 � ����������� ������\n\n\n");
		printf("������� ��� �����: ");
		scanf_s("%d", &choice);

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
