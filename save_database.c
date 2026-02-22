#include "insearch.h"

int save_database(c_db *hash_t)
{
    char filename[30];
    printf("Enter the filename to save: ");
    scanf("%s", filename);

    FILE *fptr = fopen(filename, "w");
    if (!fptr) return FAILURE;

    for (int i = 0; i < 28; i++) 
    {
        if (hash_t[i].m_link != NULL) 
        {
            m_node *m_temp = hash_t[i].m_link;
            while (m_temp) 
            {
                fprintf(fptr, "#%d;%s;%d;", i, m_temp->word, m_temp->file_count);
                s_node *s_temp = m_temp->sub_link;
                while (s_temp) 
                {
                    fprintf(fptr, "%s;%d;", s_temp->file_name, s_temp->word_count);
                    s_temp = s_temp->s_sub_link;
                }
                fprintf(fptr, "#\n");
                m_temp = m_temp->main_link;
            }
        }
    }
    fclose(fptr);
    return SUCCESS;
}