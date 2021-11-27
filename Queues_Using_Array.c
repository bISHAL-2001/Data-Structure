#include <stdio.h>
#include <stdlib.h>
int top = -1;
int size = 0;
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
        printf("Element popped out is %d\n", arr[0]);
        arr[0] = 0;
        for(int i=1; i<=top; i++)
        {
            arr[i-1] = arr[i];
            arr[i]=0;
        }
        top--;
    }
}
void print()
{
    printf("Size of Queue is %d\n", size);
    printf("The pointer location at this time is %d.\n", top);
    if(top == -1)
        printf("The Queue is Empty!\n");
    else if(top < size) {
        if(top == size-1)
            printf("The Queue is Full!!");
        printf("The elements of the queue are:\n| ");
        for(int i = 0; i<=top; i++)
            printf("%d | ", arr[i]);
        printf("\n");
    }
}
int main(void)
{
    printf("Enter the size of the queue:");

    scanf("%d", &size);

    arr = (int*)calloc(size, sizeof(int));
    printf("A stack of Size = %d has been created.\n", size);

    int choice;
    char ch[10] = "y";
    while(ch[0] == 'Y'|| ch[0] == 'y')
    {
        printf("Press: 1 to push\nPress: 2 to pop\nPress: 3 to check the status of the Queue\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                print();
                break;
            default:
                printf("Sorry wrong input!\nThe current status of the QUEUE is:\n");
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
