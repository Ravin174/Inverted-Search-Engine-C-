/*
Name: RAVIN J S
Student ID: 25021_387
Date of submission :6th JAN 2026. 
Description:    This project implements an Inverted Search engine in C, which optimizes text retrieval by 
    mapping unique words to the specific files and locations where they occur. It utilizes a Hash Table with 28
    buckets to store word data, ensuring efficient indexing of alphabetic characters, digits, and special symbols.
    The core architecture features a nested linked-list structure consisting of Main Nodes for unique words and Sub Nodes 
    for tracking word frequency across multiple source files. The program provides an interactive menu for users to
    create a database from text files, search for specific terms, and save or update the database from a backup.
    Designed for high performance, the system effectively manages memory while providing structured output for complex
    data relationships.
*/

#include "insearch.h"

int main(int argc, char *argv[])
{
    // User-selected menu option//
    int option;

    // Head of the input file list//
    f_list *head = NULL;

    // Current database state (empty, created, etc.)//
    db_state state = DB_EMPTY;

    // Hash table used for the database (indexed by letter)//
    c_db hash_table[28]; 

    // Initialize hash table entries
    for (int i = 0; i < 28; i++) {
        hash_table[i].key = i;    // store bucket key/index
        hash_table[i].m_link = NULL; // no entries yet
    }

    // Require at least one input file argument
    if (argc < 2) {
        printf("Usage: ./invsearch <file1.txt> <file2.txt> <...>\n");
        return FAILURE;
    }

    // Read and validate input files into `head`//
    if (read_and_validate(argc, argv, &head) != SUCCESS) 
    {
        return FAILURE;
    }

    // Main interactive loop
    while(1) {
        // Display menu options
        printf("\n1. Create Database\n"
                 "2. Display Database\n"
                 "3. Search Datsbase\n"
                 "4. Update Database\n"
                 "5. Save Database\n"
                 "6. Exit\n"
                 "Enter your Choice: ");

        // Read the user's menu choice (default to 0 on failure)
        if (scanf("%d", &option) != 1) option = 0;

        switch (option) {

            case 1:
                // Create the database from the input list if not already created
                if (state == DB_EMPTY) {
                    if (create_database(head, hash_table) == SUCCESS) {
                        state = DB_CREATED;
                        printf("SUCCESS: Full database creation from file list complete.\n");
                    }
                } else {
                    printf("WARNING: Database already exists. Operation cancelled.\n");
                }
                break;
            case 2:
                // Display current database contents
                display_database(hash_table);
                break;
            case 3:
                // Search the database for a given word
                if (state != DB_EMPTY) {
                    char word[30];
                    printf("Enter the word to search: ");
                    scanf("%s", word);
                    search_database(hash_table, word);
                } else {
                    // Prompt to create DB first
                    printf("Error: Database is empty. Create it first.\n");
                }
                break;
            case 4:
                if (state == DB_EMPTY) {
                    if (update_database(hash_table) == SUCCESS) {
                        state = DB_UPDATED;
                        printf("SUCCESS: Database updated from backup file.\n");
                    } else {
                        printf("ERROR: Failed to update database.\n");
                    }
                } else {
                    printf("ERROR: Update is only allowed on an empty database (before creation).\n");
                }
                break;
            case 5:
                // Save database functionality placeholder
                if(save_database(hash_table) == FAILURE){
                    printf("Error: Database not saved.\n");
                } else {
                    printf("Database Saved\n");
                }
                break;
            case 6:
                // Exit the program successfully
                return SUCCESS;
        }
        // Consume leftover newline or input characters
        getchar(); // clear buffer
    }

    return SUCCESS;
}