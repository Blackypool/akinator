#include "chitalka.h"


struct leaf* create_base(char** curent_in_txt_ptr)
{
    char* curent_in_txt = *curent_in_txt_ptr;
    
    if(*curent_in_txt == '(')
    {
        curent_in_txt++;

        struct leaf* new_node = read_words(&curent_in_txt);

        new_node->yes = create_base(&curent_in_txt);
        if(new_node->yes != NULL)
            new_node->yes->prev = new_node;


        new_node->no  = create_base(&curent_in_txt);
        if(new_node->no != NULL)
            new_node->no->prev = new_node;



        while((*curent_in_txt == ' ' || *curent_in_txt == '\t' || *curent_in_txt == '\n'))
            curent_in_txt++;

        if(*curent_in_txt == ')')
            curent_in_txt++;

        *curent_in_txt_ptr = curent_in_txt;

        return new_node;
    }

    if(strncmp("nil", curent_in_txt, 3) == 0)    //nil_li_you(&curent_in_txt)
    {
        while(*curent_in_txt == ' ') curent_in_txt++;

        curent_in_txt = curent_in_txt + strlen("nil");

        while(*curent_in_txt == ' ') curent_in_txt++;


        *curent_in_txt_ptr = curent_in_txt;


        return NULL;
    }

    

    return NULL;
}


struct leaf* read_words(char** curent_in_txt_ptr)
{
    char* curent_in_txt = *curent_in_txt_ptr;

    curent_in_txt++;

    while((*curent_in_txt == ' ' || *curent_in_txt == '\t' || *curent_in_txt == '\n') && *curent_in_txt != '"')
            curent_in_txt++;

    curent_in_txt++;


    struct leaf* new_node = (struct leaf*)calloc(1, sizeof(struct leaf));
    AsserT(new_node == NULL, NULL);
        

    char* start = curent_in_txt;

    while(*curent_in_txt != '"')
        curent_in_txt++;


    size_t len_len = (size_t)(curent_in_txt - start);

    char* ans_que = (char*)calloc(len_len + 1, sizeof(char));
    AsserT(ans_que == NULL, NULL);

    strncpy(ans_que, start, len_len);

    new_node->ques_ans = ans_que;

    // printf("%s\n", new_node->ques_ans);

    while((*curent_in_txt == ' ' || *curent_in_txt == '"' || *curent_in_txt == '\t' || *curent_in_txt == '\n') && *curent_in_txt != '(')
        curent_in_txt++;


    *curent_in_txt_ptr = curent_in_txt;

    return new_node;
}


int nil_li_you(char** curent_in_txt_ptr)
{
    char* curent_in_txt = *curent_in_txt_ptr;

    char* start = curent_in_txt;

    while(*curent_in_txt != ' ' && *curent_in_txt != ')')
        curent_in_txt++;

    size_t len_len = (size_t)(curent_in_txt - start);

    char* ans_que = (char*)calloc(len_len + 1, sizeof(char));
    AsserT(ans_que == NULL, NULL);

    strncpy(ans_que, start, len_len);

    *curent_in_txt_ptr = curent_in_txt;

    return strcmp("nil", ans_que);
}


size_t number_of_file()
{
    struct stat file_info = {};

    if (stat(BASA_dannhh, &file_info) != 0)
    {
        perror("stat error");
        return 1;
    }

    return (size_t)file_info.st_size;
}


char* file_pointer_read()
{
    size_t number_char = number_of_file();

    FILE *fp = fopen(BASA_dannhh, "rb");
    AsserT(fp == NULL, NULL);

    char *ptr = (char*) calloc((size_t)(number_char + 2), sizeof(char));
    AsserT(ptr == NULL, NULL);

    size_t count = fread(ptr, sizeof(char), number_char, fp);
    AsserT(count == 0, NULL);

    fclose (fp);

    return ptr;
}
