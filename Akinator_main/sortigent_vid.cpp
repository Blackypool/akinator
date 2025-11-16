#include "sortigent_vid.h"

    //ffmpeg -i sell_ruchku.mp4 -vf fps=60 sell_ruchku%05d.png
    //ffmpeg -i sell_ruchku.mp4 sell_ruchku.mp3

    //clang++ -std=c++17 -stdlib=libc++ -o app  Alladin_ma.cpp constr_distr.cpp add_wiki.cpp printing.cpp defenition.cpp chitalka.cpp sf_ml_ka.cpp for_video_frag.cpp sortigent_vid.cpp -I/opt/homebrew/include -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -rpath /opt/homebrew/lib

static struct what_the_video vid[] = {

    /////
    {"I$ your morning going like this?", "ostrov_kadrs/ostrov_", ".png", "cd ~/Desktop/прога/Akinator/video_siki/ostrov_kadrs && afplay Tak_eto_Ostrov.mp3", 231, 848, 352},
    /////
    {"Intraday?", "22_milliona/ostrov_", ".png", "cd ~/Desktop/прога/Akinator/video_siki/22_milliona && afplay 22_milliona.mp3", 301, 1280, 592},
    /////
    {"any exchange?", "egednevno_ya/egednevno_ya", ".png", "cd ~/Desktop/прога/Akinator/video_siki/egednevno_ya && afplay egednevno_ya.mp3", 519, 1280, 592},
    /////
    {"ugadal", "gensti_bokal/gensti_bokal", ".png", "cd ~/Desktop/прога/Akinator/video_siki/gensti_bokal && afplay gensti_bokal.mp3", 133, 848, 384},
    /////
    {"Do you want risk?", "mne_need_garan/mne_need_garan", ".png", "cd ~/Desktop/прога/Akinator/video_siki/mne_need_garan && afplay mne_need_garan.mp3", 329, 1280, 592},
    /////
    {"Idea i$ legal?", "ne_zakonno/ne_zakonno", ".png", "cd ~/Desktop/прога/Akinator/video_siki/ne_zakonno && afplay ne_zakonno.mp3", 155, 1280, 592},
    /////
    {"koreliruet with BTC?", "umeret_chelo/umeret_chelo", ".png", "cd ~/Desktop/прога/Akinator/video_siki/umeret_chelo && afplay umeret_chelo.mp3", 583, 848, 384},
    /////
    {"it is very bad... u want return?", "vernut_proshloe/vernut_proshloe", ".png", "cd ~/Desktop/прога/Akinator/video_siki/vernut_proshloe && afplay vernut_proshloe.mp3", 739, 1280, 592},
    /////
    {"no", "ya_evo_neznau/ya_evo_neznau", ".png", "cd ~/Desktop/прога/Akinator/video_siki/ya_evo_neznau && afplay ya_evo_neznau.mp3", 475, 848, 384},
    /////
    {"do you trust goovernment?", "patriot_sl/patriot_sl", ".png", "cd ~/Desktop/прога/Akinator/video_siki/patriot_sl && afplay patriot_sl.mp3", 239, 848, 384},
    /////
    {"do you have a plan?", "plan_monako/plan_monako", ".png", "cd ~/Desktop/прога/Akinator/video_siki/plan_monako && afplay plan_monako.mp3", 597, 1280, 592},
    /////
    {"ability to sell?", "sell_ruchku/sell_ruchku", ".png", "cd ~/Desktop/прога/Akinator/video_siki/sell_ruchku && afplay sell_ruchku.mp3", 835, 1280, 592},
    /////
    };


void what_the_operation(struct Main_of_tree* tree, const char* str_str)
{
    int number_of_operation = sizeof(vid) / sizeof(vid[0]);

    int i = 0;

    for(size_t kakoe_v = 0; kakoe_v < number_of_operation; ++kakoe_v) //tree->size
    {
            if (strcmp(str_str, vid[kakoe_v].answer) == 0)
            {
                i = kakoe_v;
                video_pusk_opreddelennoe(vid[i].O_X, vid[i].O_Y, vid[i].music, vid[i].name_vi, vid[i].format, vid[i].num_kadrov);
                break;
            }
    }
}

