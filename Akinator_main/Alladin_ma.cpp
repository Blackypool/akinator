#include "A_Main.h"


void quizer(struct Main_of_tree *tree, struct leaf *leaf);

void zapusk(struct Main_of_tree *tree);


int main()
{
    struct Main_of_tree tree = {};

    constructor(&tree);

    zapusk(&tree);


    //////////////
    FILE *fp_out = fopen(BASA_dannhh, "w");
    AsserT(fp_out == NULL, 1);

    pre_order_printf(fp_out, tree.root);

    fclose(fp_out);
    ///////////////


    fell_a_tree(&tree);

    return 0;

    // struct Main_of_tree tree = {};
    // constructor(&tree);
    // zapusk(&tree);
    // pre_order_printf(fp_out, tree.root);
    // fell_a_tree(&tree);
}


void quizer(struct Main_of_tree *tree, struct leaf *leaf)
{
    if(leaf != NULL)
    {
        int erro = 0;
        char ans_std[6] = {};

        if(leaf->yes != NULL && leaf->no != NULL)   //this is question
        {
            printf("%s\n", leaf->ques_ans);

            scanf("%s", ans_std);

            if(strcmp("yes", ans_std) == 0)
                quizer(tree, leaf->yes);

            if(strcmp("no", ans_std) == 0)
                quizer(tree, leaf->no);
        }

        else
        {
            printf("Это %s?\n", leaf->ques_ans);
            scanf("%s", ans_std);


            if(strcmp("yes", ans_std) == 0)
            {
                printf("\nУгадал)\n");
            }
                

            if(strcmp("no", ans_std) == 0)
            {
                if(leaf->prev->no == leaf)
                {
                    erro = extension_wiki(tree, &leaf, 2); // 2 - предыдущий нет
                    AsserT(erro != 0, );
                }

                if(leaf->prev->yes == leaf)
                {
                    erro = extension_wiki(tree, &leaf, 1);
                    AsserT(erro != 0, );
                }

                quizer(tree, tree->root);
            }
        }
    }
}


void zapusk(struct Main_of_tree *tree)
{
    int number_of_zapusk = 0;
    while(1)
    {
        printf("_________________________________________________________");
        printf("\nchoose zapusk:   'akinator'   'opredelenie'    'stop'\n");


        char operatia[512] = {};
        scanf("%s", operatia);

        if(strcmp(operatia, "akinator") == 0)
            quizer(tree, tree->root);


        if(strcmp(operatia, "opredelenie") == 0)
        {
            printf("кого найти?\n");

            char str[70] = {};
            scanf("%s", str);

            find_func(tree->root, str);
        }

        
        if(strcmp(operatia, "stop") == 0)
            break;

        true_picture(tree, tree->root, &number_of_zapusk, "just dumpi");
    }
}
