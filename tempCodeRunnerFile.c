

void load_dict(char *file_name)
{
    FILE *dict = fopen(file_name, "r");
    unsigned char *word;
    fscanf(dict, "%[^,]", word);
}