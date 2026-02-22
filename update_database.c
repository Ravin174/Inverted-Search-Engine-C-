#include "insearch.h"

int update_database(c_db *hash_t) 
{
    char filename[30];
    printf("Enter the backup file to load: ");
    scanf("%s", filename);

    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) 
    {
        printf("Error: File %s not found.\n", filename);
        return FAILURE;
    }

    char line[500];
    while (fgets(line, sizeof(line), fptr)) 
    {
        if (line[0] != '#') continue;

        char *token = strtok(line, "#;");
        int index = atoi(token);
        
        token = strtok(NULL, "#;"); 
        char word[30];
        strcpy(word, token);
        
        token = strtok(NULL, "#;"); 
        int f_count = atoi(token);

        for (int i = 0; i < f_count; i++) 
        {
            token = strtok(NULL, "#;"); 
            char f_name[30];
            strcpy(f_name, token);
            
            token = strtok(NULL, "#;"); 
            int w_count = atoi(token); // Variable is now retrieved

            for (int j = 0; j < w_count; j++)
            {
                store_word(hash_t, word, index, f_name);
            }
        }
    }

    fclose(fptr);
    return SUCCESS;
}