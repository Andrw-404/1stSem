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
    FILE* file = fopen("fileForTask.txt", "r");
    if (file == NULL) {
        printf("�� ������� ������� ����\n\n");
        return;
    }

    Node* root = expressionParse(file);
    fclose(file);

    printTree(root);

    int result = calculate(root);
    printf("\n��������� �����: %d\n\n", result);
    freeTree(root);
}