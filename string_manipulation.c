#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *s;
    s = (char*)malloc(sizeof(char)*100);

    scanf("%s", s);
    int j, k = 0;
    char *n;
    n = (char*)malloc(sizeof(char)*5);
    printf("%ld\n", strlen(s));
    for(int i = 0; i < strlen(s); i++)
    {
        if((s[i]) >='0' && (s[i]) <= '9')
        {
            n[k] = s[i];
            k++;
        }
        else if(s[i] == 'y')
        {
            int val;
            val = strtof(n, &n);
            printf("Co-Efficient = %d\n",val);
            k = 0;
            i += 1;
            j = 0;
            char *n1;
            n1 = (char*)malloc(sizeof(char)*5);
            while(s[i] >='0' && s[i]<='9')
            {
                n1[j] = s[i];
                j++;
                i++;
            }
            val = strtof(n1, &n1);
            printf("Exponent = %d\n",val);
        }

    }
    free(s);
    return 0;
}