#include <stdio.h>
void merge(int a[], int start, int mid, int end) {
    int temp[20];
    int i = start;
    int j = mid + 1;
    int k = start;
    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            temp[k] = a[i];
            i++;
            k++;
        } else {
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= end) {
        temp[k] = a[j];
        j++;
        k++;
    }
    for (int x = start; x <= end; x++) {
        a[x] = temp[x];
    }
}
void mergesort(int a[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergesort(a, start, mid);
        mergesort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[20];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    printf("The sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
