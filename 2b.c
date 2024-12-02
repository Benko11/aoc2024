#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, size_t length);
int is_safe(int *arr, size_t length);
int* remove_item(int *arr, size_t length, int n);
int is_actually_safe(int *arr, size_t length);

int main() {
    FILE *file = fopen("2list.txt", "r");

    char c;
    int n = 0;
    int numbers[1000];
    int current_index = 0;
    int safe_count = 0;

    while ((c = getc(file))) {
        if (c == ' ' || c == '\n' || c == EOF) {
            numbers[current_index++] = n;
            n = 0;

            if (c == '\n' || c == EOF) {
                if (is_actually_safe(numbers, current_index) == 1) {
                    safe_count++;
                }

                if (c == EOF) break;
                current_index = 0;
            }
        }

        if ('0' <= c && c <= '9') {
            n = n * 10 + (c - 48);
        }
    }

    printf("%d\n", safe_count);

    fclose(file);
    return EXIT_SUCCESS;
}

int is_safe(int *arr, size_t length) {
    int DEC = 0;

    for (int i = 0; i < length - 1; i++) {
        int a = arr[i], b = arr[i + 1];
        int diff = a - b;
        if (DEC == 0) DEC = diff > 0 ? 1 : -1;

        if (diff == 0) return 0;
        if (DEC == 1 && diff < 0) return 0;
        if (DEC == -1 && diff > 0) return 0;

        diff = DEC == -1 ? -diff : diff;

        if (diff > 3) return 0;
    }

    return 1;
}

int is_actually_safe(int *arr, size_t length) {
    if (is_safe(arr, length) == 1) return 1;

    for (int i = 0; i < length; i++) {
        int *x = remove_item(arr, length, i);
        if (is_safe(x, length - 1)) return 1; 
    }

    return 0;
}

void print_array(int *arr, size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* remove_item(int *arr, size_t length, int n) {
    int *new_array = malloc(sizeof(int) * (length - 1));
    int *ptr = new_array;
    for (int i = 0; i < length; i++) {
        if (i == n) continue;

        *ptr = arr[i];
        ptr++;
    }
    return new_array;
}