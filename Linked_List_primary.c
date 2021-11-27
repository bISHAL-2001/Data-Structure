//Working with 3 node
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* link;
};

void printList(struct Node* n)
{
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->link;
    }
    printf("\n");
}

int main(void)
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* tail = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    tail = (struct Node*)malloc(sizeof(struct Node));

    //Very 1st node
    head -> data = 1;
    head -> link = second;

    //2nd node
    second -> data = 2;
    second -> link = tail;

    //last node
    tail -> data = 3;
    tail -> link = NULL;

    printList(head);
    return 0;
}