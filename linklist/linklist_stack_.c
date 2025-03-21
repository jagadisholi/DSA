#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct node {
    int top;
    int array[MAX_SIZE];
};

struct node* createStack() {
    struct node* stack = (struct node*)malloc(sizeof(struct node));
    stack->top = -1;
    return stack;
}

int isFull(struct node* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(struct node* stack) {
    return stack->top == -1;
}

void push(struct node* stack, int data) {
    if (isFull(stack)) {
        printf("Error: node overflow\n");
        return;
    }
    stack->array[++stack->top] = data;
    printf("%d pushed to the stack\n", data);
}

int pop(struct node* stack) {
    if (isEmpty(stack)) {
        printf("Error: node is empty\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int main() {
    struct node* stack = createStack();
    int choice, data;

    do {
        printf("\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                data = pop(stack);
                if (data != -1) {
                    printf("%d popped from the stack\n", data);
                }
            case 3: 
                data =dispaly()
                break;
            case 3:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}