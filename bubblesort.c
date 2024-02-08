#include <stdio.h>
int bubblesort(int array[],int n);
int bubblesort(int array[],int n){
    int temp;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i -1; j++){
            if (array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array: ");
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    bubblesort(a,n);
    printf("The sorted array: ");
    for (int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
}
