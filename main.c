#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef struct {
    float key;
} data;

void shell_sort(data arr[], int n) {
    int step;
    data temp;
    step = n / 2;
    while (step > 0) {
        for (int i = 0; i < n - step; i++) {
            for (int j = i; j >= 0; j = j - step) {
                if (arr[j].key > arr[j + step].key) {
                    temp = arr[j];
                    arr[j] = arr[j + step];
                    arr[j + step] = temp;
                }
            }
        }
        step = step / 2;
    }
}


int binary_search(data arr[], int n, float value) {
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid].key == value) {
            return mid;
        } else if (arr[mid].key < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    FILE *file;
    data table[100000]; // тут было table[100]
    int i = 0;
    float key;
    int answer;
    int count;

    file = fopen("sorted_array.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл с отсортированной таблицей\n");
        return 1;
    }
    while (i < 100 && fscanf(file, "%f", &table[i].key) == 1) {
        i++;
    }
    fclose(file);

    if (i < 15) {
        printf("Недостаточно чисел в файле с отсортированной таблицей\n");
        return 1;
    }
    if (i > 100000) {
        printf("Чисел должно быть не больше 100000");
        return 1;
    }

    printf("Прочитано %d чисел:\n", i);

    printf("Отсортированная таблица до сортировки:\n");
    for (int j = 0; j < i; j++) {
        printf("%f ", table[j].key);
    }
    printf("\n \n");

    shell_sort(table, i);
    printf("Отсортированная таблица после сортировки:\n");
    for (int j = 0; j < i; j++) {
        printf("%f ", table[j].key);
    }
    printf("\n \n");

    
    file = fopen("keys.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл с ключами\n");
        return 1;
    }
    

    printf("Результаты поиска ключей в этой таблице:\n");
    while (fscanf(file, "%f", &key) == 1) { 
        answer = binary_search(table, i, key);
        printf("Index: %d, value: %f\n", answer, key);
    }
    fclose(file);
    printf("\n");

    i = 0;
    file = fopen("sorted_reverse_array.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл с таблицей, элементы которой расставлены в обратном порядке\n");
        return 1;
    }
    while (i < 100 && fscanf(file, "%f", &table[i].key) == 1) {
        i++;
    }
    fclose(file);

    if (i < 15) {
        printf("Недостаточно чисел в файле с таблицей, элементы которой расставлены в обратном порядке\n");
        return 1;
    }
    if (i > 100000) {
        printf("Чисел должно быть не больше 100000");
        return 1;
    }

    printf("Прочитано %d чисел:\n", i);

    printf("таблица, элементы которой расставлены в обратном порядке:\n");
    for (int j = 0; j < i; j++) {
        printf("%f ", table[j].key);
    }
    printf("\n \n");

    shell_sort(table, i);
    printf("таблица, элементы которой расставлены в обратном порядке, после сортировки:\n");
    for (int j = 0; j < i; j++) {
        printf("%f ", table[j].key);
    }
    printf("\n \n");

    
    file = fopen("keys.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл с ключами\n");
        return 1;
    }
    

    printf("Результаты поиска ключей в этой таблице:\n");
    while (fscanf(file, "%f", &key) == 1) { 
        answer = binary_search(table, i, key);
        printf("Index: %d, value: %f\n", answer, key);
    }
    fclose(file);
    printf("\n");
    i = 0;


    srand(time(NULL));
    printf("Введите количество чисел для генерации (не менее 15): ");
    scanf("%d", &count);
    
    for (int j = 0; j < count && j < 100000; j++) { //тут было j < 100
        float random_number = (float)(rand());
        table[j].key = random_number;
    }
    i = count;
    printf("\n");
    if (i < 15) {
        printf("Число должно быть больше 15\n");
        return 1;
    }
    if (i > 100000) {
        printf("Число должно быть не больше 100000\n");
        return 1;
    }

    printf("Прочитано %d чисел:\n", i);

    printf("Таблица до сортировки:\n");
    for (int j = 0; j < i; j++) {
        printf("%f ", table[j].key);
    }
    printf("\n \n");

    shell_sort(table, i);
    printf("Таблица после сортировки:\n");
    for (int j = 0; j < i; j++) {
        printf("%f ", table[j].key);
    }
    printf("\n \n");

    
    file = fopen("keys.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл с ключами\n");
        return 1;
    }
    

    printf("Результаты поиска ключей в этой таблице:\n");
    while (fscanf(file, "%f", &key) == 1) { 
        answer = binary_search(table, i, key);
        printf("Index: %d, value: %f\n", answer, key);
    }
    fclose(file);
    printf("\n");
    return 0;
}