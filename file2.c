#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;
void unload(node **list);
int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 5; i++)
    {
        node *n = malloc(sizeof(node));
        printf("enter a random number: ");
        scanf("%i", &(n->value));
        n->next = NULL;

        if (list == NULL)
        {
            list = n;
        }
        else if (list->value >= n->value)
        {
            n->next = list;
            list = n;
        }
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
                else if (ptr->next->value > n->value)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                }
            }
        }
    }
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i->", ptr->value);
    }
    unload(&list);
}

void unload(node **list)
{
    node *ptr = malloc(sizeof(node));
    ptr = *list;
    while (ptr != NULL)
    {
        node *temp = ptr->next;
        free(ptr);
        ptr = ptr->next;
    }
}
