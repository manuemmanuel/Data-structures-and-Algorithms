#include <stdio.h>
int search(int array[],int searchterm, int n);
int search(int array[],int searchterm, int n){
    int low = 0, high = n-1;
    while (low <= high){
        int middle = (low + high)/2;
        if (array[middle] == searchterm){
            return 1;
        }
        else if (array[middle] < searchterm){
            low = middle + 1;
        }
        else {
            high = middle - 1;
        }
    }
    return 0;

}
void main(){
    int n,temp;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("The sorted array: ");
    for (int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    int searchterm;
    printf("Enter the element to be searched: ");
    scanf("%d",&searchterm);
    int result = search(a,searchterm,n);
    if (result == 1){
        printf("The element is found");
    }
    else {
        printf("The element is not found");
    }

}
