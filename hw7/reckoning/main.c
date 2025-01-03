#include "list.h"
#include "testsForList.h"
#include "testForTask.h"
#include "reckoning.h"

#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

int main(void) {
    setlocale(LC_ALL, "RUS");
    if (!createCircularListTest()) {
        printf("The test for the list failed\n\n");
        return 1;
    }
    
    if (!reckoningTest()) {
        printf("The main function failed the test\n\n");
        return 2;
    }

    int m = 0;
    int n = 0;
    printf("\n������� ���������� ������: ");
    scanf_s("%d", &n);
    printf("\n");
    printf("������� ��������, ����� ������� ��������� ������ ��������� �������� � �����: ");
    scanf_s("%d", &m);

    int k = reckoning(n, m);

    printf("\n����� ��������� ������� �����, ������� ������ ����� �������� ���������: %d\n\n", k);
}