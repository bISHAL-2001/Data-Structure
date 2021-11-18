#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void append(struct Node** head_ref, int new_data)
{
    /*New-Node Creation*/
    struct Node* new_node = (struct Node*)malloc(sizeof (struct Node));
    /*Adding Data to the New Node*/
    new_node -> data = new_data;
    /*The address section of the new_node is set to null*/
    new_node -> link = NULL;
    /*If the list is empty, th new_node is declared as the new_node*/
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /*Else traverse from the head to the end and add the new_node*/
    struct Node* last = *head_ref;
    while(last -> link != NULL)
        last = last -> link;

    last -> link = new_node;

    return;
}
void deleteAlt(struct Node *head)
{
    if (head == NULL)
        return;

    /* Initialize prev and node to be deleted */
    struct Node *prev = head;
    struct Node *node = head->link;

    while (prev != NULL && node != NULL)
    {
        /* Change next link of previous node */
        prev->link = node->link;

        /* Update prev and node */
        prev = prev->link;
        if (prev != NULL)
            node = prev->link;
    }
    free(node);
}
void show(struct Node* node)
{
    if(node == NULL)
        printf("Empty!\n");
    else {
        while (node != NULL) {
            printf("%d ", node->data);
            node = node->link;
        }
        printf("\n");
    }
    return;
}
int main(void)
{
    struct Node *head = NULL;
    int n;
    scanf("%d", &n);
    for(int i =0; i<n; i++) {
        int temp;
        scanf("%d", &temp);
        append(&head, temp);
    }
    deleteAlt(head);
    show(head);
}