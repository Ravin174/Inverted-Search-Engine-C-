#include "insearch.h"

int search_database(c_db *hash_table, char *word) 
{
    int index = get_hash_index(word[0]);
    m_node *m_temp = hash_table[index].m_link;

    while (m_temp != NULL) 
    {
        if (strcmp(m_temp->word, word) == 0) 
        {
            printf("Word '%s' found in %d file(s):\n", word, m_temp->file_count);
            s_node *s_temp = m_temp->sub_link;
            while (s_temp) 
            {
                printf("In file: %s | Count: %d\n", s_temp->file_name, s_temp->word_count);
                s_temp = s_temp->s_sub_link;
            }
            return SUCCESS;
        }
        m_temp = m_temp->main_link;
    }
    printf("Word '%s' not found in database.\n", word);
    return DATA_NOT_FOUND;
}