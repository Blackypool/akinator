#ifndef PRINT_FFF
#define PRINT_FFF

#include "A_Main.h"

void call_terminal(int number_of_zapusk);

void draw_leaf(FILE *fp_out, struct leaf *leaf);

void draw_stick(FILE *fp_out, struct leaf *leaf);

void true_picture(struct Main_of_tree *tree, struct leaf *leaf, int *number_of_zapusk, const char* text);

void pre_order_printf(FILE *fp_out, struct leaf *leaf);


#endif