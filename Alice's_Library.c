#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char data;
    struct Node* link;
};

void push(char ch, char *s, int *pointer)
{

}
void pop(char *s, int *pointer)
{

}
void LastNodeDeletion(struct Node *head, struct Node** head_ref, struct Node* p)
{
    struct Node *toDelLast, *preNode = NULL;
    if(head == NULL)
    {/*show(head);*/}
    else if(head->link == NULL)
    {
        struct Node* new_head = NULL;
        push(head->data, )
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

void reverse(char *s)
{

    for(int i=strlen(s)-1; i>=strlen(s)/2; i--)
    {
        int tmp = s[i];
        s[i] = s[strlen(s)-i-1];
        s[strlen(s)-i-1] = tmp;
    }
}
int main(void)
{
    char *s;
    s = (char*)malloc(100*sizeof(char));
    scanf("%s", s);
    int l = strlen(s);

    if(s[0] == '/' && s[l-1] == '\\')
    {

        struct Node *tmp = NULL;

        for(int i = 0; i<l; i++)
        {
            if(i!=0 && s[i] == '/')
                while(tmp != NULL)
                {
                    LastNodeDeletion(tmp, &tmp);
                }
        }
    }
    s = NULL;
    free(s);
    return 0;
}