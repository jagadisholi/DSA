#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include<process.h>
struct node {
	int info;
	struct node* next;
};
void insert_atfirst(int item);
void traverse();
typedef struct node NodeType;
NodeType *head,*nnode; // Node1
int main()
{       int choice,item;
	
	head=NULL;
	do{
	printf("Enter 1 to insert item at first position");
	printf("\nEnter 2 to traverse");
	printf("\nEnter 9 to exit");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	printf("Enter an item to be inserted");
	scanf("%d",&item);
	insert_atfirst(item);
	break;
	case 2:
	traverse();
	break;
	case 9:
	exit(1);
	break;
	default:
	exit(1);
	}
	}while(choice<5);
	getch();
	return 0;
}
void insert_atfirst(int item)
{
	
	nnode = (NodeType *)malloc(sizeof(NodeType));
	
	nnode->info=item;
	nnode->next=head;
	head=nnode;
       //	printf("\n%d", nnode->info);
}
void traverse()
{
	NodeType *temp;
	temp=head;
	while(temp != NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->next;
	}
}
