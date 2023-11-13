#include <stdio.h>
int count = 0;
int select(int a[],int n);
void main(){
    int i,n,a[50];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++){
        scanf("%d",&a[i]);
        count += 2;
    }
    count ++;
    select(a,n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++){
        printf("%d",a[i]);
        count += 2;
    }
    count ++;
    printf("\n");
    count += 2;
    printf("Time Complexity: %d\n",count);
    printf("Space Complexity: %d\n",24+4*n);
}

int select(int a[], int n){
    int i,j,small,temp;
    for (i = 0; i < n-1; i++){
        count += 3;
        small = i;
        for (j = i+1; j < n;j++){
            count ++;
            if (a[j]<a[small]){
                small = j;
                count += 2;
            }
        }
        count ++;
        temp = a[small];
        a[small] = a[i];
        a[i] = temp;
    }
    count++;
}