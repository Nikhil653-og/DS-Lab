#include <stdio.h>
#include <stdlib.h>
int stack[4], top = -1, maxSize = 4;
void push(int val)
{
    if (top >= maxSize - 1)
    {
        printf("Stack is full");
    }
    else
    {
        top = top + 1;
        stack[top] = val;
    }
}
int pop()
{
    int popvalue;
    if (top == -1)
    {
        printf("Stack is empty");
        return 0;
    }
    else
    {
        popvalue = stack[top];
        top = top - 1;
        return popvalue;
    }
}
int main()
{
    int ch, val;
    while (1)
    {
        printf("Enter a choice \n1.Push\n2.Pop\n3.Exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter number to push:");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice");
        }
    }
}