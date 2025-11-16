#include "A_Main.h"


void quizer(struct Main_of_tree *tree, struct leaf *leaf);

void zapusk(struct Main_of_tree *tree);


int main()
{
    struct Main_of_tree tree = {};

    int num = 90;

    constructor(&tree);
    true_picture(&tree, tree.root, &num, "constructor");

    zapusk(&tree);


    //////////////
    FILE *fp_out = fopen(BASA_dannhh, "w");
    AsserT(fp_out == NULL, 1);

    pre_order_printf(fp_out, tree.root);

    fclose(fp_out);
    ///////////////


    fell_a_tree(&tree);

    return 0;
}


void quizer(struct Main_of_tree *tree, struct leaf *leaf)
{
    if(leaf != NULL)
    {
        int erro = 0;
        char ans_std[6] = {};

        if(leaf->yes != NULL && leaf->no != NULL)   //this is question
        {
            int ans = okno_sfml(leaf->ques_ans);

            if(ans == JUST_YES)    //yes
            {
                what_the_operation(tree, leaf->ques_ans);
                quizer(tree, leaf->yes);
            }

            if(ans == JUST_NOO)    //no
            {
                quizer(tree, leaf->no);
            }
            // printf("%s\n", leaf->ques_ans);

            // scanf("%s", ans_std);

            // if(strcmp("yes", ans_std) == 0)
            //     quizer(tree, leaf->yes);

            // if(strcmp("no", ans_std) == 0)
            //     quizer(tree, leaf->no);
        }

        else
        {
            int ans = okno_sfml(leaf->ques_ans);

            if(ans == JUST_YES)
                what_the_operation(tree, "ugadal");
                // system("cd ~/Desktop/прога/Akinator/video_siki && open Getsbi_bokal.mp4");

            if(ans == JUST_NOO)
            {
                what_the_operation(tree, "no");
                // system("cd ~/Desktop/прога/Akinator && open Tak_eto_Ostrov.mp4");
                // int err = vudeo_pusk();  
                // AsserT(err != 0, )       
                
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

            // printf("Это %s?\n", leaf->ques_ans);
            // scanf("%s", ans_std);


            // if(strcmp("yes", ans_std) == 0)
            // {
            //     printf("\nУгадал)\n");
            // }
                

            // if(strcmp("no", ans_std) == 0)
            // {
            //     if(leaf->prev->no == leaf)
            //     {
            //         erro = extension_wiki(tree, &leaf, 2); // 2 - предыдущий нет
            //         AsserT(erro != 0, );
            //     }

            //     if(leaf->prev->yes == leaf)
            //     {
            //         erro = extension_wiki(tree, &leaf, 1);
            //         AsserT(erro != 0, );
            //     }

            //     quizer(tree, tree->root);
            // }
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
        {
            quizer(tree, tree->root);
        }
            


        if(strcmp(operatia, "opredelenie") == 0)
        {
            printf("кого найти?\n");

            char str[70] = {};
            scanf("%s", str);

            find_func(tree->root, str);
        }  

        if(strcmp(operatia, "stop") == 0)
            break;
        
    }
}
