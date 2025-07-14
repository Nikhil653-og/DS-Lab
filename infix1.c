#include <stdio.h>
#include <string.h>
#include <ctype.h>
int i = -1;
int top = -1, maxsize = 6;
char s[10];
void push(char val)
{
    if (top >= maxsize - 1)
    {
        printf("Stack full");
    }
    else
    {
        top = top + 1;
        s[top] = val;
    }
}
char pop()
{
    char popval;
    if (top == -1)
    {
        printf("Stack is empty");
        return 0;
    }
    else
    {
        popval = s[top];
        top--;
        return popval;
    }
}
int isp(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    else
        return -9;
}
int icp(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 9;
    else if (x == ')')
        return 0;
    else
        return -9;
}
char nextExpression(char str[])
{
    i++;
    return str[i];
}
int isEmpty(char s[])
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void postfix(char str[], int len)
{
    char x;
    push('#');
    x = nextExpression(str);
    while (x != '#')
    {
        if (isalpha(x))
        {
            printf("%c", x);
        }
        else if (x == ')')
        {
            while (s[top] != '(')
            {
                printf("%c", pop());
            }
            pop();
        }
        else
        {
            if (isp(s[top]) >= icp(x))
            {
                pop();
            }
            else
            {
                push(x);
            }
        }
        x = nextExpression(str);
    }

    while (isEmpty(s) != 1)
    {
        char temp = pop();
        if (temp != '#')
        {
            printf("%c", temp);
        }
    }
}
int main()
{
    char str[10];
    int i, j, len;
    printf("Enter the expression:");
    scanf("%s", str);
    len = strlen(str);
    str[len] = '#';
    postfix(str, len);
}