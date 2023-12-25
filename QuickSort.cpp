#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printSort(int *arr,int x) {
    printf("Sorted array of %d integers: \n",x);
    for (int i = 0; i < x; i++) {
        printf("%d\t ", arr[i]);
    }
    printf("\n---------------\n");
}

int main() {
    //For time calculating
    clock_t codeStart, codeEnd, firstArrayS, firstArrayE, secondArrayS, secondArrayE, thirdArrayS, thirdArrayE;
    codeStart = clock();

    //Array decleration
    int i;
    int *arr_a, *arr_b, *arr_c;

    // Generate randoms
    srand((unsigned int)time(0));

    //for 10000 item
    int n = 10000;
    arr_a = (int*)malloc(n * sizeof(int));//To avoid memory warnings
    if (arr_a == NULL) {
        printf("Failed to memoral allocation(malloc)\n");
        return -1;
    }
    firstArrayS = clock(); //First array time starts 
    //Inserting random numbers to first array
    for (i = 0; i < n; i++) {
        arr_a[i] = rand() % 9999 + 1;
    }
    quickSort(arr_a, 0,9999);
    printSort(arr_a,10000);//Printing first sorted array
    firstArrayE = clock();//First array time ends
    free(arr_a);//To avoid memory warnings
    double firstTimeSpent = (double)(firstArrayE - firstArrayS) / CLOCKS_PER_SEC;//Calculating how much time spent
    printf("First Sorting completed at: %lf second", firstTimeSpent);
    printf("\n---------------\n");

    //for 100000 item
    n = 100000;
    arr_b = (int*)malloc(n * sizeof(int));//To avoid memory warnings
    if (arr_b == NULL) {
        printf("Failed to memoral allocation(malloc)\n");
        return -1;
    }
    secondArrayS = clock();//Second array time starts 
    //Inserting random numbers to second array
    for (i = 0; i < n; i++) {
        arr_b[i] = rand() % 9999 + 1;
    }

    quickSort(arr_b, 0,99999);
    printSort(arr_b, 100000);//Printing second sorted array
    printf("\n----------------\n");
    secondArrayE = clock();//Second array time ends
    free(arr_b);//To avoid memory warnings
    double secondTimeSpent = (double)(secondArrayE - secondArrayS) / CLOCKS_PER_SEC;//Calculating how much time spent
    printf("Second Sorting completed at: %lf second", secondTimeSpent);
    printf("\n---------------\n");


    //for 1000000 item
    n = 1000000;
    arr_c = (int*)malloc(n * sizeof(int));//To avoid memory warnings
    if (arr_c == NULL) {
        printf("Failed to memoral allocation(malloc)\n");
        return -1;
    }
    thirdArrayS = clock();//Third array time starts 
    //Inserting random numbers to third array
    for (i = 0; i < n; i++) {
        arr_c[i] = rand() % 9999 + 1;
    }

    quickSort(arr_c, 0,999999);
    printSort(arr_c,1000000);//Printing third sorted array
    thirdArrayE = clock();//Third array time ends
    free(arr_c);//To avoid memory warning
    double thirdTimeSpent = (double)(thirdArrayE - thirdArrayS) / CLOCKS_PER_SEC;//Calculating how much time spent
    printf("Third Sorting completed at: %lf second", thirdTimeSpent);
    printf("\n---------------\n");

    codeEnd = clock();
    double timeSpent = (double)(codeEnd - codeStart) / CLOCKS_PER_SEC;//Calculating how much time spent for whole code
    printf("Sorting completed at: %lf second\n", timeSpent);

    return 0;
}
