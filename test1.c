#include<stdio.h>
#include<stdlib.h>

// Structure of node.

struct Node
{
    int data;
    struct Node *link;
};


//  deleting the duplicate nodes.


void remove_duplicate(struct Node *head)
{
    struct Node *current = head,*index = NULL,*temp = NULL;
    if(head == NULL)
        return;
    else
    {
        while(current != NULL)      // do till the linked list is empty.
        {
            temp = current;
            index = current -> link;

            while(index != NULL)
            {
                if(current -> data == index -> data)
                    temp -> link = index -> link;
                else
                    temp = index;

                index = index -> link;
            }
            current = current -> link;
        }
    }
}


// inserting the nodes at end.


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

// Displaying the list.
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

int main()
{
    struct Node *head = NULL;

    int n,num;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num);
        append(&head, num);
    }

    remove_duplicate(head);
    show(head);
    free(head);
    return 0;
}