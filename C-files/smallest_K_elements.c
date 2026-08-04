#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}


void quickSelect(int arr[], int low, int high, int k) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k)
            return;
        else if (pivotIndex > k)
            quickSelect(arr, low, pivotIndex - 1, k);
        else
            quickSelect(arr, pivotIndex + 1, high, k);
    }
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter K: ");
    scanf("%d", &k);

    if (k <= 0 || k > n) {
        printf("Invalid value of K\n");
        return 0;
    }

    
    quickSelect(arr, 0, n - 1, k - 1);

    printf("\nSmallest %d elements :\n", k);

    for (int i = 0; i < k; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
