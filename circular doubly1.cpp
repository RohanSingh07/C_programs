#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
 struct node *next;
	int data;
	struct node *prev;
};
struct node *start = NULL ;
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
		printf("\n12:Exit ");
		printf("\n Enter the option\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				start=create_ll(start);
				printf(" \n The linked list is created\n");
				break;
			case 2:
			start=display(start);
			break;
			case 3:
				start=insert_beg(start);
				break;
			case 4:
				start=insert_end(start); 
				break;
			case 5:
				start=insert_after(start);
				break;
			case 6:
				start=insert_before(start);
				break;
			case 7:
				start=delete_before(start);
				break;
			case 8:
				start=delete_after(start);
				break;
			case 9:
				start=delete_start(start);
					break;
				case 10:
					start=delete_end(start);
					break;
				case 11:
					start =delete_list(start);
					break ;
				
				
		}
	}while(option!=12);
	getch();
}
struct node *create_ll(struct node *start)
{
struct node *new_node,*ptr;
int val;
printf(" \n Enter -1 to exit");
printf(" \n Enter the data of the node\n");
scanf("%d",&val);
while(val!=-1)
{
	
	if(start==NULL)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=val;
		start=new_node;
		new_node->prev=start;
	
		new_node->next=start;
	}
	else
	{
		new_node=(struct node*)malloc(sizeof(struct node));
	     new_node->data=val;
		ptr=start;
		while(ptr->next != start)
		ptr=ptr->next;
		new_node->prev=ptr;
		ptr->next=new_node;
		new_node->next=start;
		
		start->prev=new_node;
		
        
	}
	printf("\nEnter the data of the node :");
	scanf("%d",&val);
}
return start;	
}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{printf(" %d ",ptr->data);
	ptr=ptr->next;
	
	}
	printf(" %d ",ptr->data);
	return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	printf("\nEnter the data of the new node\n");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node ));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	new_node->next=start;
	start->prev=new_node;
	new_node->prev=ptr;
	ptr->next=new_node;
	start=new_node;
	return start;
	
}
struct node *insert_end(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	printf(" \nEnter the data of the new node\n");
	scanf("%d ",&num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->next=new_node;
	new_node->prev=ptr;
	new_node->next=start;
	start->prev=new_node;
	return start;
	
}
struct node *insert_before(struct node *start)
{
	struct node *new_node,*ptr;
	int val,num;
	printf("\n Enter the data of the node\n");
	scanf("%d",&val);
	printf(" \n Enter the data of the node before which the new node has to be inserted \n");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=val;
	ptr=start;
	while(ptr->data!=num)
	ptr=ptr->next;
	ptr->prev->next=new_node;
	new_node->prev=ptr->prev;
	new_node->next=ptr;
	ptr->prev=new_node;
	return start;
	
	
	
}
struct node *insert_after(struct node *start)
{
struct node *new_node,*ptr;
int num,val;
printf("\nEnter the data of the new node\n");
scanf("%d",&val);
printf("\nEnter the data of the node after which the new element has to be inserted\n");
scanf("%d",&num)	;
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=val;
ptr=start;
while(ptr->data!=num)
ptr=ptr->next;
new_node->prev=ptr;
new_node->next=ptr->next;
ptr->next->prev=new_node;
ptr->next=new_node;
return start;
}
struct node *delete_start(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->next=start->next;
	start->next->prev=ptr;
	
	free(start);
	start=ptr->next;
	return start;
}

struct node *delete_end(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->prev->next=start;
	start->prev=ptr->prev;
	free(ptr);
	return start;
	
}
struct node *delete_before(struct node *start)
{
	struct node *ptr,*temp;
	int num;
	printf(" \nEnter the data of node whose predicessor has to be deleted\n");
	scanf("%d",&num);
	ptr=start;
	while(ptr->data!=num)
	ptr=ptr->next;
	
	temp=ptr->prev;
		if(temp==start)
	start=delete_start(start);
	else
{
		temp->prev->next=ptr;
	ptr->prev=temp->prev;}
	
	free(temp);
	return start;
	
	
	
}
struct node *delete_after(struct node *start)
{
	struct node *ptr,*temp;
	int num;
	printf(" \nEnter the data of node whose successor has to be deleted\n");
	scanf("%d",&num);
	ptr=start;
	while(ptr->data!=num)
	ptr=ptr->next;
	temp=ptr->next;
	ptr->next=temp->next;
	temp->next->prev=ptr;
	free(temp);
	return start;
	
	
	
}
struct node *delete_list(struct node *start)
{ struct node *ptr;
ptr=start;
	while(ptr->next!=start)
	start=delete_end(start);
	free(start);
	return start;
}




















	
