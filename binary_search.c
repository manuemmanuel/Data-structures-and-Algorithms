#include <stdio.h>
int search(int array[], int m, int n);
int search(int array[], int m, int n) {
    int high, low, middle;
    high = n - 1;
    low = 0;
    while (low <= high) {
        middle = (low + high) / 2;
        if (array[middle] == m) {
            return 1;
        } else if (array[middle] < m) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }
    return 0;
}
void main() {
    int n, m,temp;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    for ( int i = 0;i < n;i++){
        if (array[i] < array[i+1]){
            temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
        }
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &m);
    int result = search(array, m, n);
    if (result == 1) {
        printf("The value is present\n");
    } 
    else {
        printf("The value is absent\n");
    }
}      

