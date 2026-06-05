#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
const char lower_c[] = {'a', 'b', 'c', 'd', 'e',
                        'f', 'g', 'h', 'i', 'j',
                        'k', 'l', 'm', 'n', 'o',
                        'p', 'q', 'r', 's', 't',
                        'u', 'v', 'w', 'x', 'y',
                        'z'};

typedef struct node
{
    struct node *array[26];
    char value;
} node;

char *hash(char *string)
{
    int length = strlen(string);
    char *array = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++)
    {
        char ch = tolower(string[i]);
        int num = 0;
        char *cont = malloc(sizeof(char) * 2);
        num = (int)ch - (int){'a'};
        sprintf(cont, "%d", num);
        array[i] = *cont;
    }
    return array;
}

void load_dict(char *file_name)
{
    FILE *dict = fopen(file_name, "r");
    char word[100];
    while (fscanf(dict, "%[^,]", word) == 1)
    {
        char *list = hash(word);
        printf("%s", word);
        getc(dict);
    }
}

int main(int argc, char *argv[])
{
    load_dict(argv[1]);
}