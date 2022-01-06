#include <stdio.h>
#include <stdlib.h>

void push(int input, int *arr, int *t, int *c)
{

        (*t)++;
        arr[*t] = input;
        (*c)++;

}

void pop(int point, int *arr, int *t)
{
    arr[point] = 0;
    (*t)--;
}

void show(int *arr, int s1, int s2, int sizeOfStack1)
{
    printf("STACK 1:\n>> ");
    for(int i = s1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\nSTACK 2:\n>> ");
    for(int i = s2; i >= sizeOfStack1; i--)
    {
        printf("%d ", arr[i]);
    }
}

int main(void)
{
    int size;
    int stack1;
    int stack2;
    printf("Enter the size of the 1st stack:");
    scanf("%d", &stack1);

    printf("Enter the size of the 2nd stack:");
    scanf("%d", &stack2);

    size = stack1 + stack2;

    int top1 = -1;
    int counter1 = 0;
    int top2 = stack1-1;
    int counter2 = 0;

    int *arr;
    arr = (int*)calloc(size, sizeof(int));

    printf("    (Format of input should be: STACK_NUMBER INPUT_NUMBER)\n\texample:\n\t2 6\n\t1 7\n\t1 8\n\t2 9");
    printf("\n[+] INPUT:\n");

    for(int i = 0; i < size; )
    {
        int stack_choice;
        int input;
        scanf("%d %d", &stack_choice, &input);
        if(stack_choice == 1 && counter1 < stack1){
            push(input, arr, &top1, &counter1);
            i++;
        }
        else if(stack_choice == 2 && counter2 < stack2) {
            push(input, arr, &top2, &counter2);
            i++;
        }
        else
            printf("[-] ----> Sorry Input not possible!\n");
    }
    printf("\n\n[+] OUTPUT:\n");
    show(arr, top1, top2, stack1);

    printf("\n[+] You can perform 2 pop operations.\n\tInput pattern for pop is -> STACK_NUMBER\n");

    counter1 = 0;
    stack2 = 0;

    while(stack2 < 2)
    {
        printf("[+] Enter the stack number:");
        counter2 = 0;
        scanf("%d", &counter2);
        if(counter2 == 1)
        {
            pop(top1, arr, &top1);
            stack2 ++;
        }
        else if(counter2 == 2) {
            pop(top2, arr, &top2);
            stack2 ++;
        }
    }

    printf("\n[+] OUTPUT:\n");
    show(arr, top1, top2, stack1);

    arr = NULL;
    free(arr);
}