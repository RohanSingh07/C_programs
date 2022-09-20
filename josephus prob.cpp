#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int player;
	struct node *next;
	
};
struct node *start,*ptr,*new_node;
int main()
{
	
	int n ,k,count ,i;
	
	printf("\n Enter the number of the players\n");
	scanf("%d",&n);
	printf("\n Enter the value of k\n");
	scanf("%d",&k);
	start=(struct node*)malloc(sizeof(struct node));
	start->player=1;
	ptr=start;
	for(i=2;i<=n;i++)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		ptr->next=new_node;
		new_node->player=i;
		new_node->next=start;
		ptr=new_node;
		
	}
	for(count=n;count>1;count--)
	{
		for(i=0;i<k-1;++i)
		ptr=ptr->next;
		printf("The element being eleminated is %d\n",ptr->next->player);
		ptr->next=ptr->next->next;
		
		
	}
	printf(":\n The winnewr is the player %d",ptr->player);
	getch();
	return 0;
}
