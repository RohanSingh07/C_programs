#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 30

int Delete(void);
void display(void);
void insert(void);
int peek(void);
int front=-1,rear =-1,queue[max];
int main()
{
int option,val;

do{
	printf("*****Main Menu****");
    printf("\n 1.Insert new element ");
	printf(" \n 2.Delete ");
	printf(" \n 3.Peek");
	printf(" \n 4.Print queue");
	printf(" \n 5.Exit\n");
	scanf(" %d",&option);
	
	switch(option)
	{
		case 1:
			insert();
			break;
		case 2:
		val=Delete();
		if(val!=-1)
		printf("The value deleted is : %d",val);
		break;
		case 3:
		val=peek();
		if(val!=-1)
		printf(" The value at the top of queue is:%d",val);
		break;
		case 4:
		display();
		break;	
			
	}
	}while(option!=5);
	getch();	
}
void insert(void)
{
	int val;
	printf(" Enter the value to be entered in queue\n");
	scanf(" %d",&val);
	if(front==max-1)
	printf(" Overflow\n");
	else if(front==-1||rear==-1)
	{
	front=rear=0;
	queue[rear]=val;
	}
	else
	{
	rear++;
	queue[rear]=val;
	}
}
int Delete(void)
{ int val;
	if(front==-1||front>rear)
	{
	printf("Underflow\n");
	}	
	else
	{val=queue[front];
	front++;
		
	}
	if( front>rear)
	{
	front=rear =-1;
	}
	return val;
}
int peek(void)
{
	if(front==-1||front>rear)
	{
		printf(" \n Queue is empty");
	return -1;
    }
	else 
	return queue[front];  
	}	
void display(void)
{
	int i;
	if(front ==-1||front>rear)
	printf(" \n Queue is empty");
	else{
		for(i=front;i<=rear;i++)
		printf(" %d ",queue[i]);
	
	}
	printf("\n");
	}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		

