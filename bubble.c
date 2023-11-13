#include<stdio.h>
int count=0;
void main()
{
int i,j,n,temp;
printf("Enter the number of elements: ");
scanf("%d",&n);
int a[n];
printf("Enter the elements: ");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
count+=2;
}
count++;
for(i=0;i<n-1;i++)
{
count++;
for(j=0;j<n-i-1;j++)
{
count;
if(a[j]>a[j+1])
{
count++;
temp=a[j+1];
a[j+1]=a[j];
a[j]=temp;
}

}
count++;
}
count++;
printf("Sorted Array: ");
for(i=0;i<n;i++)
{
printf("%d,",a[i]);
count+=2;
}
count++;
printf("\n");
count+=2;
printf("Time Complexity:%d\n",count);
printf("Space Complexity:%d",16+4*n);
}
