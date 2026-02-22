#include "insearch.h"

int display_database(c_db *hash_t)
{
    printf("%-10s %-15s %-12s %-15s %-10s\n", "Index", "Word", "File_Count", "File_Name", "Word_Count");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < 28; i++)
    {
        if (hash_t[i].m_link != NULL) {
            m_node *m_curr = hash_t[i].m_link;
            while (m_curr != NULL)
            {
                printf("[%d]    %-15s %-12d", i, m_curr->word, m_curr->file_count);
                
                s_node *s_curr = m_curr->sub_link;
                while (s_curr != NULL) 
                {
                    printf("%-15s %-10d", s_curr->file_name, s_curr->word_count);
                    s_curr = s_curr->s_sub_link;
                    if (s_curr) printf("\n%40s", "");
                }
                
                printf("\n");
                m_curr = m_curr->main_link;
            }
        }
    }
    return SUCCESS;
}