#ifndef TYPE_OF_OPERA 
#define TYPE_OF_OPERA

#include "A_Main.h"

struct what_the_video
{
    char answer[52];
    
    char name_vi[512];
    
    char format[28];
    
    char music[512];

    size_t num_kadrov;

    unsigned int O_X;
    unsigned int O_Y;
};

void what_the_operation(struct Main_of_tree* tree, const char* str_str);

#endif
