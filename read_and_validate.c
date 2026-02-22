#include "insearch.h"

int read_and_validate(int argc, char *argv[], f_list **head) 
{
    for (int i = 1; i < argc; i++) 
    {
        // Check if file exists and is not empty //
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("Error: File %s does not exist or cannot be opened.\n", argv[i]);
            continue;
        }
        
        fseek(fp, 0, SEEK_END);
        if (ftell(fp) == 0) 
        {
            printf("Error: File %s is empty. Skipping.\n", argv[i]);
            fclose(fp);
            continue;
        }
        fclose(fp);

        // Add to linked list of files//
        f_list *new_file = malloc(sizeof(f_list));
        strcpy(new_file->f_name, argv[i]);
        new_file->link = *head;
        *head = new_file;
    }

    return (*head != NULL) ? SUCCESS : FAILURE;
}