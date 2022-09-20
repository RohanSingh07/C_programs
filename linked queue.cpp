#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct queue{
	struct node *front;
	struct node *rear;
};
void create_que(struct queue *);
struct queue *insert(struct queue *,int val);
struct queue *delete_ele(struct queue *);
int peek(struct queue *);
struct queue *display(struct queue *);
struct queue *q;
int main()
{
	int option ,val;
	create_que(q);
	do{
		printf("\n***MENU***\n");
		printf("\n1.Insert a new element \n");
		printf("\n2.Delete an element from the queue\n");
		printf(" \n3.Display the queue\n");
		printf(" \n4.To perform peek operation\n");
		printf("\n5.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\n Enter the data of the new element\n");
				scanf("%d",&val);
				q=insert(q,val);
				break;
			case 2:
				val=delete_ele(q);
				printf("\nThe Element which was deleted is %d \n ",val);
				break;
			case 3:
			display(q);
			break;
			case 4:
			display(q);
			break;
				
		}while(option!=5);
		getch();
	}
}
struct create_que(struct queue *q)
{
	q->front=NULL;
	q->rear=NULL;
}
struct queue *insert(struct queue *q,int val)
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=val;
	if(q->front==NULL)
	{q->front=ptr;
	q->rear=ptr;
	q->front->next=q->rear->next=NULL;
	
	}
	else
	{
		q->rear->next=ptr;
		rear=ptr;
		q->rear->next=NULL;
		
	}
	return q;
}

struct queue *delete_ele(struct queue *q)
{
	
}







