#include<stdio.h>
void main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int array[n];
    printf("Enter the elements: ");
    for (int i = 1; i <= n; i++){
        scanf("%d",&array[i]);
    }
    int k = 0;
    while (k == 0){
        printf("Enter any node: ");
        int node;
        scanf("%d",&node);
        if (node <= 1){
            printf("This is the root node.\n");
        }
        else if (node > 1){
            printf("The parent node is %d and the value at the node is %d\n",node/2,array[node/2]);
            if (((2*node)+1 > n) && (2*node > n)){
                printf("This node has no child\n");
            }
            else if ((2*node)+1 > n){
                printf("This node has no right child.\n");
            }
            else if (2*node > n){
                printf("This node has no left child.\n");
            }
            else {
                printf("The right child node is %d and the value at the node is %d\n",(2*node)+1,array[(2*node)+1]);
                printf("The left child of the node is %d and the value at the node is %d\n",2*node,array[2*node]);
            }
        }
    }
}
