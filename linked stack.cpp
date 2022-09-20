#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct stack{
	int data;
	struct stack *next;
};
struct stack *top=NULL;
struct stack *push(struct stack *,int);
struct stack *print(struct stack *);
int peek(struct stack*);
struct stack *pop(struct stack *);
int main()
{
	int val,
	 option;
	
	do{
	
	printf("\n\n***MENU***\n\n");
	printf("1.Push operation\n");
	printf("2.Pop operation\n");
	printf("3.Peek operation\n");
	printf("4.Print the stack \n");
	printf("5.Exit\n");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			printf("Enter the number to be inserted in the stack\n");
			scanf("%d",&val);
			top=push(top,val);
			break;
		case 2:
		 top =	pop(top);
			
			break;
		case 3:
			val=peek(top);
			if(val!=1)
			printf("\n The value at the top of the stack is %d",val);
			else
			{
				printf("Stack is empty\n");
			}
		
			
			break;
		case 4:
		top=	print(top);
			break;
			
		}
		
			}while(option!=5);
		getch();
		return 0;
			
}
struct stack *push(struct stack*top,int val)
{
	struct stack *ptr;
	ptr=(struct stack*)malloc(sizeof(struct stack));
	ptr->data=val;
	if(top==NULL)//second node link have first node address in link field and so on and last node address in “top” pointer.
	{ptr->next=NULL;
		top=ptr;
		
	}
	else{
		ptr->next=top;
		top=ptr;
		
	}
	return top;
}
struct stack *pop(struct stack *top)
{
	struct stack *ptr;
	ptr=top;
	if(top==NULL)
	{printf("Underflow\n");
	
	}
	else{
	
		top=ptr->next;
		printf("The value being deleted is%d",ptr->data);
		free(ptr);
}
return top;}
int peek(struct stack *top)
{
	if(top==NULL)
	return -1;
	else
	return top->data;
}
struct stack *print(struct stack *top)
{
	struct stack *ptr;
	ptr = top;
	if(top==NULL)
	printf("\nStack is empty\n");
	else{
		while(ptr!=NULL)
		{printf("\n%d\n",ptr->data);
		ptr=ptr->next;
		
		}
	return top;
}
}

