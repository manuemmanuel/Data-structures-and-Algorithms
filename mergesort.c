#include <stdio.h>
int merge(int a[],int start,int mid,int end);
int mergesort(int a[],int start,int end);
int mergesort(int a[],int start,int end){
    if (start < end){
        int mid = (start+end)/2;
        mergesort(a,start,mid);
        mergesort(a,mid+1,end);
        merge(a,start,mid,end);
    }
}
int merge(int a[],int start,int mid,int end){
    int temp[20];
    int i = start; 
    int j = mid+1;
    int k = start;
    while(i <= mid && j <= end){
        if (a[i]<a[j]){
            temp[k] = a[i];
            k++;
            i++;
        }
        else {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    if (i <= mid){
        temp[k] = a[i];
        k++;
        i++;
    }
    else if (j <= end){
        temp[k] = a[j];
        k++;
        j++;
    }
    for (int i = start; i <= end; i++){
        a[i] = temp[i];
    }
}
void main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int array[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n;i++){
        scanf("%d",&array[i]);
    }
    mergesort(array,0,n-1);
    printf("The sorted array: ");
    for (int i = 0; i < n; i++){
        printf("%d ",array[i]);
    }
}
