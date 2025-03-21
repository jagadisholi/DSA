#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node NodeType;
NodeType *head = NULL;

void insert_atfirst(int);
void insert_atend(int);
void insert_after_node(int, int);
void insert_at_position(int, int);
void delete_first();
void delete_last();
void delete_after_node(int);
void delete_at_position(int);
void traverse();
void display_menu();
void delete_all_nodes();

int main() {
    int choice;
    int item;
    int position;
    int after_node;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item to be inserted at first position: ");
                scanf("%d", &item);
                insert_atfirst(item);
                break;
            case 2:
                printf("Enter item to be inserted at end position: ");
                scanf("%d", &item);
                insert_atend(item);
                break;
            case 3:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                printf("Enter node after which you want to insert: ");
                scanf("%d", &after_node);
                insert_after_node(item, after_node);
                break;
            case 4:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                printf("Enter position: ");
                scanf("%d", &position);
                insert_at_position(item, position);
                break;
            case 5:
                delete_first();
                break;
            case 6:
                delete_last();
                break;
            case 7:
                printf("Enter node after which you want to delete: ");
                scanf("%d", &after_node);
                delete_after_node(after_node);
                break;
            case 8:
                printf("Enter position of node to delete: ");
                scanf("%d", &position);
                delete_at_position(position);
                break;
            case 9:
                traverse();
                break;
                
            case 10:
             delete_all_nodes();
                break;
                
            case 11:
            	exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 11);

    return 0;
}

void insert_atfirst(int item) {
    NodeType *nnode = (NodeType*)malloc(sizeof(NodeType));
    if (nnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    nnode->info = item;
    nnode->next = head;
    head = nnode;
}

void insert_atend(int item) {
    NodeType *nnode = (NodeType*)malloc(sizeof(NodeType));
    if (nnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    nnode->info = item;
    nnode->next = NULL;
    
    if (head == NULL) {
        head = nnode;
    } else {
        NodeType *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nnode;
    }
}

void insert_after_node(int item, int after_node) {
    NodeType *temp = head;
    while (temp != NULL && temp->info != after_node) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    NodeType *nnode = (NodeType*)malloc(sizeof(NodeType));
    if (nnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    nnode->info = item;
    nnode->next = temp->next;
    temp->next = nnode;
}

void insert_at_position(int item, int position) {
    if (position == 1) {
        insert_atfirst(item);
        return;
    }
    NodeType *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    NodeType *nnode = (NodeType*)malloc(sizeof(NodeType));
    if (nnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    nnode->info = item;
    nnode->next = temp->next;
    temp->next = nnode;
}

void delete_first() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    NodeType *temp = head;
    head = head->next;
    free(temp);
}

void delete_last() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    NodeType *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void delete_after_node(int after_node) {
    NodeType *temp = head;
    while (temp != NULL && temp->info != after_node) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Node not found or node is last\n");
        return;
    }
    NodeType *to_deletee = temp->next;
    temp->next = to_deletee->next;
    free(to_deletee);
}

void delete_at_position(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 1) {
        delete_first();
        return;
    }
    NodeType *temp = head;
    NodeType *prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void traverse() {
	if (head == NULL) {
        printf("List is empty\n");
    return;
}
else{
	NodeType *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}
}
void delete_all_nodes() {
    NodeType *current = head;
    NodeType *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    head = NULL; 
}


void display_menu() {
    printf("\nEnter 1 to insert item at first position\n");
    printf("Enter 2 to insert item at end position\n");
    printf("Enter 3 to insert node after given node\n");
    printf("Enter 4 to insert node at specific position\n");
    printf("Enter 5 to deletee first node\n");
    printf("Enter 6 to deletee last node\n");
    printf("Enter 7 to deletee a node after given node\n");
    printf("Enter 8 to deletee a node at specific position\n");
    printf("Enter 9 to traverse\n");
    printf("Enter 10 deletee all nodes \n");
    printf("Enter 11 to exit\n");
}