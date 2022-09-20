#include<stdio.h>
#include<conio.h> 
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int c;int p;struct node *next;
};
struct node* start1=NULL;
struct node* start2=NULL;
struct node* start3=NULL;
struct node* start4=NULL;
struct node*creation(struct node*);
struct node*display(struct node*);
struct node*add(struct node*,struct node*,struct node*);
struct node*addnode(struct node*,int,int);
int main()
{
	int choice;
	do
	{
		printf("1:Creation 1\n");
		printf("2:Display\n");
		printf("3:Creation 2\n");
		printf("4:Display\n");
		printf("5:Add\n");
		printf("6:Display\n");
		printf("7:Exit\n");
		printf("8:Enter choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				start1=creation(start1);
				printf("Created\n");
				break;
			case 2:
				start1=display(start1);
				break;
			case 3:
				start2=creation(start2);
				printf("Created\n");
				break;
			case 4:
				start2=display(start2);
				break;
			case 5:
				start3=add(start1,start2,start3);
			    break;
			case 6:
				start3=display(start3);
				printf("The Result is printed\n");
				break;
			case -1:
				printf("the end\n");
				break;
			default:
				printf("Wrong choice\n");
			
			
				
		}
	}while(choice!=-1);
	getch();
return 0;
}
struct node* creation(struct node* start)
{
	struct node *new_node,*ptr;
	int coeff,pow;
	printf("Enter the coefficient\n");
	scanf("%d",&coeff);
	printf("Enter the power.\n");
	scanf("%d",&pow);
	while(coeff!=-1)
    {
    	new_node=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		new_node->next=NULL;
		new_node->p=pow;
		new_node->c=coeff;
		start=new_node;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=new_node;
		new_node->next=NULL;
		new_node->c=coeff;
		new_node->p=pow;
	}
	printf("Enter coefficient\n");
	scanf("%d",&coeff);
	if(coeff==-1)
	break;
	printf("Enter power\n");
	scanf("%d",&pow);
}
return start;
}
struct node* display(struct node* start)
{
	struct node* ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf(" %d x^ %d\n",ptr->c,ptr->p);
		ptr=ptr->next;
	}
	return start;
}
struct node* add(struct node *start1,struct node *start2,struct node* start3)
{
	struct node *ptr1,*ptr2;
	int sum;
	ptr1=start1;
	ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->p == ptr2->p)
		{
			sum=ptr1->c+ptr2->c;
			start3=addnode(start3,sum,ptr1->p);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->p>ptr2->p)
		{
			start3=addnode(start3,ptr1->c,ptr1->p);
			ptr1=ptr1->next;
		}
		else if(ptr2->p>ptr1->p)
		{
			start3=addnode(start3,ptr2->c,ptr2->p);
			ptr2=ptr2->next;
		}
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			start3=addnode(start3,ptr2->c,ptr2->p);
			ptr2=ptr2->next;
		}
	}
	if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			start3=addnode(start3,ptr1->c,ptr1->p);
			ptr1=ptr1->next;
		}
	}
	return start3;
}
struct node* addnode(struct node *start,int coeff,int pow)
{
	struct node *new_node,*ptr;
	new_node=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		new_node->p=pow;
		new_node->c=coeff;
		new_node->next=NULL;
		start=new_node;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=new_node;
		new_node->p=pow;
		new_node->c=coeff;
		new_node->next=NULL;
	}
	return start;
}
	
