#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 3
int st[max],top=-1;
void push (int st[],int val);
void display( int st[]);
int pop(int st[]);
int main(int argc,char *argv[])
{

	int val,option,i;
	
		do{
		printf(" press 1 for push operation\n");
		printf("Press 2 for pop operation\n");
		printf("Press 4 to exit");
	scanf("%d",&option);
		
		
		
	switch( option)
	{
	case 1:
	printf("\nEnter the number to be pushed on stack : ");
	scanf("%d",&val);
	push(st,val);
	display( st);
	break;
	case 2:
		val=pop(st);
		if(val!=-1)
		printf(" The value deleted from stack is %d",val);
		break;
		
}
}while(option!=4);
	getch();
	}	void push(int st[],int val)
	{
		if(top==max-1)
		{
			printf("\n Stack overflow");
		}
		else
		{
			top++;
			st[top]=val;
		}
	}
	void display(int st[])
	{ int i;
		if(top==-1)
		printf("\n The stack is empty:");
		else
		{
			for(i=top;i>=0;i--)
			printf(" \n %d",st[i]);
			printf("\n");
			
		}
	}
	int pop(int st[])
	{ int val;
	if(top==-1)
	{printf(" \nStack underflow");
	return -1;
	
	}
	else{
		val=st[top];
		top--;
		
		
		
		return val;
	}
}
	
	
	
	
	
	
	
	
