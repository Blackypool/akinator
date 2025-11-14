#ifndef CHTEC_H
#define CHTEC_H

#include "A_Main.h"

struct leaf* create_base(char** curent_in_txt_ptr);

struct leaf* read_words(char** curent_in_txt_ptr);

int nil_li_you(char** curent_in_txt_ptr);

size_t number_of_file();

char* file_pointer_read();

#endif