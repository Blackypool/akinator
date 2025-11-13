#include "chitalka.h"


char* create_base(char* curent_in_txt)
{
    if(*curent_in_txt == '(')
    {
        *curent_in_txt = *curent_in_txt + 3;    // ( + spase + "

        while(*curent_in_txt != '"')
        {
            *curent_in_txt++;
        }


    }


    return curent_in_txt;
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
