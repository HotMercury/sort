#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TEST_NUM 10

void quick_sort(int *arr, int left, int right) {
    if (right <= left) {
        return;
    }
    int pivot = arr[left];
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while (i <= right && arr[i] < pivot) {
            i++;
        }
        while (j >= left + 1 && arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    arr[left] = arr[j];
    arr[j] = pivot;

    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}

int main() {
    srand(time(NULL));
    int arr[TEST_NUM];
    for(int i = 0; i < TEST_NUM; i++){
        arr[i] = rand();
    }
    quick_sort(arr, 0, TEST_NUM-1);
    for(int i = 0; i < TEST_NUM; i++){
        printf("%d ",arr[i]);
    }
}
