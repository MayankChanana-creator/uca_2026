#include <stdio.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int size;
} heap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUpMax(heap *h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (h->arr[parent] >= h->arr[i]) {
            break;
        }

        swap(&h->arr[parent], &h->arr[i]);

        i = parent;
    }
}

void insertMax(heap *h, int value) {
    h->arr[h->size] = value;
    h->size++;

    heapifyUpMax(h, h->size - 1);
}

void heapifyDownMax(heap *h, int i) {
    while (1) {
        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < h->size &&
            h->arr[left] > h->arr[largest]) {
            largest = left;
        }

        if (right < h->size &&
            h->arr[right] > h->arr[largest]) {
            largest = right;
        }

        if (largest == i) {
            break;
        }

        swap(&h->arr[largest], &h->arr[i]);

        i = largest;
    }
}

int extractMax(heap *h) {
    int result = h->arr[0];

    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    if (h->size > 0) {
        heapifyDownMax(h, 0);
    }

    return result;
}

void heapifyUpMin(heap *h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (h->arr[parent] <= h->arr[i]) {
            break;
        }

        swap(&h->arr[parent], &h->arr[i]);

        i = parent;
    }
}

void insertMin(heap *h, int value) {
    h->arr[h->size] = value;
    h->size++;

    heapifyUpMin(h, h->size - 1);
}

void heapifyDownMin(heap *h, int i) {
    while (1) {
        int smallest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < h->size &&
            h->arr[left] < h->arr[smallest]) {
            smallest = left;
        }

        if (right < h->size &&
            h->arr[right] < h->arr[smallest]) {
            smallest = right;
        }

        if (smallest == i) {
            break;
        }

        swap(&h->arr[smallest], &h->arr[i]);

        i = smallest;
    }
}

int extractMin(heap *h) {
    int result = h->arr[0];

    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    if (h->size > 0) {
        heapifyDownMin(h, 0);
    }

    return result;
}

void insert(heap *maxHeap, heap *minHeap, int num) {
    if (maxHeap->size == 0 ||
        num <= maxHeap->arr[0]) {

        insertMax(maxHeap, num);
    }
    else {
        insertMin(minHeap, num);
    }
    if (maxHeap->size > minHeap->size + 1) {

        int x = extractMax(maxHeap);

        insertMin(minHeap, x);
    }

    else if (minHeap->size > maxHeap->size + 1) {

        int x = extractMin(minHeap);

        insertMax(maxHeap, x);
    }
}

double getMedian(heap *maxHeap, heap *minHeap) {
    if (maxHeap->size > minHeap->size) {
        return maxHeap->arr[0];
    }

    else if (minHeap->size > maxHeap->size) {
        return minHeap->arr[0];
    }

    else {
        return ((double)maxHeap->arr[0] +
                minHeap->arr[0]) / 2.0;
    }
}

int main() {

    heap maxHeap = {.size = 0};
    heap minHeap = {.size = 0};

    int stream[] = {5, 2, 10, 4};

    int n = 4;

    for (int i = 0; i < n; i++) {

        insert(&maxHeap, &minHeap, stream[i]);

        printf("Inserted: %d\n", stream[i]);
        printf("Median: %.2f\n\n",
               getMedian(&maxHeap, &minHeap));
    }

    return 0;
}
