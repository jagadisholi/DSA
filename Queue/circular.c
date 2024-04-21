// circular queue Implementation using array 

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 4
int queue[MAX]; // ARRAY DECLARATION FOR CIRCULAR QUEUE
int front=-1;
int rear=-1;

void enqueue(){
    int data; 
    printf("\n\n the front : %d\n\n", front);
    printf("\n\n the rear : %d\n \n", rear);
    printf("enter the elements that is to be inserted in a queue");
    scanf("%d", &data);
    if(front==-1 && rear==-1) // first case : queue can be empty
    {
        front=0;
        rear=0;
        queue[rear]= data;
    }
    else if((rear+1)%MAX==front){ // second case : queue can be full
        printf("\n\nQueue is Full \n\n");
    }
    else  // third case : queue can have space 
    {
        rear=(rear+1)%MAX ;  // rear is incremented so that it goes back to the first location to make the queue circular 
        printf("  %d is inserted \n", data); 
        queue[rear]=data;  // inserting the given data
    }
}

int dequeue(){
    if((front==-1) && (rear==-1))  // first case : queue can be empty
    {
        printf("\n \n Queue is Empty \n \n ");    
    }
    else if(front==rear)  // second case : Both front and rear are pointing at same value
    {
        printf("\nthe dequeued element is %d", queue[front]);
        front=-1;
        rear=-1;
    }
    else  // third case : front and rear are in different places 
    {
        printf("\n the dequeued element is %d", queue[front]);
        front=(front+1) %MAX;
    }
}
// to display the elements of a queue 
void display(){
    int i = front;
    if(front==-1 && rear==-1)
    {
        printf("\n \n queue s empty \n \n");
    }
    else{
        printf("\n \n Elements in a queue are : ");
        while(i!=rear)
        {
            printf("\n \n %d \t", queue[i]);
            i=(i+1)%MAX;
        }
        printf("%d", queue[rear]);
    }
}
int main(){
    int choice;
    while(1)
    {
        printf("\n Press 1 : Insert an element in circular queue");
        printf("\n press 2: Delete an element from circular queue");
        printf("\n press 3: display the element of circular queue");
        printf("\n press 4: Quit");
        printf("\n enter your choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            display();
            break;

        case 2:
            dequeue();
            display();
            break;

        case 3:
            display();
            break;
        
        case 4:
            exit(1);
            
        default:
            printf("\n Invalid choice \n");
            break;
        }
    }
    getch();
    return 0; 
}