#ifndef INSEARCH
#define INSEARCH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 1
#define FAILURE -1
#define DATA_NOT_FOUND 2

typedef enum 
{
    DB_EMPTY,
    DB_CREATED,
    DB_UPDATED
} db_state;

typedef struct file_node 
{
    char f_name[30];
    struct file_node *link;
} f_list;

typedef struct main_node 
{
    int file_count;
    char word[30];
    struct main_node *main_link;
    struct sub_node *sub_link;
} m_node;

typedef struct sub_node 
{
    int word_count;
    char file_name[30];
    struct sub_node *s_sub_link;
} s_node;

typedef struct create_database 
{
    int key;
    m_node *m_link;
} c_db;

// Function Prototypes//
int read_and_validate(int argc, char *argv[], f_list **head);
int store_word(c_db *hash_table, char *word, int index, char *filename);
int open_files(char *argv);
int create_database(f_list *head, c_db *arr);
int display_database(c_db *hash_t);
int search_database(c_db *hash_table, char *word);
int update_database(c_db *hash_t);
int save_database(c_db *hash_t);
int get_hash_index(char ch);

#endif