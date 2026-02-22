#include "insearch.h"

int store_word(c_db *hash_table, char *word, int index, char *filename)
{
    // 1. If the index is empty, create the first main node//

    if (hash_table[index].m_link == NULL) {
        m_node *new_m = malloc(sizeof(m_node));
        s_node *new_s = malloc(sizeof(s_node));

        strcpy(new_m->word, word);
        new_m->file_count = 1;
        new_m->main_link = NULL;
        new_m->sub_link = new_s;

        strcpy(new_s->file_name, filename);
        new_s->word_count = 1;
        new_s->s_sub_link = NULL;

        hash_table[index].m_link = new_m;
        return SUCCESS;
    }

    // 2. Search if word already exists in this index

    m_node *m_curr = hash_table[index].m_link;
    m_node *m_prev = NULL;

    while (m_curr != NULL)
    {
        if (strcmp(m_curr->word, word) == 0) 
        {
            // Word found, check sub_nodes for the filename//
            s_node *s_curr = m_curr->sub_link;
            s_node *s_prev = NULL;

            while (s_curr != NULL) 
            {
                if (strcmp(s_curr->file_name, filename) == 0) {
                    s_curr->word_count++;
                    return SUCCESS;
                }
                s_prev = s_curr;
                s_curr = s_curr->s_sub_link;
            }
            // New file for an existing word //

            s_node *new_s = malloc(sizeof(s_node));
            strcpy(new_s->file_name, filename);
            new_s->word_count = 1;
            new_s->s_sub_link = NULL;
            s_prev->s_sub_link = new_s;
            m_curr->file_count++;
            return SUCCESS;
        }
        m_prev = m_curr;
        m_curr = m_curr->main_link;
    }

    // 3. New word for this index//
    
    m_node *new_m = malloc(sizeof(m_node));
    s_node *new_s = malloc(sizeof(s_node));
    
    strcpy(new_m->word, word);
    new_m->file_count = 1;
    new_m->main_link = NULL;
    new_m->sub_link = new_s;

    strcpy(new_s->file_name, filename);
    new_s->word_count = 1;
    new_s->s_sub_link = NULL;
    
    m_prev->main_link = new_m;
    return SUCCESS;
}