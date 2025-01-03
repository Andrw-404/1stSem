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
    printf("\nВведите количество воинов: ");
    scanf_s("%d", &n);
    printf("\n");
    printf("Введите интервал, через который удаляется каждый следующий участник в кругу: ");
    scanf_s("%d", &m);

    int k = reckoning(n, m);

    printf("\nНомер начальной позиции воина, который должен будет остаться последним: %d\n\n", k);
}