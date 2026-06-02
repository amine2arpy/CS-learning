#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node
{
    void *value;
    struct node *next;
    struct node *prev;
} node;

typedef struct
{
    node *head;
    node *tail;
} linkedlist;

// the prototype of functions in case i use them before creating them
void *get(linkedlist *list);
void insert(linkedlist *list, void *item);
void init_list(linkedlist *list);

// initlize the linked list
void init_list(linkedlist *list)
{
    list->head = NULL;
    list->tail = NULL;
}
// insertation function , i had a bad time with this one but hollyshit it is working
void insert(linkedlist *list, void *item)
{
    node *temp = malloc(sizeof(node));
    temp->value = item;
    temp->next = list->head;
    if (list->head == NULL)
    {
        list->head = temp;
        list->tail = temp;
    }
    else
    {
        list->head->prev = temp;
        list->head = temp;
    }

    temp = NULL;
}

// this inserts the value the delete it from the list in queue fashion
void *get(linkedlist *list)
{
    if (list->tail == NULL)
    {
        printf("its empty...");
        exit(1);
    }
    else
    {
        node *temp;
        temp = list->tail;
        list->tail = list->tail->prev;
        temp->prev->next = NULL;
        temp->prev = NULL;

        void *item = temp->value;

        free(temp);

        if (list->tail == NULL)
        {
            list->head = NULL;
        }
        return item;
    }
}

// testing
int main(void)
{
    linkedlist list;
    init_list(&list);
    char *item1 = "negga";
    char *item2 = "hell";
    char *item3 = "boody";
    insert(&list, &item1);
    insert(&list, &item2);
    insert(&list, &item3);
}

// int main(void)
// {
//     node *list = NULL;
//     node *ptr = NULL;

//     append(&list, &ptr);
//     for (node *point = list; point != NULL; point = point->next)
//     {
//         printf("%i ->", point->value);
//     }
//     printf("\n");
// }

// void append(node *list, node *ptr)
// {
//     int decision;
//     printf("how many things do you to add: ");
//     scanf("%i", &decision);
//     if (decision == 0)
//     {
//         return;
//     }

//     for (int i = 0; i <= decision; i++)
//     {
//         node *temp = malloc(sizeof(node));
//         temp->value = i;
//         temp->next = list;

//         ptr = temp;
//         if (ptr->next == NULL)
//         {
//             while (1)
//             {
//                 if (ptr->next->next == NULL)
//                 {
//                     ptr->next->next = temp;
//                     break;
//                 }
//                 else
//                 {
//                     ptr = ptr->next;
//                 }
//             }
//         }
//     }
// }
