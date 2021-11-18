#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void show(struct Node* node)
{

    if(node == NULL)
        printf("Empty!");
    else {
        printf("|");

        while (node != NULL) {
            printf(" %d |", node->data);
            node = node->link;
        }
    }
    return;
}

void push(struct Node** head_ref, int new_data)
{
    /*Allocation of New Node*/
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    /*Adding Data to the New Node*/
    new_node -> data = new_data;

    /*Converting the new_node as Head*/
    new_node -> link = *head_ref;

    /*Moving the Head-Node a step back*/
    *head_ref = new_node;
    printf("[+] Successfully Added\n");
}


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

    printf("[+] Successfully Added\n");
    return;
}
void add_after_head(struct Node** head_ref, struct Node* head, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = data;
    new_node->link = NULL;
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    temp_node -> link = head->link;
    head -> link = new_node;
    new_node -> link = temp_node->link;

    printf("[+] Successfully Added\n");
}

void add_after_required(struct Node* node, int data, int user_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    int c=0;
    while(node!=NULL) {
        if(node->data == data) {
            new_node->data = user_data;
            new_node->link = node->link;
            node->link = new_node;
            printf("[+] Successfully Added\n");
            c+=1;
            break;
        }

        node = node->link;
    }
    if(c==0)
        printf("[-] Operation unsuccessful!\n");
    return;
}

void pop(struct Node** head)
{
    if(*head == NULL) {
        printf("Underflow has occurred!\n");
    }
    else
    {
        printf("Data popped: %d\n", (*head)->data);
        *head = (*head) -> link;
    }
    return;
}

void deleteAlt(struct Node *head)
{
    if (head == NULL) {
        printf("[-] Operation not possible!");
        return;
    }
    else if(head -> link == NULL) {
        printf("[-] Operation not possible!");
        return;
    }
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
    printf("[+] Deleted alternate nodes\n");
    printf("The current state of the List: ");
    show(head);
}

void LastNodeDeletion(struct Node *head, struct Node** head_ref)
{
    struct Node *toDelLast, *preNode = NULL;
    if(head == NULL)
        show(head);
    else if(head->link == NULL)
    {
        struct Node* new_head = NULL;
        *head_ref = new_head;
    }
    else
    {
        toDelLast = head;
        preNode = head;
        /* Traverse to the last node of the list*/
        while(toDelLast->link != NULL)
        {
            preNode = toDelLast;
            toDelLast = toDelLast->link;
        }
        if(toDelLast == head)
        {
            head = NULL;
        }
        else
            /* Disconnects the link of second last node with last node */
            preNode->link = NULL;

    }
}

void delete_a_particular_Node(struct Node** head_ref, int key)
{
    // Store head node
    struct Node *temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->link; // Changed head
        free(temp); // free old head
        printf("[+] Success!\n");
        printf("The List after deletion of the node: ");
        show(*head_ref);
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->link;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("[-] No such value was found to be deleted!");
        return;
    }
    // Unlink the node from linked list
    prev->link = temp->link;
    printf("[+] Success!\n");
    printf("The List after deletion of the node: ");
    show(*head_ref);
    free(temp); // Free memory


}

int main(void) {
    struct Node *head = NULL;
    printf("Welcome to the Linked List Test!\n");
    printf("--------------------------------\n--------------------------------\n");
    printf("Press:\n1. To Push integers at the beginning of the list\n2. To Append integers as the end of the list\n3. To Add integers after the head\n4. To Add integers after any other data\n5. To pop data (POP means to remove data from the beginning of the list, i.e, to delete the very 1st node)\n6. To delete alternate nodes \n7. To delete data from the end\n8. To delete a particular Node\n9. To show the List\n10. Exit");

    int choice;
    do
    {
        int data;
        printf("\nEnter your choice:\n-->");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the number to be pushed:\n-->");
                scanf("%d", &data);
                push(&head, data);
                printf("The current state of the List: ");
                show(head);
                break;
            case 2:
                printf("Enter the number to be appended:\n-->");
                scanf("%d", &data);
                append(&head, data);
                printf("The current state of the List: ");
                show(head);
                break;
            case 3:
                printf("Enter the number to be added after the very 1st node:\n-->");
                scanf("%d", &data);
                add_after_head(&head, head, data);
                printf("The current state of the List: ");
                show(head);
                break;
            case 4:
                printf("The current status of the LIST: ");
                show(head);
                printf("\nEnter the number to be added:\n-->");
                scanf("%d", &data);
                int given_data;
                printf("Enter the number after which you want to insert the number:\n-->");
                scanf("%d", &given_data);
                add_after_required(head, given_data, data);
                break;
            case 5:
                pop(&head);
                printf("The current state of the List: ");
                show(head);
                break;
            case 6:
                deleteAlt(head);
                break;
            case 7:
                LastNodeDeletion(head, &head);
                printf("The current state of the List: ");
                show(head);
                break;
            case 8:
                printf("Enter the value to be deleted:---> ");
                scanf("%d", &data);
                delete_a_particular_Node(&head, data);
                break;
            case 9:
                printf("The LIST:\n");
                show(head);
                break;
            case 10:
                free(head);
                printf("[+] Process Ended with code 0");
                exit(0);
            default:
                printf("Wrong choice!");
        }
    }
    while(choice!=10);

}