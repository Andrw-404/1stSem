#include <stdio.h>
#include <locale.h>

int counterOfZero(int array[], int size) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            counter++;
        }
    }
    return counter;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int array[] = { 0,1,0,2 };
    int size = sizeof(array) / sizeof(array[0]);
    int c = counterOfZero(array, size);
    printf("Количество нулевых элементов в массиве: %d\nThe numbers of zero elements in the array: %d\n", c, c);
    return 0;
}