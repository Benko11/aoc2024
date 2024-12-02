#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, size_t length);
void swap(int *a, int m, int n);
void print_array(int *arr, size_t length);

int main(void) {
    FILE *file = fopen("1list.txt", "r");
    if (file == NULL) {
        exit(EXIT_FAILURE);
    }
    
    size_t line_count = 0;
    char c;
    while ((c = getc(file)) != EOF) {
        if (c == '\n') line_count++;
    }
    rewind(file);

    int n = 0;
    int *l = malloc(sizeof(int) * line_count), *r = malloc(sizeof(int) * line_count);
    int i = 0;
    int IGNORE_N = 0;
    while ((c = getc(file)) != EOF) {
        if (IGNORE_N == 1 && n != 0) {
            n = 0;
        }

        if ('0' <= c && c <= '9') {
            IGNORE_N = 0;
            n = n * 10 + (c - 48);
        } else {
            if (c == ' ' && IGNORE_N == 0) {
                IGNORE_N = 1;
                l[i] = n; 
            }
            
            if (c == '\n') {
                r[i] = n;
                n = 0;
                i++;
            }
        }
    }

    fclose(file);

    bubble_sort(l, line_count);
    bubble_sort(r, line_count);

    int sum = 0;
    for (int i = 0; i < line_count; i++) {
        sum += r[i] - l[i] > 0 ? r[i] - l[i] : l[i] - r[i];
    }

    printf("%d\n", sum);

    print_array(l, line_count);
    print_array(r, line_count);

    free(l);
    free(r);
    
    return EXIT_SUCCESS;
}

void bubble_sort(int *a, size_t length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 1; j < length - i; j++) {
            if (a[j - 1] > a[j]) swap(a, j - 1, j);
        }
    }
}

void swap(int *a, int m, int n) {
    int temp = a[m];
    a[m] = a[n];
    a[n] = temp;
}

void print_array(int *arr, size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}