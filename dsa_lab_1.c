// first non repeating value
#include <stdio.h>
#include <string.h>
char nonrepeating(char str[], int len)
{
    int i, j, count, a;
    char b;
    for (i = 0; i < len; i++)
    {
        count = 0;
        for (j = 0; j < len; j++)
        {
            if (str[i] == str[j])
            {
                count++;
            }
        }
        if (count == 1)
        {
            b = str[i];
            break;
        }
        else
        {
            b = '$';
        }
    }
    return b;
}
int main()
{
    int i, j;
    char str1[] = "racecdar";
    int len = strlen(str1);
    printf("%c", nonrepeating(str1, len));
}