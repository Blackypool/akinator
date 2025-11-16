#ifndef MAIN_H_OF_AKINATOR
#define MAIN_H_OF_AKINATOR


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <getopt.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "constr_distr.h"
#include "add_wiki.h"
#include "printing.h"
#include "chitalka.h"
#include "defenition.h"
#include "sf_ml_ka.h"
#include "for_video_frag.h"
#include "sortigent_vid.h"


#define BASA_dannhh "base_of_the_base.txt"
#define HLP tree->fict_helper


struct Main_of_tree
{
    int Kana_;

    size_t size;

    struct leaf* root;

    struct leaf* fict_helper;

    char* basis;

    int _reyka;
};


struct leaf
{
    struct leaf* prev;
    const char* ques_ans;

    struct leaf* yes;
    struct leaf* no;
};


#define ART(paint) \
            window.draw(paint)


#define AsserT(what_need, retern)  \
            if(what_need){  \
                fprintf(stderr, "\nerror in line, %s:%d\n", __FILE__, __LINE__);  \
                return retern;  \
            }


#endif