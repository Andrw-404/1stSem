#include "tree.h"
#include "tests.h"

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void) {
    setlocale(LC_ALL, "RUS");
    if (!runTests()) {
        return 4;
    }
    Node* mainNode = NULL;
    int choice = 0;
    int key = 0;
    char value[100] = "";
    do {
        printf("1-�������� ����� �������\n");
        printf("2-�������� �������� �� �����\n");
        printf("3-��������� ������� �������� �� �����\n");
        printf("4-������� ��������\n");
        printf("5-�����\n");

        printf("\n��� �����: ");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
            printf("������� ����: ");
            scanf("%d", &key);
            while (getchar() != '\n');
            printf("������� ��������: ");
            fgets(value, 100, stdin);
            value[strcspn(value, "\n")] = '\0';
            printf("\n\n");
            mainNode = add(mainNode, key, value);
            break;
        case 2:
            if (isEmpty(mainNode)) {
                printf("������ ������ :(\n\n");
                break;
            }
            else {
                printf("������� ����: ");
                scanf("%d", &key);
                char* output = getValueByKey(mainNode, key);
                if (output != NULL) {
                    printf("%s\n\n\n", output);
                    break;
                }
                else {
                    printf("�������� �� ����� %d �� �������\n\n", key);
                    break;
                }
            }
        case 3:
            if (isEmpty(mainNode)) {
                printf("������ ������ :(\n\n");
                break;
            }
            printf("������� ����: ");
            scanf("%d", &key);
            if (checkTheKey(mainNode, key)) {
                printf("�������, ��������������� ������� ����� ������\n\n");
            }
            else {
                printf("������� ��������������� ������� ����� �� ������\n\n");
            }
            break;
        case 4:
            if (isEmpty(mainNode)) {
                printf("������ ������ :(\n\n");
                break;
            }
            else {
                printf("������� ���� ��������, ������� �� ������ �������: ");
                scanf("%d", &key);
                if (!checkTheKey(mainNode, key)) {
                    printf("������ �������� ���\n\n");
                    break;
                }
                else {
                    mainNode = deleteNode(mainNode, key);
                    printf("������� ������� ����� ^_^\n\n");
                    break;
                }
            }
        case 5:
            printf("����� �� ���������...\n\n\n");
            break;
        default:
            printf("������������ ����:(\n");
            break;
        }
    } while (choice != 5);

    freeTree(mainNode);
}