#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
struct node *start =NULL ;
struct node *create_ll( struct node*);
struct node *insert_beg(struct node*);
struct node *insert_end(struct node*);
struct node *insert_after(struct node*);
struct node *insert_before(struct node*);
struct node *delete_before(struct node*);
struct node *delete_after(struct node*);
struct node *delete_start(struct node*);
struct node *delete_end(struct node*);
struct node *display(struct node *);
struct node *delete_list(struct node*);
struct node *sort(struct node*);
int main(int argc,char *argv[])
{
	int option;
	do{
		printf(" ***MENU***\n");
		printf(" 1.Create a list\n");
		printf(" 2.Display the list\n");
		printf(" 3.Insert at begining\n");
		printf(" 4.Insert at end\n");
		printf(" 5.Insert after a given element\n");
		printf(" 6.Insert before a given element\n");
		printf(" 7.Delete a node before a given node\n");
		printf(" 8.Delete a node after a given node\n");
		printf(" 9.Delete the fisrt element\n");
		printf(" 10.Delete the last element\n");
		printf("11.Delete the list\n");
		printf(" 12.Sort the list in ascending order\n");
		printf(" 13.Exit\n");
		printf(" Enter the option\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				start= create_ll(start);
				break;
			case 2:
			 start = display(start);
			break;
			case 3:
			start= insert_beg(start)	;
			break;
			case 4:
			start= insert_end(start);
			break;
			case 5:
			start= insert_after(start);
			break;
			case 6:
			start= insert_before(start);
			break;
			case 7:
			start= delete_before(start);
			break;
			case 8:
			start= delete_after(start);
			break;
			case 9:
			start= delete_start(start);
			break;
			case 10:
			start= delete_end(start);
			break;	
			case 11:
			start =delete_list(start);
			printf("\nThe list has been deleted\n");
			break;	
			case 12:	
			start = sort(start);
			break ;
			
		}
		
	} while(option!=13);
	getch();
}
struct node *create_ll( struct node *start)
{
	struct node *ptr,*new_node;
	int num;
	printf("Enter -1 to end\n");
	printf(" Enter the data\n");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data =num;
		if(start==NULL)
		{
			new_node->next=new_node;
			start=new_node;
		}
		else{
			ptr=start;
			while(ptr->next!=start)
			ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=start;
		}
		printf("Enter the data\n");
		scanf("%d",&num);
	}
return start;	
	
}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr =start;
	while(ptr->next!=start)
	{printf(" %d ",ptr->data);
	ptr=ptr->next;
	}
printf(" %d ",ptr->data);	
	return start;
	
}

struct node *insert_beg(struct node*start)
{
	struct node *new_node,*ptr;
	int val;
	printf("Enter the data of the new node\n");
	scanf("%d",&val);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=val;
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=start;
	start=new_node;
	return start;
}
struct node *insert_end(struct node*start)
{
	struct node *new_node,*ptr;
	int val;
	printf("Enter the data to of new node\n");
	scanf("%d",&val);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=val;
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=start;
	return start;
	
	
	
}
struct node *insert_after(struct node *start)
{
	struct node *new_node,*ptr,*preptr;
	int val,num;
	printf("Enter the data of new node\n");
	scanf("%d",&val);
	printf("Enter the data after which the element has to be inserted\n");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=val;
	ptr=start;
	preptr=ptr;
	while(preptr->data!=num)
	{preptr=ptr;
	ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	
	return start;
	
	
}
struct node *insert_before(struct node *start)
{
	struct node *new_node,*ptr,*preptr;
	int val,num;
	printf("Enter the data of the new node\n");
	scanf("%d",&val);
	printf(" Enter the data before which the element has to be inserted\n");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data =val;
	ptr=start;
	preptr=ptr;
	while(ptr->data!=num)
	{ preptr=ptr;
	ptr=ptr->next;
	
	}
	preptr->next=new_node;
    new_node->next=ptr;
    return start;
}
struct node *delete_before(struct node *start)
{
	struct node *ptr,*preptr;
	int num;
	printf("Enter the data of node ,whose predecessor has to be deleted (before) \n");
	scanf("%d",&num);
	ptr=start;
	preptr=ptr;
	while(ptr->next->data!=num)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	if(ptr==start)
	start=preptr->next;
	free(ptr);
	
	return start;
	
}
struct node *delete_after(struct node *start)
{
	struct node *ptr,*preptr;
	int num;
	printf(" Enter the data of node ,whose successor has to be deleted(after)\n");
	scanf(" %d ",&num);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=num)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	if(ptr==start)
	start=preptr->next;
	free(ptr);
	
	return start;
	
}
struct node *delete_start(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->next=start->next;
	free(start);
	start=ptr->next;
	return start;
	
}
struct node *delete_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	preptr=ptr;
	while(ptr->next!=start)
	{preptr=ptr;
	ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}

struct node *delete_list(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	start=delete_end(start);
	free(start);
	return start;
}

struct node *sort( struct node *start)
{
	struct node *ptr1,*ptr2;
	int temp;
	ptr1=start;
	while(ptr1->next!=start)
	{
		ptr2=ptr1->next;
		while(ptr2!=start)
		{
		
		if( ptr1->data>ptr2->data)
		{
			temp=ptr1->data;
			ptr1->data=ptr2->data;
			ptr2->data=temp;
		}
		ptr2=ptr2->next;
	}

	ptr1=ptr1->next;
}
return start;
}













