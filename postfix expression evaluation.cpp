#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100
int top =-1;
float st[max];
void push( float st[],float val);
float pop(float st[]);
float evaluatepostfix(char exp[]);
int main()
{
	char exp[100];
	float result;
	printf("Enter the postfix expression\n");
	gets(exp);
	result=evaluatepostfix(exp);
	printf("The result of the postfix expression is as follows\n %f",result);
	getch();
	return 0;
	
}
float evaluatepostfix(char exp[])
{
	int i=0;
	float op1,op2,value;
	while(exp[i]!='\0')
	{
	if(isdigit(exp[i]))	
	{
		
		push(st,(float)(exp[i]));
		i++;
	}
	else
	{
		op2=pop(st);
		op1=pop(st);
		switch(exp[i])
		{
			case '+':
			
					value=op1+op2;
				
				
				break;
			case '-':
		
			value=op1-op2;
			break;
			case '*':
			
			value=op1*op2;
			break;
			case '/':
			
			value=op1/op2;
			break;
			case '%':
			value=(int)op1%(int)op2;
			break;
				
		}
		push(st,value);
		
		
		
	}i++;
	
	}
	return (pop(st));
}
void push(float st[],float val)
{
	if(top==max-1)
	printf(" stack overflow\n");
	else
	{
		top++;
		st[top]=val;
		
	}
}
float pop(float st[])
{
	float value=-1;
	if(top==-1)
	printf("Stack underflow\n");
	else
	{
	value=st[top];
	top--;	
	}
	return value;
}
















