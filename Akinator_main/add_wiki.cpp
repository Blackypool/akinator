#include "add_wiki.h"


int extension_wiki(struct Main_of_tree *tree, struct leaf** what, int yes_no)
{
    HLP = (*what);//кот         //фиктивный элемент имеет указатель на тот который не подошел под итоговый ответ 

    AsserT(tree == NULL, 1);

    AsserT(*what == NULL, 1);


    printf("И кто это был?\n");
    getchar();

    char *answ = (char*)calloc(70, sizeof(char));
    AsserT(answ == NULL, 1);
    fgets(answ, 69, stdin);
    answ[strlen(answ) - 1] = '\0';

    printf("И чем %s отличается от %s? Это существо...\n", answ, HLP->ques_ans);      //проверка на частицу ненененеенннене

    char *quest = (char*)calloc(513, sizeof(char));
    AsserT(quest == NULL, 1);
    fgets(quest, 512, stdin);
    quest[strlen(quest) - 1] = '\0';

    snprintf(quest, 512, "%s?", quest);


    struct leaf* new_question = (struct leaf*)calloc(1, sizeof(struct leaf)); //создаем новую структуру для нового вопроса
    AsserT(new_question == NULL, 1);
    
    struct leaf* new_answer = (struct leaf*)calloc(1, sizeof(struct leaf));   //новая структура для нового существа
    AsserT(new_answer == NULL, 1);


    new_question->ques_ans = (const char*)quest;  //сам вопрос

    new_question->no = HLP;          //нет <=> тот который не подошел изначально = кот 
    new_question->yes = new_answer;
    new_question->prev = HLP->prev;  //у нового вопроса - предыдущий у кота

    
    if(yes_no == 1) //yes то есть ответ на предыдущий вопрос был да
        HLP->prev->yes = new_question;   //да у старого вопроса - новый вопрос

    if(yes_no == 2) //no у предыдущего вопроса
        HLP->prev->no = new_question;


    HLP->prev = new_question; //предыдущий у кота теперь новый вопрос


    new_answer->prev = new_question;    //у нового существа предыдущий - новый вопрос
    new_answer->ques_ans = (const char*)answ;

           
    return 0;
}
