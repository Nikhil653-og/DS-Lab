#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int i = -1, j = 0, k = -1;
int top = -1, top2 = -1, maxsize = 20;
char s[10], s2[20];
char nextExpression2(char str[])
{
    k++;
    return str[k];
}
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
// push 2nd stack
void push2(int s[], char val)
{
    if (top2 >= maxsize - 1)
    {
        printf("Stack full");
    }
    else
    {
        top2 = top2 + 1;
        s[top2] = val;
    }
}
char pop2(int s[])
{
    char popval;
    if (top2 == -1)
    {
        printf("Stack is empty");
        return 0;
    }
    else
    {
        popval = s[top];
        top2--;
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
        return -1;
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
        return -1;
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

void postfixeval(char str[])
{
    int num[20], result_arr[20], digit = 0, m = -1, top2 = -1, result, k = -1;
    char x;

    x = nextExpression2(str);
    while (x != '#')
    {
        if (x != ' ' && isdigit(x))
        {
            while (x != ' ')
            {
                digit = digit * 10 + (x - '0');
                x = nextExpression2(str);
            }
            num[++m] = digit;
            digit = 0;
        }
        else if (x == '+' || x == '-' || x == '*' || x == '/')
        {
            int b = num[m--];
            int a = num[m--];
            switch (x)
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            default:
                printf("Invalid");
            }
            num[++m] = result;
        }

        x = nextExpression2(str);
    }

    for (int p = 0; p < m; p++)
    {
        printf("%d ", num[p]);
    }
    printf("result:%d", num[m]);
}
void postfix(char str[], int len)
{
    char post[25];
    char x;
    push('#');
    x = nextExpression(str);
    while (x != '#')
    {
        if (isalnum(x))
        {
            while (isalnum(x))
            {
                post[j++] = x;
                printf("%c", x);
                x = nextExpression(str);
            }
            post[j++] = ' ';

            continue;
        }

        else if (x == ')')
        {
            while (s[top] != '(')
            {
                char temp = pop();
                post[j++] = temp;
                printf("%c", temp);
            }
            pop();
        }
        else
        {
            while (isp(s[top]) >= icp(x))
            {
                char temp = pop();
                post[j++] = temp;
                printf("%c", temp);
            }
            push(x);
        }
        x = nextExpression(str);
    }
    post[j++] = '\0';
    printf("expression:%s", post);
    while (isEmpty(s) != 1)
    {
        char temp = pop();
        if (temp != '#')
        {
            post[j++] = temp;
            post[j++] = ' ';
            printf("%c", temp);
        }
    }

    post[j++] = '#'; // ✅ important: signal end of expression
    post[j] = '\0';
    k = -1;
    postfixeval(post);
}

int main()
{
    char str[30];
    int i, j, len;
    printf("Enter the expression:");
    scanf("%s", str);
    len = strlen(str);
    str[len] = '#';
    str[len + 1] = '\0';
    postfix(str, len);
}