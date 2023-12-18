#include<stdio.h>
void main()
{
	int a[30],lim,i,j,k;
	printf("Enter the limit:\n");
	scanf("%d",&lim);
	printf("Enter the values for the array:\n");
	for(i=0;i<lim;i++)
	{
		scanf("%d",&a[i]);
	}
	i=1;
	while(i<lim)
	{
		j=i;
		while(a[j]<a[j-1])
		{
			k=a[j];
			a[j]=a[j-1];
			a[j-1]=k;
			j=j-1;
		}
		i=i+1;
	}
	printf("The sorted array is:\n");
	for(i=0;i<lim;i++)
	{
	printf("%d\n",a[i]);
	}
}
