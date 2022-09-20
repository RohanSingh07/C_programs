#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
struct que{
	struct node *front;
	struct node *rear;
};
struct que *q;
void create_que(struct que *q);
struct que *insert(struct que*,int);
struct que *delete_(struct que*);
int peek(struct que *);
struct que *print(struct que *);
int main()
{
	int option,val;
	create_que(q);
	getch();

	do{
		printf("\n\n***MENU***\n");
		printf("\n1.Insert new node in the queue\n");
		printf("\n2.Delete element from the queue\n");
		printf("\n3.Print the queue\n");
		printf("\n4.Perform peek operation\n");
		printf("\n5.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			
			case 1:
				printf("\nEnter the element to be inserted \n");
				scanf("%d",&val);
				q=insert(q,val);
				break ;
		    case 2:
		    	q=delete_(q);
		    	break ;
		    case 3:
		    	q=print(q);
		    	break ;
		    case 4:
		     val=peek(q);
		     if(val!=-1)
		     printf(" The value on front is %d ",val);
		     break ;
		     
		}
	}while(option!=5);
	getch();
}
void create_que(struct que *q)
{

	q->rear = NULL;
	q->front=NULL;
}
struct que *insert(struct que *q,int val)
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=val;
	if (q->front==NULL)
	{
	q->front=ptr;   
	q->rear=ptr;
	q->front->next=q->rear->next=NULL;
	}
	else
	{
	q->rear->next=ptr;
	q->rear=ptr;
	q->rear->next=NULL;	
	}
	return q;
}
struct que *delete_(struct que *q)
{
	
	struct node *ptr;
	ptr=q->front;
	if(q->front==NULL)
	{
	printf(" \nUnderflow\n");
	}
	else{
	
	q->front=q->front->next;
	printf("The value being deleted is %d",ptr->data);
	free(ptr);
	}
	return q;
}
int peek(struct que *q)
{
	if(q->front==NULL)
	{
	printf(" \nThe queue is empty\n");
	return -1;
}
	else
	{
		return q->front->data;
	}
}
struct que *print(struct que *q)
{
	struct node *ptr;
	ptr=q->front;
	if(ptr==NULL)
	{printf("\n The queue is empty\n");
	}
	else{
	
	while(ptr!=q->rear)
{
		printf("  %d  ",ptr->data);
	ptr=ptr->next;
}
printf(" %d ",ptr->data);
}return q;
}
