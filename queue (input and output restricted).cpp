#include<stdio.h>
#include<conio.h>
#define max 10
int queue[max];
int left=-1,right=-1;
void inqueue();
void ouqueue();
void insert_left();
void insert_right();
void delete_left();
void delete_right();
void display();
int  main()
{
	int option;
	
		printf("\n***MENU***\n");
		printf("\n1.Input restricted queue\n");
		printf("\n2.Output  restricted queue\n");
		printf("\n3.exit\n");
		printf("\nEnter your option\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			void inqueue();
			break;
			case 2:
		    void ouqueue();
			break ;
			
				
		}
		return 0;
		
	
}
void inqueue()
{
	int option ,val;
	do{
		printf("\n***MENU***\n");
		printf("\n1.Insert from left\n");
		printf("\n2.Delete from left\n");
		printf("\n3.Delete from right\n");
		printf("\n4.Print Queue\n");
		printf("\n5.exit \n");
		printf("\nEnter your option\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			insert_left();
			break ;
			case 2:
			delete_left();
			break;
			case 3:
			delete_right();
			break;
			case 4:
			display();
			
			
		}
		
	}while(option!=5);
	 getch();
	  
}
void ouqueue()
{
	int option ,val;
	do
	{
		printf("\n***MENU***\n");
		printf("\n1.Insert from left\n");
		printf("\n2.Insert from right\n");
		printf("\n3.Delete from right \n");
		printf("\n4.display queue\n");
		printf("\n5.Exit\n");
		printf("\n Enter your option\n");
		scanf("%d",&option);
		switch(option)
		{
		case 1:
		 insert_left();
		 break ;
		 case 2:
		insert_right();
		break;
		case 3:
		delete_right();
		break;
		
	}
}while(option!=5);
getch();

}
void insert_right()
{  
	 int val;
	 printf("\n Enter the value of the queue\n");
	 scanf("%d",&val);
	 if((left==0&&right==max-1)||(left==right+1))
	 {
	 printf("\n Overflow\n");
      return ;
}
	 else if(left==-1)
	 {left=0;
	 right=0;
	 
	 }
	 else if(right==max-1)
	 {
	 	right=0;
	 }
	 else
	 {
	 	right++;
	 	}
	queue[right]=val;
	 
	 
	 
}
void insert_left()
{
	int val;
	printf("\nEnter the value \n");
	scanf("%d",&val);
	if((left==0&&right==max-1)||(left==right+1))
	{
	printf("\nOverflow\n");
	return ;	
	}
	else if(left==-1)
	{
		left=0;
		right=0;
	}
	else if(left==0)
	{
		left=max-1;
		
	}
	else {
		left--;
	}
	queue[left]=val;
	
}
void delete_left()
{
	if(left==-1)
    {
	printf("\nUnderflow\n");
	return ;}
	printf("The element being deleted is\n%d",queue[left]);
	if(left==right)
	{
		left=-1;
		right=-1;
	}
	
	else if(left==max-1)
	left=0;
	else 
	{
		left++;
	}
	
}
void delete_right()
{
	if(left==-1)
	{
	printf("\n Underflow\n");

return ;}
printf("\n The element being is deleted is %d",queue[right]);
 if(left==right)
{
	left=-1;
	right=-1;
}
else if(right==0)
right=max-1;
right--;
}
void display()
{ 
int i;
if(left==-1)
{
	printf("\n The stack is empty\n");
	return;
}
else if(left==right)
printf("\n %d",queue[left]);


else if(left<right)
{

for(i=left;i<=right;i++)
printf("\n %d ",queue[i]);
}

else
{
	for(i=0;i<=right ;i++)
	printf("\n %d ",queue[i]);
	for(i=left;i<=max-1;i++)
	printf("\n %d",queue[i]);
}
}





















