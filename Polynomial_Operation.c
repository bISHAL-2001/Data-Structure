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
}
int main(void)
{
    struct Node *list1 = NULL, *list2 = NULL, *final_list = NULL;

//    char *s, *s1;
//    s = (char*)malloc(sizeof(char)*100);
//    s1 = (char*)malloc(sizeof(char)*100);
//
//
//    scanf("%s", s);
//    scanf("%s", s1);
//    int sl1 = strlen(s);
//    int sl2 = strlen(s);
//    int  k =0;
//
//
//    for(int i = 0; i<sl1; i++)
//    {
//        char *temp;
//        temp = (char*) malloc(sizeof(char)*10);
//        if(s[i] >= '0' && s[i] <= '9')
//        {
//            temp[k++] = s[i];
//        }
//        else if(s[i] == 'y')
//        {
//            k = 0;
//            printf("%s", temp);
//        }
//    }
    char s[] = "12y4-3y3+2y2+6";
    int ls1 = strlen(s);

    char *n = (char*) malloc(sizeof (char)*(ls1+1));
    for(int i=0; i<ls1; i++)
    {
        int j = 0;
        int val;
        while(s[i]>= '1' && s[i] <= '9')
        {
            n[j++]= s[i++];
        }
        if(s[i] == 'y')
        {
            val = (int) (strtof(n, &n));
            int val1 = 0;
            char *temp = (char*) malloc((100));
            j = 0;
            i+=1;
            while(s[i]>= '1' && s[i] <= '9')
            {
                temp[j++] = s[i++];
            }
            val1 = (int)(strtof(temp, &temp));
            if(val!=0 && val1 != 0)
                printf("%d %d\n", val, val1);
            else if(val != 0 )
                printf("%d 1\n", val);
        }
    }
    printf("%s", n);

}