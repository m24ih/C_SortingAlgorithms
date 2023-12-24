#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    clock_t codeStart,codeEnd, firstArrayS,firstArrayF, secondArrayS,secondArrayF, thirdArrayS,thirdArrayF;
    codeStart= clock();
    int i;
    int *arr_a, *arr_b, *arr_c;

    // Generate random arrays
    srand((unsigned int)time(0));

    //for 10000 item
    int n = 10000;
    arr_a = (int*)malloc(n * sizeof(int));
    if (arr_a == NULL) {
        printf("Failed to memoral allocation(malloc)\n");
        return -1;
    }
    firstArrayS = clock();
    for (i = 0; i < n; i++) {
        arr_a[i] = rand() % 9999 + 1;
    }
    bubbleSort(arr_a, 10000);

    printf("Sorted array of 10000 integers: \n");
    for (i = 0; i < 10000; i++) {
        printf("%d\t ", arr_a[i]);
    }
    printf("\n---------------\n");
    firstArrayF = clock();
    
    free(arr_a);

    double firstTimeSpent = (double)(firstArrayF - firstArrayS ) / CLOCKS_PER_SEC;
    printf("First Sorting completed at: %lf second\n", firstTimeSpent);
    printf("---------------\n");

    //for 100000 item
    n = 100000;
    arr_b = (int*)malloc(n * sizeof(int)); 
    if (arr_b == NULL) {
        printf("Failed to memoral allocation(malloc)\n");
        return -1;
    }
    secondArrayS = clock();
    for (i = 0; i < n; i++) {
        arr_b[i] = rand() % 9999 + 1;
    }

    bubbleSort(arr_b, 100000);

    printf("\nSorted array of 100000 integers: \n");
    for (i = 0; i < 100000; i++) {
        printf("%d\t ", arr_b[i]);
    }
    printf("\n----------------\n");
    secondArrayF = clock();

    free(arr_b);

    double secondTimeSpent = (double)(secondArrayF - secondArrayS) / CLOCKS_PER_SEC;
    printf("Second Sorting completed at: %lf second\n", secondTimeSpent);
    printf("---------------\n");


    //for 1000000 item
    n = 1000000; 
    arr_c = (int*)malloc(n * sizeof(int)); 
    if (arr_c == NULL) {
        printf("Failed to memoral allocation(malloc)\n");
        return -1;
    }
    thirdArrayS = clock();
    for (i = 0; i < n; i++) {
        arr_c[i] = rand() % 9999 + 1;
    }

    bubbleSort(arr_c, 1000000);

    printf("\nSorted array of 1000000 integers: \n");
    for (i = 0; i < 1000000; i++) {
        printf("%d\t ", arr_c[i]);
    }
    printf("\n----------------\n");
    thirdArrayF = clock();
    
    free(arr_c);

    double thirdTimeSpent = (double)(thirdArrayF - thirdArrayS) / CLOCKS_PER_SEC;
    printf("Third Sorting completed at: %lf second\n", thirdTimeSpent);
    printf("---------------\n");

    codeEnd = clock();

    double timeSpent = (double)(codeEnd - codeStart) / CLOCKS_PER_SEC;
    printf("Sorting completed at: %lf second\n", timeSpent);

    return 0;
}
