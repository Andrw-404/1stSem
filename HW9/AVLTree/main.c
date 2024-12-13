#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "AVLTree.h"

int main(void) {
    setlocale(LC_ALL, "RUS");
    Node* root = NULL;
    int choice = 0;
    char key[100] = "";
    char value[100] = "";
    do {
        printf("1-Добавить значение по заданному ключу в словарь\n");
        printf("2-Получить значение по заданному ключу из словаря\n");
        printf("3-Проверить наличие заданного ключа\n");
        printf("4-Удалить заданный ключ и связанное с ним значение из словаря\n");
        printf("5-Выйти\n");

        printf("\nВаш выбор: ");
        scanf_s("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case(1):
            while (getchar() != '\n');
            printf("Введите ключ: ");
            fgets(key, 100, stdin);
            key[strcspn(key, "\n")] = '\0';
            printf("Введите значение: ");
            fgets(value, 100, stdin);
            value[strcspn(value, "\n")] = '\0';
            printf("\n\n");
            root = add(root, key, value);
            break;
        case(2):
            if (isEmpty(root)) {
                printf("Словарь пуст :(\n\n");
                break;
            }
            else {
                while (getchar() != '\n');
                printf("Введите ключ ");
                fgets(key, 100, stdin);
                key[strcspn(key, "\n")] = '\0';
                const char* output = getValue(root, key);
                if (output != NULL) {
                    printf("%s\n\n\n", output);
                    break;
                }
                else {
                    printf("Значение по ключу '%s' не найдено\n", key);
                    break;
                }
            }
        case(3):
            if (isEmpty(root)) {
                printf("Словарь пуст :(\n\n");
                break;
            }
            while (getchar() != '\n');
            printf("Введите ключ: ");
            fgets(key, 100, stdin);
            key[strcspn(key, "\n")] = '\0';
            if (checkTheKey(root, key)) {
                printf("Значение с таким ключом есть в словаре\n\n");
            }
            else {
                printf("Значение с таким ключом отсутствует\n\n");
            }
            break;
        case(4):
            if (isEmpty(root)) {
                printf("Словарь пуст :(\n\n");
                break;
            }
            else {
                while (getchar() != '\n');
                printf("Введите ключ: ");
                fgets(key, 100, stdin);
                key[strcspn(key, "\n")] = '\0';
                if (!checkTheKey(root, key)) {
                    printf("Элемент с таким ключом отсутствует\n\n");
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
        case(7):
            printTree(root, getHeight(root));
            break;
        default:
            printf("Неверный ввод:(\n");
            break;
        }
    } while (choice != 5);

    freeTree(root);
}