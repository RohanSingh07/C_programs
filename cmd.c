#include<stdio.h>
int main( int argc, char *argv[])
{
	int i,sum=0;
	printf(" Argument count =%d\n ",argc);
	printf(" File name is %s\n ",argv[0]);
	for(i=1;i<argc;i++)
	sum+=atoi(argv[i]);
	printf("Sum=%d",sum);
}
