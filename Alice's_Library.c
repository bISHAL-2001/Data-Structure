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