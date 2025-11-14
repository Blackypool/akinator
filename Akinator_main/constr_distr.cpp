#include "constr_distr.h"


int constructor(struct Main_of_tree *tree)
{
    AsserT(tree == NULL, 1);

    tree->Kana_  = 914;
    tree->_reyka = 419;

    tree->size = 0;

    tree->root = NULL;
    HLP = NULL;

    tree->basis = file_pointer_read();

    tree->root = create_base(&(tree->basis));

    kanareyka_checker(tree, __FILE__, __LINE__);

    return 0;
}


int base_data(struct Main_of_tree *tree)
{
    AsserT(tree == NULL, 1);
    kanareyka_checker(tree, __FILE__, __LINE__);


    allocation(&(HLP));
    HLP->ques_ans = "HELPER";

    allocation(&(tree->root));
    tree->root->ques_ans = "Животное?";
    tree->root->prev = NULL;


    allocation(&(tree->root->yes));
    HLP->yes = tree->root->yes;
    HLP->yes->ques_ans = "кот";
    HLP->yes->prev = tree->root;


    allocation(&(tree->root->no));
    HLP->no = tree->root->no;
    HLP->no->ques_ans = "персонаж";
    HLP->no->prev = tree->root;


    kanareyka_checker(tree, __FILE__, __LINE__);

    return 0;
}


void allocation(struct leaf** what)
{
    *what = (struct leaf*)calloc(1, sizeof(struct leaf));
    AsserT(*what == NULL, );
}


void fell_a_tree(struct Main_of_tree *tree)
{
    AsserT(tree == NULL, );
    kanareyka_checker(tree, __FILE__, __LINE__);

    tree->Kana_ = 0;
    tree->_reyka = 0;

    tree->size = 0;

    if(tree->root != NULL)
    {
        if(tree->root->yes != NULL)
            cleaner(&(tree->root->yes));
        
        if(tree->root->no != NULL)
            cleaner(&(tree->root->no));
        
        free(tree->root);
        tree->root = NULL;
    }
}


void cleaner(struct leaf **left_right)
{
    if((*left_right)->yes == NULL && (*left_right)->no == NULL)
    {
        free(*left_right);
        *left_right = NULL;
        return ;
    }

    if((*left_right)->yes != NULL)
        cleaner(&((*left_right))->yes);

    if((*left_right)->no != NULL)
        cleaner(&((*left_right))->no);
}


void kanareyka_checker(struct Main_of_tree *tree, const char *file_n, int line_n)
{
    AsserT(tree == NULL, );

    if((tree->Kana_ != 914) || (tree->_reyka != 419))
        fprintf(stderr, "\nkanareyka in line, %s:%d\n", file_n, line_n);
}
