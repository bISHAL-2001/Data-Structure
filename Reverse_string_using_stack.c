#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack
{
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (char*)malloc(stack -> capacity * sizeof(char));
    return stack;
}
bool isFull(struct Stack*stack)
{
    if(stack->top==stack->capacity-1)
        return true;
    return false;
}

bool isEmpty(struct Stack*stack)
{
    if(stack->top==-1)
        return true;
    return false;
}

void push(struct Stack* stack, char ch)
{
    if(isFull(stack))
        return;
    else
        stack->array[++stack->top] = ch;

}

char pop(struct Stack* stack)
{
    char ch = ' ';
    if(isEmpty(stack) == false)
        ch = stack->array[stack->top];

    stack->array[stack->top--] = ' ';
    return ch;
}

int main(void)
{

    struct Stack* stack = NULL;

    char *s;
    s = (char*) malloc(sizeof(char)*100);
    printf("Enter the string to reverse:-->");
    scanf("%[^\n]s", s);
    int len = strlen(s);
    int size = len-1;
    while(size!=0) {
        if(s[size--] != 32) {
            break;
        }
        len -= 1;
    }
    int i=0;
    while(i<len)
    {
        if(s[i] != 32)
            break;

        i++;
    }
    stack = createStack(len);
    int nSize = len-i;

    char *ns;
    ns = (char*) calloc(sizeof(char), (nSize));

    for(; i<len; i++)
    {
        push(stack, s[i]);
    }

    for(i=0; i<nSize; i++)
    {
        ns[i] = pop(stack);
    }

    printf("%d %d\n", len, nSize);
    printf("The Original string:\n\"%s\"\n", s);
    printf("The Reversed string:\n\"%s\"\n", ns);
    free(stack);
    free(ns);
    free(s);
}