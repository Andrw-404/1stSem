#include "list.h"
#include "testsForList.h"
#include "reckoning.h"

#include <locale.h>
#include <stdio.h>

int main(void) {
    setlocale(LC_ALL, "RUS");
    if (!testAdd() || !testAddLast() || !testCreateList() || !testGetValue()
        || !testIsEmpty() || !testIsLast() || !testSetValue() || !testMakeACircularList()) {
        printf("!!!the list did not pass the tests!!!\n\n\n");
        return NULL;
    }

    List* list = createList();
    
    int m = 0;
    int n = 0;
    printf("\nВведите количество воинов: ");
    scanf_s("%d", &n);
    printf("\n");
    printf("Введите интервал, через который удаляется каждый следующий участник в кругу: ");
    scanf_s("%d", &m);
    for (int i = 1; i <= n; ++i) {
        addLast(list, i);
    }
    
    makeACircularList(list);
    int k = reckoning(list, m);

    printf("\nНомер начальной позиции воина, который должен будет остаться последним: %d\n\n", k);

}