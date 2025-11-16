#ifndef FOR_SFML_H
#define FOR_SFML_H

#include "A_Main.h"

#define OX_OX 800
#define OY_OY 500

#define JUST_YES 1
#define JUST_NOO 2


enum pose
{
    POSE_yes_OX = 150,
    POSE_yes_minus_OY = 330,

    POSE_noo_OX = 450,
    POSE_noo_minus_OY = 330,

    //координаты левого верхнего угла прямоугольника
    SIZE_but_OX = 200,  
    SIZE_but_OY = 50,
};


int okno_sfml(const char* question);


#endif