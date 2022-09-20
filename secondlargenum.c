#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	int n,i,*arr,max,j,secondlar;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",(arr+i));
	
	}
	max=arr[0];
	
	for(j=0;j<n;j++)
	
{
if(arr[j]>max)
max=arr[j];
	
}
secondlar=arr[1];
for(i=0;i<n;i++)
{ 
if(arr[i]!=max)
{
if(arr[i]>secondlar)
secondlar=arr[i];
}
}
printf("The second largest value is %d",secondlar);
	getch();
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
