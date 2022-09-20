#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
	int power;
	int coeff;
	struct node *next;
	
};
struct node *start1=NULL;
struct node *start2=NULL;
struct node *start3=NULL;
struct node *start4=NULL;
struct node *create_poly(struct node *start);
struct node *display_poly(struct node *start);
struct node *add_two(struct node*start1,struct node *start2,struct node *start3);
struct node *sub_two(struct node *start1,struct node *start2,struct node *start4);
struct node *add_node(struct node *start,int p,int c);
int main()
{
	int option;
	do{
		printf("****MENU****\n");
		printf(" \n 1.Create poynomial 1 \n");
		printf(" \n 2.Display the polynomial 1\n");
		printf("\n3.create polynomial 2\n");
		printf(" \n4.Display the polynomial 2\n");
		printf(" \n5.Add two polynomials\n");
		printf(" \n6.display the added polynomials\n");
		printf(" \n7.Substract the two polynomials\n");
		printf(" \n8.Display the substracted polynomial\n");
		printf("\n9.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				start1=create_poly(start1);
				printf(" The first polynomial is created\n");
				break;
			case 2:
				start1=display_poly(start1);
				break;
			case 3:
				start2=create_poly(start2);
				printf(" The second polynomial is created\n");
				break;
			case 4:
				start2=display_poly(start2);
				break;
			case 5:
				start3=add_two(start1,start2,start3);
				break;
			case 6:
				start3=display_poly(start3);
				break;
			case 7:
				start4=sub_two(start1,start2,start4);
				break;
			case 8:
				start4=display_poly(start4);
				break;
			
				
		}
		
		
	}while(option!=9);
	getch();
	
}
struct node *create_poly(struct node *start)
{
	struct node *new_node,*ptr;
	int power,coeff;
	printf("Enter -1 to end\n");
	printf(" Enter the power \n");
	scanf("%d",&power);
	
	while(power!=-1)
	{ 
		printf("Enter the coeff \n");
	scanf("%d",&coeff);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->power=power;
	new_node->coeff=coeff;
	if(start==NULL)
	{
		new_node->next=NULL;
		start=new_node;
		
	}
		else
    {
		ptr=start;
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=new_node;
		new_node->next=NULL;
		
		
		}
		printf("Enter the power\n" );
		scanf("%d",&power);
	}
	return start;
	
}
struct node *display_poly(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf(" %d X%d ",ptr->coeff,ptr->power);
	ptr=ptr->next;

	}
	return start;
	
}
struct node *add_two(struct node *start1,struct node *start2,struct node *start3)
{
	struct node *ptr1,*ptr2;
	int sum;
	ptr1=start1;
	ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
	
	if(ptr1->power==ptr2->power)
	{
		sum=ptr1->coeff+ptr2->coeff;
		start3=add_node(start3, ptr1->power, sum);
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	
	}
	else if(ptr1->power>ptr2->power)
	{
		sum=ptr1->coeff;
		start3=add_node( start3,ptr1->power,sum);
		ptr1=ptr1->next;
		
	}
	else if(ptr1->power<ptr2->power)
	{
		sum=ptr2->coeff;
		start3=add_node(start3,ptr2->power,sum);
		ptr2=ptr2->next;
		
	}
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			sum=ptr2->coeff;
			start3=add_node(start3,ptr2->power,sum);
			ptr2=ptr2->next;
		}
		
	}
    if(ptr2==NULL)
	{
		
			while(ptr1!=NULL)
		{
			sum=ptr1->coeff;
			start3=add_node(start3,ptr1->power,sum);
			ptr1=ptr1->next;
	   }
   }
	return start3;
}
struct node *sub_two(struct node *start1,struct node *start2 ,struct node *start4)
{

	struct node *ptr1,*ptr2;
	int sum;
	ptr1=start1;
	ptr2=start2;
	do
	{
	
	if(ptr1->power==ptr2->power)
	{
		sum=ptr1->coeff-ptr2->coeff;
		start4=add_node(start4, ptr1->power, sum);
		ptr1=ptr1->next;
		ptr2=ptr2->next;
		
	}
	else if(ptr1->power>ptr2->power)
	{
		sum=ptr1->coeff;
		start4=add_node( start4,ptr1->power,sum);
		ptr1=ptr1->next;
		
	}
	else if(ptr1->power<ptr2->power)
	{
		sum=ptr2->coeff;
		start4=add_node(start4,ptr2->power,sum);
		ptr2=ptr2->next;
		
	}
	}while(ptr1!=NULL|| ptr2!=NULL);
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			sum=ptr2->coeff;
			start4=add_node(start4,ptr2->power,sum);
			ptr2=ptr2->next;
		}
		
	}
	else if(ptr2==NULL)
	{
		
			while(ptr1!=NULL)
		{
			sum=ptr1->coeff;
			start4=add_node(start4,ptr1->power,sum);
			ptr1=ptr1->next;
	}
}
	return start4;	
}
struct node *add_node(struct node *start, int power,int coeff)
{
	struct node  *new_node,*ptr;
	if(start==NULL)
	{
	new_node=(struct node*)malloc(sizeof(struct node));

new_node->power=power;
new_node->coeff=coeff;
start=new_node;
	
	}
	else
	{
		ptr=start;
		new_node=(struct node*)malloc(sizeof(struct node));
	while(ptr->next!=NULL)
	ptr=ptr->next;
		ptr->next=new_node;
	new_node->power=power;
	new_node->coeff=coeff;
	new_node->next=NULL;

		
	}
	return start ;
}
























