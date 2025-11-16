#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <optional>
#include <iostream>

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
#include <sys/wait.h>
#include <signal.h>

#include "sf_ml_ka.h"

//clang++ -std=c++17 -stdlib=libc++ -o app src/main.cpp -I/opt/homebrew/include -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -rpath /opt/homebrew/lib

//clang++ -std=c++17 -stdlib=libc++ -o app  Alladin_ma.cpp constr_distr.cpp add_wiki.cpp printing.cpp defenition.cpp chitalka.cpp sf_ml_ka.cpp for_video_frag.cpp sortigent_vid.cpp -I/opt/homebrew/include -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -rpath /opt/homebrew/lib


sf::Text text_create(sf::Vector2f pose, const char* yes_noo, sf::Font *font);

sf::RectangleShape create_butt(sf::Color color, sf::Vector2f pose);

int yes_come_back_no(int pose_yes_no_ox, int pose_yes_no_oy, int Yes_or_No, sf::Vector2i *mousePose);

pid_t music_go();


int okno_sfml(const char* question)
{
    // pid_t pid = music_go();

    
    sf::RenderWindow window(sf::VideoMode({OX_OX, OY_OY}), "Black crypto pool"); //создаем окно размером


    auto button_yes = create_butt(sf::Color(7, 67, 245), {POSE_yes_OX, POSE_yes_minus_OY});
    auto button_noo = create_butt(sf::Color(245, 7, 67), {POSE_noo_OX, POSE_noo_minus_OY});     //sf::RectangleShape


    sf::Font font;
    (void)font.openFromFile("/System/Library/Fonts/Helvetica.ttc");

    auto text_yes = text_create({POSE_yes_OX + 77, POSE_yes_minus_OY + 10}, "yes", &font);
    auto text_noo = text_create({POSE_noo_OX + 87, POSE_noo_minus_OY + 10}, "no" , &font);       //sf::Text
    
    //question
    auto text_of_question = text_create({(float)OX_OX / 2 - 45, (float)OY_OY - 60}, question, &font);
    

    sf::Texture texture;
    (void)texture.loadFromFile("/Users/artem888bogdanovmail.ru/Desktop/прога/Akinator/kartinki/Morbius_y_n.jpg");

    sf::Sprite morbius(texture);        // morbius.setTexture(texture);

    morbius.setPosition({-10, -50});    //coordinats
    morbius.setScale({0.7f, 0.7f});


    while(window.isOpen()) 
    {
        while(auto event = window.pollEvent()) //достаем событие
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            auto mousePose = sf::Mouse::getPosition(window);  //Vector2i


            if (auto* click = event->getIf<sf::Event::MouseButtonPressed>())    //достаем из событий нажатие мыши 
                {
                    if (click->button == sf::Mouse::Button::Left)
                    {
                        if((mousePose.x > POSE_noo_OX) && (mousePose.x < POSE_noo_OX + SIZE_but_OX) && \
                            (mousePose.y > POSE_noo_minus_OY) && (mousePose.y < POSE_noo_minus_OY + SIZE_but_OY))
                                return JUST_NOO;
                    }
                }

                
            if (auto* click = event->getIf<sf::Event::MouseButtonPressed>())
                {
                    if (click->button == sf::Mouse::Button::Left)
                    {
                        if((mousePose.x > POSE_yes_OX) && (mousePose.x < POSE_yes_OX + SIZE_but_OX) && \
                            (mousePose.y > POSE_yes_minus_OY) && (mousePose.y < POSE_yes_minus_OY + SIZE_but_OY))
                                return JUST_YES;
                    }
                }


                // int ret_1 = yes_come_back_no(POSE_yes_OX, POSE_yes_minus_OY, JUST_YES, &mousePose);
                // if(ret_1 != -1)
                //     return JUST_YES;

                // int ret_2 = yes_come_back_no(POSE_noo_OX, POSE_noo_minus_OY, JUST_NOO, &mousePose);
                // if(ret_2 != -1)
                //     return JUST_NOO;
        }
            
        window.clear();

        ART(morbius);

        ART(button_yes);
        ART(text_yes);

        ART(button_noo);
        ART(text_noo);

        ART(text_of_question);
        
        window.display();
    }

    // kill(pid, SIGTERM);
    
    return 0;
}


sf::RectangleShape create_butt(sf::Color color, sf::Vector2f pose)
{
    sf::RectangleShape button(sf::Vector2f(SIZE_but_OX, SIZE_but_OY));   //size in float -- Vector2_f/i/ui
    button.setFillColor(color);
    button.setPosition(pose);

    return button;
}


sf::Text text_create(sf::Vector2f pose, const char* yes_noo, sf::Font *font)
{
    sf::Text text(*font, yes_noo, 22);
    text.setFillColor(sf::Color::White);
    text.setPosition(pose);

    return text;
}


pid_t music_go()
{
    pid_t pid = fork();
    
    if(pid == 0)
    {
        system("cd ~/Desktop/прога/Akinator/music && afplay Sherlock.mp3");
        exit(0);
    }

    return pid;
}


int yes_come_back_no(int pose_yes_no_ox, int pose_yes_no_oy, int Yes_or_No, sf::Vector2i *mousePose)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {            
        if((mousePose->x > pose_yes_no_ox) && (mousePose->x < pose_yes_no_ox + SIZE_but_OX) && \
           (mousePose->y > pose_yes_no_oy) && (mousePose->y < pose_yes_no_oy + SIZE_but_OY))
                return Yes_or_No;
    }

    return -1;
}


// int yes_come_back_no(int pose_yes_no_ox, int pose_yes_no_oy, int Yes_or_No, std::optional<sf::Event> *event, sf::Vector2i *mousePose)
// //закидываем событие 
//{                       //проверяем событие =? нажатие лкм
//     if (auto* click = event->value().getIf<sf::Event::MouseButtonPressed>())    //достаем из событий нажатие мыши 
//     {
//         // struct MouseButtonPressed = click
//         // {
//         //     sf::Mouse::Button button;
//         //     int x;
//         //     int y;
//         // };
//         if (click->button == sf::Mouse::Button::Left)
//         {
//             if((mousePose->x > pose_yes_no_ox) && (mousePose->x < pose_yes_no_ox + SIZE_but_OX) && \
//                (mousePose->y > pose_yes_no_oy) && (mousePose->y < pose_yes_no_oy + SIZE_but_OY))
//                         return Yes_or_No;
//         }
//     }
//
//     return -1;
// }

            // if (auto* click = event->value().getIf<sf::Event::MouseButtonPressed>())    //достаем из событий нажатие мыши 
            // {
            //     if (click->button == sf::Mouse::Button::Left)
            //     {
            //         if((mousePose.x > POSE_noo_OX) && (mousePose.x < POSE_noo_OX + SIZE_but_OX) && \
            //             (mousePose.y > POSE_noo_minus_OY) && (mousePose.y < POSE_noo_minus_OY + SIZE_but_OY))
            //                 return JUST_NOO;
            //     }
            // }

            
            // if (auto* click = event->getIf<sf::Event::MouseButtonPressed>())    //достаем из событий нажатие мыши 
            // {
            //     if (click->button == sf::Mouse::Button::Left)
            //     {
            //         if((mousePose.x > POSE_yes_OX) && (mousePose.x < POSE_yes_OX + SIZE_but_OX) && \
            //             (mousePose.y > POSE_yes_minus_OY) && (mousePose.y < POSE_yes_minus_OY + SIZE_but_OY))
            //                 return JUST_YES;
            //     }
            // }
