/*Problem
Alice is rearranging her library. She takes the innermost shelf and reverses the order of books. She breaks the walls of the shelf. In the end, there will be only books and no shelf walls. Print the order of books.

Opening and closing walls of shelves are shown by '/' and '\' respectively whereas books are represented by lower case alphabets.

Input format

The first line contains string  displaying her library.

Output format

Print only one string displaying Alice's library after rearrangement.

Constraints


Note

The first character of the string is '/' and the last character of the string is '\' indicating outermost walls of the shelf.

Sample Input
/u/love\i\
Sample Output
iloveu
Time Limit: 2
Memory Limit: 256
Source Limit:
Explanation
/u/love\i\

Here Katrina breaks the innermost shelf and reverse the order. So the library will be  /uevoli\ .

Now she breaks the outermost wall and reverses the order. So the library will be iloveu.*/


/*Code*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char *per, char input, int *pointer1)
{
    (*pointer1) ++;
    per[(*pointer1)] = input;
}
void del(char *tmp, char *per, int *pointer, int *pointer1)
{
    if(*pointer != -1)
    {
        int i = 0;
        while(*pointer != -1)
        {
            push(per, tmp[i], pointer1);
            tmp[i++] = ' ';
            (*pointer)--;
        }
    }
}
void pop(char *tmp, char *per, int *pointer, int *pointer1)
{
    if(*pointer != -1)
    {
        while(*pointer != -1)
        {
            push(per, tmp[*pointer], pointer1);
            tmp[*pointer] = ' ';
            (*pointer) --;
        }
    }
}
void show(char *s, int pointer)
{
    for(int i = pointer; i>=0; i--)
        printf("%c", s[i]);
}
int main(void)
{
    char *s = (char*)malloc(100*sizeof(char));
    char *tmp = (char*)malloc(50*sizeof(char));
    char *per = (char*)malloc(70*sizeof(char));

    int pointer = -1;
    int pointer1 = -1;
    printf("%s", "[+] Enter the expression:--->");
    scanf("%s", s);

    if(s[0] == '/' && s[strlen(s) - 1] == '\\')
    {
        for(int i = 0; i<strlen(s); i++)
        {
            char ch = s[i];
            if(ch == '/')
                del(tmp, per, &pointer, &pointer1);
            else if(ch == '\\')
                pop(tmp, per, &pointer, &pointer1);
            else
                push(tmp, ch, &pointer);
        }
        printf("[+] Output:--->");
        show(per, pointer1);
    }
}