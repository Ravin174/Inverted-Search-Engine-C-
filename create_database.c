#include "insearch.h"

int create_database(f_list *head, c_db *hash_table) 
{
    f_list *curr_file = head;

    while (curr_file != NULL) 
    {
        FILE *fptr = fopen(curr_file->f_name, "r");
        if (fptr == NULL) {
            printf("Error: Could not open %s\n", curr_file->f_name);
            curr_file = curr_file->link;
            continue;
        }

        char word[30];
        while (fscanf(fptr, "%s", word) == 1)
        {
            // Get index (0-25 for a-z, 26 for digits, 27 for others)//
            int index = get_hash_index(word[0]);
            
            // Logic to store word in the hash table
            store_word(hash_table, word, index, curr_file->f_name);
        }
        
        fclose(fptr);
        printf("Successful: Creation of database for file: %s\n", curr_file->f_name);
        curr_file = curr_file->link;
    }
    return SUCCESS;
}

int get_hash_index(char ch) 
{
    if (isalpha(ch)) return tolower(ch) - 'a';
    if (isdigit(ch)) return 26;
    return 27;
}