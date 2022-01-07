#include <stdio.h>
#include <stdlib.h>

void push(int *arr, int stack_choice, int input, int *p)
{
    if(stack_choice == 1)
    {
        (*p)++;
        arr[*p] = input;
    }
    else if(stack_choice == 2)
    {
        (*p)--;
        arr[*p] = input;
    }
}

void pop(int stack_choice, int *arr, int *p)
{
    if(stack_choice==1)
    {
        if(*p == -1)
        {
            printf("Underflow!");
            return;
        }
        printf("[-] Data popped from STACK1 : %d.\n", arr[*p]);
        arr[*p] = 0;
        (*p)--;
    }
    else if(stack_choice==2)
    {
        if(*p == 49)
        {
            printf("Underflow!");
            return;
        }
        printf("[-] Data popped from STACK2 : %d.\n", arr[*p]);
        arr[*p] = 0;
        (*p)++;
    }
}

void show(int stack_choice, int *arr, int p)
{
    if(stack_choice==1)
    {
        if(p == -1)
        {
            printf("Stack Empty!");
            return;
        }
        else if(p == 49)
        {
            printf("Stack Full!");
        }
        printf("[+] STACK 1:\n[+] ");
        for(int i = p; i >= 0; i--)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else if(stack_choice == 2)
    {
        if(p == 0)
        {
            printf("Stack Full!");
            return;
        }
        else if(p == 50)
        {
            printf("Stack Empty!");
        }
        printf("[+] STACK 2:\n[+] ");
        for(int i = p; i <= 49; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
int main(void)
{
    int *arr;
    arr = (int*)calloc(50, sizeof(int));

    printf("[+] 2 stacks can hold a total of 50 elements.\n");
    printf("[+] Input Format:\n[+]\t\tStack_Number Input_Element\n");

    char flag[2] = "";

    int stack1 = -1;
    int stack2 = 50;
    int counter = 0;

    printf("[+] INPUT:\n");
    do {
        int stack_choice;
        int input;

        scanf("%d %d", &stack_choice, &input);
        if(stack_choice == 1) {
            push(arr, stack_choice, input, &stack1);
            counter++;
        }
        else if(stack_choice == 2) {
            push(arr, stack_choice, input, &stack2);
            counter++;
        }
        else
            printf("\n[-] Sorry operation unsuccessful!\n");

        if(counter >= 50)
            break;

        printf("\nWanna stop? type 'Y' else type 'N'  ---->");
        scanf("%s", flag);
    }
    while(flag[0] != 'Y');
    show(1, arr, stack1);
    show(2, arr, stack2);

    printf("Pointers' current location: %d %d.\n", stack1, stack2);
    pop(1, arr, &stack1);
    pop(2, arr, &stack2);
    pop(2, arr, &stack2);
    show(1, arr, stack1);
    show(2, arr, stack2);
    printf("Pointers' current location: %d %d.\n", stack1, stack2);

    arr = NULL;
    free(arr);
    return 0;
}