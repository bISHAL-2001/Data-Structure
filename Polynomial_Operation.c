#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int co;
    int ex;
    struct Node *link;
};

void append(struct Node** head_ref, int coefficient, int exponent)
{
    /*New-Node Creation*/
    struct Node* new_node = (struct Node*)malloc(sizeof (struct Node));
    /*Adding Data to the New Node*/
    new_node -> co = coefficient;
    new_node -> ex = exponent;
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
void add_terms(struct Node *head1,struct Node* head2, struct Node **new_head)
{
    if(head1 == NULL)
    {
        *new_head = head2;
        return ;
    }
    else if(head2 == NULL)
    {
        *new_head = head1;
        return;
    }
    else
    {
        while(head1 != NULL && head2 != NULL)
        {
            if(head1 -> ex >head2 -> ex)
            {
                    append(new_head, head1->co, head1->ex);
                    head1 = head1->link;
            }
            else if(head2 -> ex >head1 -> ex)
            {
                    append(new_head, head2->co, head2->ex);
                    head2 = head2->link;
            }
            else if(head2 -> ex == head1 -> ex)
            {
                append(new_head, ((head1->co) + (head2->co)), head1->ex);
                head1 = head1->link;
                head2 = head2->link;
            }
            else if(head1 -> ex > head2 -> ex && head1 -> link == head2-> link == NULL)
            {

            }
        }
    }
}
void show(struct Node* node)
{


    if(node == NULL)
        printf("Empty!");
    else {
//        printf("|");

        while (node != NULL) {
            if(node -> co != 0) {
//                if (node->ex == 0)
//                    printf(" %d |", node->co);
//                else
//                    printf(" %dy%d |", node->co, node->ex);

                    if(node -> ex == 0) {
                        if (node->link == NULL) {
                            printf("%d", node->co);

                        }
                        else {
                            printf("%d+", node->co);

                        }
                    }
                    else{
                        if (node->link == NULL)
                        {
                            printf("%dy%d", node->co, node->ex);

                        }
                        else {
                            if(node->link->co>0) {
                                printf("%dy%d+", node->co, node->ex);

                            }
                            else {
                                printf("%dy%d", node->co, node->ex);

                            }
                        }
                    }
            }
            node = node->link;
        }

    }

    printf("\n");
    return;
}
int main(void)
{
    struct Node *list1 = NULL, *list2 = NULL, *final_list = NULL;

    char *s;
    s = (char*)malloc(sizeof(char)*100);

    scanf("%s", s);
    int j, k = 0;
    char *n;
    n = (char*)malloc(sizeof(char)*5);


    /* List 1*/
    for(int i = 0; i < strlen(s); i++)
    {
        if((s[i]) >='0' && (s[i]) <= '9')
        {
            n[k] = s[i];
            k++;
        }
        else if(s[i] == 'y')
        {
            int val1, val;
            val1 = strtof(n, &n);
            k = 0;
            i += 1;
            j = 0;
            char *n1;
            n1 = (char*)malloc(sizeof(char)*5);
            while(s[i] >='0' && s[i]<='9')
            {
                n1[j] = s[i];
                j++;
                i++;
            }
            val = strtof(n1, &n1);
            append(&list1, val1, val);
        }


    }

    scanf("%s", s);
    /* List 2*/
    for(int i = 0; i < strlen(s); i++)
    {
        if((s[i]) >='0' && (s[i]) <= '9')
        {
            n[k] = s[i];
            k++;
        }
        else if(s[i] == 'y')
        {
            int val1, val;
            val1 = strtof(n, &n);
            k = 0;
            i += 1;
            j = 0;
            char *n1;
            n1 = (char*)malloc(sizeof(char)*5);
            while(s[i] >='0' && s[i]<='9')
            {
                n1[j] = s[i];
                j++;
                i++;
            }
            val = strtof(n1, &n1);
            append(&list2, val1, val);

        }

    }


    show(list1);
    show(list2);

    add_terms(list1, list2, &final_list);

    show(final_list);
    free(s);
    return 0;
}