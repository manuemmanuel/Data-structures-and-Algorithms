#include <stdio.h>
void quicksort(int a[], int low, int high) {
    while (low < high) {
        int pivotIndex = low;
        int storeIndex = pivotIndex + 1;
        for (int i = pivotIndex + 1; i <= high; i++) {
            if (a[i] < a[pivotIndex]) {
                int temp = a[i];
                a[i] = a[storeIndex];
                a[storeIndex] = temp;

                storeIndex++;
            }
        }
        int temp2 = a[pivotIndex];
        a[pivotIndex] = a[storeIndex - 1];
        a[storeIndex - 1] = temp2;
        if (storeIndex - 1 - low < high - storeIndex + 1) {
            high = storeIndex - 2;
        } else {
            low = storeIndex;
        }
    }
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
