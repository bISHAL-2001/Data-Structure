#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (int*)malloc(stack -> capacity * sizeof(int));
    return stack;
}
bool isEmpty(struct Stack *ps)
{
    if(ps -> top == -1)
        return true;
    else
        return false;
}

bool isFull(struct Stack *ps)
{
    return (ps -> top == ps -> capacity-1)?true:false;
}

void push(struct Stack* stack, int n)
{
    stack->array[++stack->top] = n;
    printf("%s", "Push Successful!");
}

void pop(struct Stack* stack)
{
    stack->array[stack->top] = 0;
    stack->top=stack->top-1;
    printf("%s", "Pop Successful!");
}

void show(struct Stack* stack)
{
    printf("The STACK:\n| ");
    for(int i=0; i<=stack ->top; i++)
    {
        printf("%d | ", stack->array[i]);
    }
}
int main(void)
{
    struct Stack* stack = createStack(100);

    printf("A stack of Size 100 has been predefined!");
    char c=' ';
    printf("\nDo you want to resize it? (Press Y for YES or N for NO)\n-->");

    do{
        scanf("%c", &c);
        if(c == 'Y')
        {
            printf("Enter the new size for allocation: --> ");
            int size;
            scanf("%i", &size);
            stack = createStack(size);
            printf("The stack has been reinitialized to a size of %d.\n", size);
            break;
        }
        else if(c == 'N')
        {
            break;
        }
        else {
            printf(" Re-Enter your choice!\n-->");
        }
        scanf("%c", &c);
    }
    while(c!='N');

    printf("The options for the STACK OPERATION:\n1. PUSH\n2. POP\n3. SHOW\n4. EXIT");
    int n = 0;
    while(sizeof(n)==sizeof(int))
    {
        printf("\nEnter your choice:\n-->");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                if (isFull(stack))
                    printf("%s", "OverFlow Condition has occurred!\n");
                else {
                    printf("Enter the number to push:\n-->");
                    int num;
                    scanf("%d", &num);
                    push(stack, num);
                }
                break;
            case 2:
                if (isEmpty(stack))
                    printf("%s", "UnderFlow Condition has occurred!\n");
                else {
                    pop(stack);
                }
                break;
            case 3:
                if (isFull(stack))
                    printf("The stack is Full!\n");
                else if (isEmpty(stack))
                    printf("The stack is EMPTY!\n");
                else
                    show(stack);
                break;
            case 4:
                printf("\n[+] PROCESS TERMINATED!");
                exit(0);
            default:
                printf("[-] WRONG INPUT!\n");
                break;
        }

    }
}