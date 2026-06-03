#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} node;
int search(node *list, int value);
void append(node *tree, node *n);

int main(void)
{
    node *tree = NULL;
    for (int i = 0; i < 10; i++)
    {
        node *temp = malloc(sizeof(node));
        printf("what the value: ");
        scanf("%i", &(temp->value));
        temp->left = NULL;
        temp->right = NULL;

        append(&tree, &temp);
    }
    search(tree, 1);
}

void append(node *tree, node *n)
{
    if (tree == NULL)
    {
        tree = n;
        return;
    }
    else
    {
        node *ptr = tree;
        if (n->value < ptr->value)
        {
            ptr = ptr->right;
            return append(&ptr, n);
        }
        else if (n->value > ptr->value)
        {
            ptr = ptr->left;
            return append(&ptr, n);
        }
    }
}

int search(node *list, int value)
{
    if (list == NULL)
    {
        printf("not found\n");
        return 1;
    }
    else if (value < list->value)
    {
        node *ptr;
        ptr = list->left;
        return search(ptr, value);
    }
    else if (value > list->value)
    {
        node *ptr;
        ptr = list->right;
        return search(ptr, value);
    }
    else
    {
        printf("found\n");
        return 0;
    }
}