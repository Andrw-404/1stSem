#include "tree.h"
#include "tests.h"

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

void main(void) {
    setlocale(LC_ALL, "RUS");
    if (!runTests()) {
        return;
    }
    Node* root = NULL;
    int choice = 0;
    int key = 0;
    char value[100] = "";
    do {
        printf("1-Добавить новый элемент\n");
        printf("2-Получить значение по ключу\n");
        printf("3-Проверить наличие элемента по ключу\n");
        printf("4-Удалить значение\n");
        printf("5-Выйти\n");

        printf("\nВаш выбор: ");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case(1):
            printf("Введите ключ: ");
            scanf("%d", &key);
            while (getchar() != '\n');
            printf("Введите значение: ");
            fgets(value, 100, stdin);
            value[strcspn(value, "\n")] = '\0';
            printf("\n\n");
            root = add(root, key, value);
            break;
        case(2):
            if (isEmpty(root)) {
                printf("Дерево пустое :(\n\n");
                break;
            }
            else {
                printf("Введите ключ: ");
                scanf("%d", &key);
                char* output = getValue(root, key);
                if (output != NULL) {
                    printf("%s\n\n\n", output);
                    break;
                }
                else {
                    printf("Значение по ключу %d не найдено\n", key);
                    break;
                }
            }
        case(3):
            if (isEmpty(root)) {
                printf("Дерево пустое :(\n\n");
                break;
            }
            printf("Введите ключ: ");
            scanf("%d", &key);
            if (checkTheKey(root, key)) {
                printf("Элемент, соответствующий данному ключу найден\n\n");
            }
            else {
                printf("Элемент соответствующий данному ключу не найден\n\n");
            }
            break;
        case(4):
            if (isEmpty(root)) {
                printf("Дерево пустое :(\n\n");
                break;
            }
            else {
                printf("Введите ключ элемента, который Вы хотите удалить: ");
                scanf("%d", &key);
                if (!checkTheKey(root, key)) {
                    printf("Такого элемента нет\n\n");
                    break;
                }
                else {
                    root = deleteNode(root, key);
                    printf("Элемент успешно удалён ^_^\n\n");
                    break;
                }
            }
        case(5):
            printf("Выход из программы...\n\n\n");
            break;
        default:
            printf("Некорректный ввод:(\n");
            break;
        }
    } while (choice != 5);

    freeTree(root);
}