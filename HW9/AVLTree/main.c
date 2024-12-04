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
        printf("1-�������� �������� �� ��������� ����� � �������\n");
        printf("2-�������� �������� �� ��������� ����� �� �������\n");
        printf("3-��������� ������� ��������� �����\n");
        printf("4-������� �������� ���� � ��������� � ��� �������� �� �������\n");
        printf("5-�����\n");

        printf("\n��� �����: ");
        scanf_s("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case(1):
            while (getchar() != '\n');
            printf("������� ����: ");
            fgets(key, 100, stdin);
            key[strcspn(key, "\n")] = '\0';
            printf("������� ��������: ");
            fgets(value, 100, stdin);
            value[strcspn(value, "\n")] = '\0';
            printf("\n\n");
            root = add(root, key, value);
            break;
        case(2):
            if (isEmpty(root)) {
                printf("������� ���� :(\n\n");
                break;
            }
            else {
                while (getchar() != '\n');
                printf("������� ���� ");
                fgets(key, 100, stdin);
                key[strcspn(key, "\n")] = '\0';
                const char* output = getValue(root, key);
                if (output != NULL) {
                    printf("%s\n\n\n", output);
                    break;
                }
                else {
                    printf("�������� �� ����� '%s' �� �������\n", key);
                    break;
                }
            }
        case(3):
            if (isEmpty(root)) {
                printf("������� ���� :(\n\n");
                break;
            }
            while (getchar() != '\n');
            printf("������� ����: ");
            fgets(key, 100, stdin);
            key[strcspn(key, "\n")] = '\0';
            if (checkTheKey(root, key)) {
                printf("�������� � ����� ������ ���� � �������\n\n");
            }
            else {
                printf("�������� � ����� ������ �����������\n\n");
            }
            break;
        case(4):
            if (isEmpty(root)) {
                printf("������� ���� :(\n\n");
                break;
            }
            else {
                while (getchar() != '\n');
                printf("������� ����: ");
                fgets(key, 100, stdin);
                key[strcspn(key, "\n")] = '\0';
                if (!checkTheKey(root, key)) {
                    printf("������� � ����� ������ �����������\n\n");
                    break;
                }
                else {
                    root = deleteNode(root, key);
                    printf("������� ������� ����� ^_^\n\n");
                    break;
                }
            }
        case(5):
            printf("����� �� ���������...\n\n\n");
            break;
        case(7):
            printTree(root, getHeight(root));
            break;
        default:
            printf("�������� ����:(\n");
            break;
        }
    } while (choice != 5);

    freeTree(root);
}