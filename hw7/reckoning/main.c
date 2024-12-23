#include "list.h"
#include "testsForList.h"
#include "reckoning.h"

#include <locale.h>
#include <stdio.h>

int main(void) {
    setlocale(LC_ALL, "RUS");
    if (!runTests()) {
        return 1;
    }
    int errrorCode = 0;

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
   
    int k = reckoning(list, m, &errrorCode);
    if (errrorCode != 0) {
        removeList(list);
    }

    printf("\n����� ��������� ������� �����, ������� ������ ����� �������� ���������: %d\n\n", k);
    removeList(list);
}