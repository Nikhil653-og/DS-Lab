#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *new, *header, *temp;
void addNode(int data)
{
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    if (header == NULL)
    {
        header = new;
    }
    else
    {
        temp = header;
        while (temp->next != NULL)
        {

            temp = temp->next;
        }
        temp->next = new;
    }
}
void display()
{
    temp = header;
    while (temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}
int main()
{
    int ch, data;
    while (1)
    {
        printf("\nEnter choice\n1.Add node\n2.Display\n3.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter number:");
            scanf("%d", &data);
            addNode(data);
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Error");
        }
    }
    free(new);
    free(header);
}