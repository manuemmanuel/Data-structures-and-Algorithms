#include <stdio.h>
void main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int array[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++){
        scanf("%d",&array[i]);
    }
    int i = 1;
    while (i < n){
        int j = i;
        while (j > 0 && array[j]<array[j-1]){
            int temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            j--;
        }
        i++;
    }
    printf("The sorted array: ");
    for (int i = 0; i < n;i++){
        printf("%d ",array[i]);
    }
}
