#include "parsingTree.h"
#include "test.h"

#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "RUS");
    if (!test()) {
        printf("Test failed\n\n");
        return -999;
    }
    int errorCode = 0;
    FILE* file = fopen("fileForTask.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл\n\n");
        return -3;
    }

    Node* root = expressionParse(file, &errorCode);
    if (!verify(&errorCode)) {
        fclose(file);
        return -3;
    }
    fclose(file);
    if (root == NULL) {
        printf("Ошибка при парсинге\n\n");
        return -4;
    }
    printTree(root);

    int result = calculate(root, &errorCode);
    if (!verify(&errorCode)) {
        freeTree(root);
        return -1;
    }
    printf("\nРезультат равен: %d\n\n", result);
    freeTree(root);
}