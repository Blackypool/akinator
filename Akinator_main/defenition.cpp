#include "defenition.h"


void find_func(struct leaf *leaf, char* str)
{
    if(leaf != NULL)
    {
        if(strcmp(leaf->ques_ans, str) == 0)
        {
            printf("\nНашел твое слово %s\nВот его точное определение:\n\n ", leaf->ques_ans);
            come_back(leaf);
            return ;
        }

        if(leaf->yes != NULL)
            find_func(leaf->yes, str);

        if(leaf->no != NULL)
            find_func(leaf->no, str);
    }
}


void come_back(struct leaf *leaf)
{
    if(leaf == NULL)
        return ;

    char definition[1307] = "";

    struct leaf* fict = leaf->prev;
     struct leaf* curr = leaf;

    printf("\nНашел твое слово %s\nВот его точное определение: ", leaf->ques_ans);

    while(fict != NULL) //определение в нормальном порядке // стек  //say
    {
        strcpy(definition, fict->ques_ans);

        definition[strlen(definition) - 1] = ' ';

        if(fict->yes == curr)
            printf("-->%s",definition);
        
        else printf("-->не %s",definition);

        curr = fict;

        fict = fict->prev;
    }

    printf("\n");
}
