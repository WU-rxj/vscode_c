#include<stdio.h>
#include<string.h>

int main()
{
    char stack[300];
    char input[300];
    scanf("%s",input);
    int len = strlen(input);
    int top=0;
    for (int i=0;i<len;i++)
    {
        if (input[i]=='(' || input[i]=='[')
        {
            stack[top++]=input[i];
        }
        else if (input[i]==')')
        {
            if (top<0 || stack[top-1]!='(')
            {
                printf("Wrong");
                return 0;
            }
            top--;
        }
        else if (input[i]==']')
        {
            if (top<0 || stack[top-1]!='[')
            {
                printf("Wrong");
                return 0;
            }
            top--;
        }
        if (top<0)
        {
            printf("Wrong");
            return 0;
        }
    }
    if (top!=0)
    {
        printf("Wrong");
        return 0;
    }
    printf("OK");
    return 0;
}