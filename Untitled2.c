#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	int *arr1,*arr2,n,i,count,z=0,j,s=0,l=0,e=0,num,pos[10],o;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	arr1=(int*)malloc(n*sizeof(int));
	arr2=(int*)malloc(n*sizeof(int));
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr1[i]);
	arr2[0]=arr1[0];
	l++;
	for(i=0;i<n;i++)
	{count=0;
		for(j=0;j<l;j++)
		{
			if(arr1[i]!=arr2[j])
			{
				count++;
			
			} 
		}
		
		if(count==l)
		{
			arr2[l]=arr1[i];
			l++;
		}
	
		else if(count<l)
		continue ;
		
	}
	printf("The numbers entered are\n");
		for(i=0;i<l;i++)
	printf(" %d ",arr2[i]);
	printf("\n");
	for(i=0;i<l;i++)
	{ num=arr2[i];
	   for(j=0;j<n;j++)
	     { 
		   if(num==arr1[j])
		   {
			 z++;
		    pos[e++]=j;}
	     } 
	     printf("\nThe number %d is repeated %d times at position \n",num,z);
	     for(o=0;o<e;o++)
	     printf(" %d ,",pos[o]+1);
	     e=0;
	     z=0;
		}
	
	  
	getch();
	
	}
