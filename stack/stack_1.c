// stack implementation
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 3   // global variable
int stack[MAX]; // stack implementation using Array
int top = -1;
void push(int n);
int pop();
int peek();
void display();
int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int main()
{
    int ch, value;
    while (1)
    {
        printf("\n");
        printf("1.push");
        printf("\n2.pop");
        printf("\n3.peek");
        printf("\n4.Print all the elements of the stack");
        printf("\n5. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to be push:");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            value = pop();
            printf("\n Deleted value is %d\n", value);
            break;

        case 3:
            printf("\n the element of the stack is %d\n", peek());
            break;

        case 4:
            printf("\n");
            display();
			break;

        case 5:
        	exit(1);
            break;

        default:
            printf("please choose the right value\n");
        }
    }
    return 0;
}
void push(int data)
{
    if (isFull())
    {
        printf("stack overflow");
        // return;
    }
    else{
    top++;
    stack[top] = data;
    }
}
int pop()
{
    int n;
    if (isEmpty())
    {
        printf("\n stack underflow");
       // exit(1);
    }
    n = stack[top];
    top = top - 1;
    return n;
}

int peek()
{
    if (isEmpty())
    {
        printf("stack is Empty\n");
       // exit(1);
    }
    return stack[top];
}
void display()
{
    int i;
    printf("%d",top);
    if (isEmpty())
    {
        printf("\n stack underflow, no data to show");
      // exit(1);
    }
    else
    {
        printf("\n the elements in stack are:");
      //  for (i =0; i<=top; i++)
        for(i=top; i>=0; i--)
        {
            printf("%d\t", stack[i]);
        }
    }
    printf("\n");
}
//  return 1;
