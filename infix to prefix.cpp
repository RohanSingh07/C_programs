#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char st[max] ;
int top=-1;
char pop(char st[]);
void infixtopostfix(char source[],char target[]);
void push(char st[],char);
int getpriority( char);
void reverse(char st[]);
char temp[100],infix[100],postfix[100];
int main()
{
	
	int i,j;
	printf("Enter the expression\n");
	gets(infix);
	reverse(infix);
	strcpy(postfix," ");
	infixtopostfix(temp,postfix);
	printf("The corresponding postfix expression is as follows\n");
	puts(postfix);
	strcpy(temp,"");
	reverse(postfix);
	printf("\n The prefix expression is :\n");
	puts(temp);
	getch();
	return 0;
}
void infixtopostfix(char source[],char target[])
{
	int i=0,j=0;
	char temp;
	strcpy(target," ");
	while(source[i]!='\0')
	{
		if(source[i]=='(')
		{
			push(st,source[i]);
			i++;
		}
		else if(source[i]==')')
		{
			if(top==-1) 
			{printf("Incorrect expresion\n");
			exit(1);
			}
			while((top!=-1)&&(st[top]!='('))
			{
				target[j]=pop(st);
				j++;
			}
			temp=pop(st);
			i++;
		}
		else if(isdigit(source[i])||isalpha(source[i]))
		{
			target[j]=source[i];
			i++;
			j++;
		}
		else if(source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='%'||source[i]=='/')
		{
			while((top!=-1)&&(st[top]!='(')&&(getpriority(source[i])<getpriority(st[top] )))
       {
       	target[j]=pop(st);
       	j++;
	   }
	   push(st,source[i]);
	   i++;
	   	}
	   	else{
	   		printf("Incorrect expression2\n");
	   		exit(1);
	   		
		   }
	}
	while((top!=-1)&&(st[top]!='('))
	{
		target[j]=pop(st);
		j++;
	}
	target[j]='\0';
	
}
void push(char st[],char val)
{
	if(top==max-1)
	printf("stack overflow\n");
	else
	{
		st[++top]=val;
	}

}
char pop(char st[])
{char val=' ';
	if(top==-1)
    printf("Stack underflow\n");
    else
    {
    	val=st[top];
    	top--;
	}
	return val;
}
int getpriority(char op)
{
	if(op=='*'||op=='/'||op=='%')
	return 1;
	else if(op=='+'||op=='-')
	return 0;
	
}
void reverse(char st[])
{
	int i=0,j=0,len;
	len=strlen(st);
	j=len-1;
	while(j>=0){
	

	if(st[j]=='(')
	temp[i]=')';
	else if(st[j]==')')
	temp[i]='(';
	else 
	temp[i]=st[j];
	j--;
	i++;
	
}
temp[i]='\0';
}
