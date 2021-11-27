#include <stdio.h>
#include <stdlib.h>
int top = -1, size = 0;
int* arr;
char *condition = " ";
void push ()
{
    if(top == size-1)
        printf("OverFlow Condition has been encountered!!\n");
    else
    {
        printf("Enter the integer to push:");
        int input;
        scanf("%d", &input);
        top++;
        arr[top] = input;
    }
}
void pop ()
{
    if(top == -1)
        printf("UnderFlow Condition has been encountered!!\n");
    else
    {
        printf("Element popped out is %d\n", arr[top]);
        arr[top] = 0;
        top--;
    }
}
void peek()
{
    printf("The top element: %d", arr[top]);
    printf("\nPointer at %d\n", top);
}
void print()
{
    printf("Size of Stack is %d\n", size);
    printf("The pointer location at this time is %d.\n", top);
    if(top == -1)
        printf("The Stack is Empty!\n");
    else if(top < size) {
        if(top == size-1)
            printf("The Stack is Full!!");
        printf("The elements of the stack are:\n| ");
        for(int i = 0; i<=top; i++)
            printf("%d | ", arr[i]);
        printf("\n");
    }
}
int main(void)
{
    printf("Enter the size of the stack:");

    scanf("%d", &size);

    arr = (int*)calloc(size, sizeof(int));
    printf("A stack of Size = %d has been created.\n", size);

    int choice;
    char ch[10] = "y";
    while(ch[0] == 'Y'|| ch[0] == 'y')
    {
        printf("Press: 1 to push\nPress: 2 to pop\nPress: 3 to Peek\nPress: 4 to check the status of the Stack\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                print();
                break;
            default:
                printf("Sorry wrong input!\nThe current status of the STACK is:\n");
                print();
                break;
        }
        printf("Do you wanna continue? Type 'Y' or 'y' to continue\nInput --->");
        scanf("%s", ch);
    }
    printf("Process ended!!");
    free(arr);
    free(condition);
    return 0;
}
