#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define maxPersons 100
#define maxNameLength 35
#define maxPhoneLength 15

typedef struct {
    char name[maxNameLength];
    char phone[maxPhoneLength];
} Person;

void loadPhoneDirectory(Person phoneDirectory[], int* count) {
    FILE* file = fopen("contactDatabase.txt", "r");
    if (file == NULL) {
        perror("contactDatabase.txt");
        *count = 0;
        return;
    }

    while (fscanf(file, "%35s %15s", phoneDirectory[*count].phone, phoneDirectory[*count].name) == 2) {
        (*count)++;
    }
    fclose(file);
}

void savePhoneDirectory(Person phoneDirectory[], int count) {
    FILE* file = fopen("contactDatabase.txt", "w");
    if (file == NULL) {
        perror("contactDatabase.txt");
        return;
    }

    for (int i = 0; i < count; ++i) {
        fprintf(file, "%s\n%s\n", phoneDirectory[i].name, phoneDirectory[i].phone);
    }

    fclose(file);
    printf("\nДанные успешно сохранены\n\n");
}

void addPerson(Person phoneDirectory[], int* count, char* phone, char* name) {
    if (*count >= maxPersons) {
        printf("Нет места в телефонном справочнике\n");
        return;
    }

    strncpy(phoneDirectory[*count].name, name, maxNameLength);
    strncpy(phoneDirectory[*count].phone, phone, maxPhoneLength);
    ++(*count);
}

void printAllPerson(Person phoneDirectory[], int count) {
    if (count == 0) {
        printf("\nСправочник пуст\n\n");
        return;
    }
 
    for (int i = 0; i < count; ++i) {
        printf("%d. Имя: %s, Номер: %s\n", i + 1, phoneDirectory[i].name, phoneDirectory[i].phone);
    }
    
}

char* findPhone(Person phoneDirectory[], int count, char* name) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(phoneDirectory[i].name, name) == 0) {
            return phoneDirectory[i].phone;
        }
    }
    return NULL;
}

char* findName(Person phoneDirectory[], int count, char* phone) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(phoneDirectory[i].phone, phone) == 0)
            return phoneDirectory[i].name;
    }
    return NULL;
}

bool testAddPerson() {
    Person phoneDirectory[maxPersons];
    int count = 0;

    addPerson(phoneDirectory, &count, "1234567", "Andrey");
    if (count != 1 || strcmp(phoneDirectory[0].name, "Andrey") != 0 || strcmp(phoneDirectory[0].phone, "1234567") != 0) {
        return false;
    }
    return true;
}

bool testFindPhone() {
    Person phoneDirectory[maxPersons];
    int count = 0;

    addPerson(phoneDirectory, &count, "1234567", "Andrey");
    char* expectedPhone = "1234567";
    if (strcmp(findPhone(phoneDirectory, count, "Andrey"), expectedPhone) != 0) {
        return false;
    }
    return true;
}

bool testFindName() {
    Person phoneDirectory[maxPersons];
    int count = 0;

    addPerson(phoneDirectory, &count, "1234567", "Andrey");
    char* expectedName = "Andrey";
    if (strcmp(findName(phoneDirectory, count, "1234567"), expectedName) != 0) {
        return false;
    }
    return true;
}

int main(void) {
    
    setlocale(LC_ALL, "RUS");
    if (!testAddPerson() || !testFindPhone() || !testFindName()) {
        printf("!Тесты не пройдены!");
        return 1;
    }
    Person phoneDirectory[maxPersons];
    char name[maxNameLength];
    char phone[maxPhoneLength];
    int count = 0;
    int choice = 0;
    loadPhoneDirectory(phoneDirectory, &count);

    do {
        printf("\n\n===Меню===\n");
        printf("0 - выйти\n");
        printf("1 - добавить запись (имя и телефон)\n");
        printf("2 - распечатать все имеющиеся записи\n");
        printf("3 - найти телефон по имени\n");
        printf("4 - найти имя по телефону\n");
        printf("5 - сохранить текущие данные в файл\n");
        printf("\nВыберите операцию: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 0:
            printf("Вы вышли из программы\n");
            break;
        case 1:
            printf("Введите имя: ");
            scanf_s("%s", name, maxNameLength);
            printf("Введите номер: ");
            scanf_s("%s", phone, maxPhoneLength);
            addPerson(phoneDirectory, &count, phone, name);
            break;
        case 2:
            printAllPerson(phoneDirectory, count);
            break;
        case 3:
            printf("Введите имя: ");
            scanf_s("%s", name, maxNameLength);
            char* foundPhone = findPhone(phoneDirectory, count, name);
            if (foundPhone != NULL) {
                printf("Номер: %s", foundPhone);
            }
            else {
                printf("\nНомер контакта \"%s\" не найден\n\n", name);
            }
            break;
        case 4:
            printf("Введите номер: ");
            scanf_s("%s", phone, maxPhoneLength);
            char* foundName = findName(phoneDirectory, count, &phone);
            if (foundName != NULL) {
                printf("Имя: %s", foundName);
            }
            else {
                printf("\nИмя контакта с номером \"%s\" не найдено\n\n", phone);
            }
            break;
        case 5:
            savePhoneDirectory(phoneDirectory, count);
            break;
        default:
            printf("Неправильный ввод\n");
        }
    } while (choice != 0);
}