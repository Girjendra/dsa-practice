#include<stdio.h>
#include<stdlib.h>
void printarray(int size, int* arr) {
    int i;
    printf("Array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionsort(int size, int* arr) {
    int i;
    for(i = 1; i < size; i++ ) {
        int index = i;
        if(arr[index] < arr[index - 1]) {
            while(arr[index] < arr[index - 1] && index >= 1) {
                int temp = arr[index];
                arr[index] = arr[index - 1];
                arr[index - 1] = temp;
                index--;
            }
        }
    }
}

void createsortedarray(int size, int* arr) {
    int i;
    printf("Enter the elements of array:\n");
    for(i = 0; i < size; i++) {
        printf("Element: ");
        scanf("%d" ,&arr[i]);
        insertionsort(i + 1, arr);
        printarray(i + 1, arr);
    }
}

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(sizeof(int)*size);
    createsortedarray(size, arr);

    printf("Fully sorted Array:\n");
    printarray(size, arr);

    return 0;
}