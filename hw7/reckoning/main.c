#include "list.h"
#include "testsForList.h"
#include "reckoning.h"

#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

int main(void) {
    setlocale(LC_ALL, "RUS");
    if (!runTests()) {
        return 1;
    }

    List* list = createList();

    int m = 0;
    int n = 0;
    printf("\n������� ���������� ������: ");
    scanf_s("%d", &n);
    printf("\n");
    printf("������� ��������, ����� ������� ��������� ������ ��������� �������� � �����: ");
    scanf_s("%d", &m);
    Position current = first(list);
    for (int i = 1; i <= n; ++i) {
        addLast(list, i);
    }

    int k = reckoning(list, m);

    printf("\n����� ��������� ������� �����, ������� ������ ����� �������� ���������: %d\n\n", k);
    removeList(list);
}