#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\\n");
}

int main() {
    clock_t start = clock();
    int i;
    int arr_a[1000], arr_b[10000], arr_c[100000];
    
    srand(time(0));
    for (i = 0; i < 1000; i++) {
        arr_a[i] = rand() % 9999 + 1;
    }
    for (i = 0; i < 10000; i++) {
        arr_b[i] = rand() % 9999 + 1;
    }
    for (i = 0; i < 100000; i++) {
        arr_c[i] = rand() % 9999 + 1;
    }

    selectionSort(arr_a, 1000);
    selectionSort(arr_b, 10000);
    selectionSort(arr_c, 100000);

    printf("Sorted array of 1000 integers: \n");
    for (i = 0; i < 1000; i++) {
        printf("%d\t ", arr_a[i]);
    }
    printf("---------------\n");

    printf("\nSorted array of 10000 integers: \n");
    for (i = 0; i < 10000; i++) {
        printf("%d\t ", arr_b[i]);
    }
    printf("----------------\n");

    printf("\nSorted array of 100000 integers: \n");
    for (i = 0; i < 100000; i++) {
        printf("%d\t ", arr_c[i]);
    }
    printf("----------------\n");
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorting completed at: %lf second\n", time_spent);

    return 0;
}