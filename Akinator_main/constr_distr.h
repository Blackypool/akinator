#ifndef CONSTR_DISTR_H
#define CONSTR_DISTR_H

#include "A_Main.h"


int constructor(struct Main_of_tree *tree);

int base_data(struct Main_of_tree *tree);

void allocation(struct leaf** what);

void fell_a_tree(struct Main_of_tree *tree);

void cleaner(struct leaf **left_right);

void kanareyka_checker(struct Main_of_tree *tree, const char *file_n, int line_n);


#endif