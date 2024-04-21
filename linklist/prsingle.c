// practice of singly link list
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
struct node{
    int info; 
    struct node*next;
};
void insert_atfirst(int item);
void traverse();
void insert_atend(int nitem);
typedef struct node NodeType;
NodeType *head=NULL,*last=NULL, *nnode // node 1
int main()
{
    int choice, item, nitem;
    do{
        printf("enter 1 to insert item at first position");
        printf("\n enter 2 to traverse");
        printf("\n Insert at end");
        printf("\n enter 9 to exit");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("enter an item to be inserted");
            scanf("%d", &item);
            insert_atfirst(item);
            break;
            case 2:
            traverse();
            break;
            case 3:
            printf("enter the item at end");
            scanf("%d", &nitem);
            insert_atend(nitem);
            break;
            case 4:
            exit(0);
            default:
            printf("Invalid choice!\n");
        }
    }
    while(choice!=6);
    return 0;
}
void insert_atfirst(int item)
{
    nnode = (NodeType *)malloc(sizeof(NodeType));
    nnode->info=item;
    nnode->next=head;
    head=nnode;
}
void traverse()
{
    NodeType *temp;
    temp=head;
    while(temp !=NULL)
    {
        printf("%d\t", temp->info);
        temp=temp->next;
    }
}

void insert_atend(int nitem)
{
    nitem=(NodeType*)malloc(sizeof(NodeType));
    nnode->info= nitem;
    nnode->next=NULL;
    if(head==NULL)
    {
        head=nnode;
        last=nnode;
    }
    else
    {
        last->next=nnode;
        last=nnode;
    }
}
