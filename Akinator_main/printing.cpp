#include "printing.h"


void true_picture(struct Main_of_tree *tree, struct leaf *leaf, int *number_of_zapusk, const char* text)
{
    AsserT(leaf == NULL, );

    char str[26] = {};
    snprintf(str, sizeof str, "akin_dump_%d.dot", *number_of_zapusk);

    FILE *fp_out = fopen(str, "w");
    AsserT(fp_out == NULL, );

    fprintf(fp_out, "digraph\n{\nrankdir=TB;\nnodesep=0.4;\nranksep=1.0;\n");

    fprintf(fp_out, "  labelloc=\"t\";\n");
    fprintf(fp_out, "  label=\"ROOT: %p\nNUM_ZAP: %d\n%s\";\n", tree->root, *number_of_zapusk, text);



    draw_leaf(fp_out, leaf);

    draw_stick(fp_out, leaf);


    fprintf(fp_out, "\n}");

    fclose(fp_out);

    call_terminal(*number_of_zapusk);

    (*number_of_zapusk)++;
}


void draw_leaf(FILE *fp_out, struct leaf *leaf)
{
    if(leaf == NULL)
    {
        return ;
    }
    

    fprintf(fp_out, "leaf_%p [label = \"{index = %p | val = %s | {yes = %p | no = %p | prev = %p}}\", \
                 style = \"rounded, filled\", \
                    fillcolor = \"#a2a6f1ff\", fontcolor = \"#000000\", shape = Mrecord];\n", leaf, leaf, leaf->ques_ans, leaf->yes, leaf->no, leaf->prev);


    if(leaf->yes != NULL)
        draw_leaf(fp_out, leaf->yes);


    if(leaf->no != NULL)
        draw_leaf(fp_out, leaf->no);
}


void draw_stick(FILE *fp_out, struct leaf *leaf)
{
    if(leaf != NULL)
    {
            if(leaf->no != NULL)
            {
                fprintf(fp_out, "leaf_%p -> leaf_%p;\n", leaf, leaf->no);
                draw_stick(fp_out, leaf->no);
            }

            if(leaf->yes != NULL)
            {
                fprintf(fp_out, "leaf_%p -> leaf_%p;\n", leaf, leaf->yes);
                draw_stick(fp_out, leaf->yes);
            }
    }
}


void call_terminal(int number_of_zapusk) 
{
    char apple_script[512] = {};

    snprintf(apple_script, sizeof(apple_script), "cd ~/Desktop/прога/Akinator/Akinator_main && dot -Tpng akin_dump_%d.dot -o try_try_%d.png && \
        open try_try_%d.png", number_of_zapusk, number_of_zapusk, number_of_zapusk);
    
    system(apple_script);
}


void pre_order_printf(FILE *fp_out, struct leaf *leaf)
{
    if(leaf != NULL)
    {
        fprintf(fp_out, "(");

        fprintf(fp_out, " \"%s\" ", leaf->ques_ans);


        if(leaf->yes != NULL)
            pre_order_printf(fp_out, leaf->yes);

        if(leaf->no != NULL)
            pre_order_printf(fp_out, leaf->no);

        if((leaf->yes == NULL) && (leaf->no == NULL))
            fprintf(fp_out, " nil nil ");

        fprintf(fp_out, ")");
    }
}
