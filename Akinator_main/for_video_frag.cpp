#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <optional>
#include <iostream>

#include <thread>
#include <chrono>

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
#include "for_video_frag.h"

void video_pusk_opreddelennoe(unsigned int OX, unsigned int OY, const char* music, const char* name_vi, const char* format, size_t num_kadrov)
{
    sf::RenderWindow window(sf::VideoMode({OX, OY}), "Black crypto pool"); //создаем окно размером


    pid_t pid = fork();
    
    if(pid == 0)
    {
        system(music);
        exit(0);
    }

    // sf::Music music_s;
    // (void)music_s.openFromFile(music);
    // music_s.play();
    

    while(window.isOpen()) 
    {
        char str[513] = {};
        for(int i = 1; i < num_kadrov; ++i)
        {     
            snprintf(str, sizeof(str), "/Users/artem888bogdanovmail.ru/Desktop/прога/Akinator/video_siki/%s%05d%s", name_vi, i, format);

            sf::Texture textura_ostrov;
            (void)textura_ostrov.loadFromFile(str);
        
            sf::Sprite ostrov(textura_ostrov);

            while(auto event = window.pollEvent())
                if (event->is<sf::Event::Closed>())
                    window.close();
            
            window.clear();

            ART(ostrov);
            usleep(6500);
            
            window.display();
        }

        break;
    }

    kill(pid, SIGTERM);
}

// int vudeo_pusk()
// {
//     sf::RenderWindow window(sf::VideoMode({750, 300}), "Black crypto pool"); //создаем окно размером


//     pid_t pid = fork();
    
//     if(pid == 0)
//     {
//         system("cd ~/Desktop/прога/Akinator/ostrov_kadrs && afplay Tak_eto_Ostrov.mp3");
//         exit(0);
//     }
    

//     while(window.isOpen()) 
//     {
//         char str[513] = {};
//         for(int i = 1; i < 231; ++i)
//         {     
//             snprintf(str, sizeof(str), "/Users/artem888bogdanovmail.ru/Desktop/прога/Akinator/%s %05d %s", i);

//             sf::Texture textura_ostrov;
//             (void)textura_ostrov.loadFromFile(str);
        
//             sf::Sprite ostrov(textura_ostrov);

//             ostrov.setPosition({-10, -50});
//             // ostrov.setScale({0.7f, 0.7f});

//             while(auto event = window.pollEvent()) //достаем событие
//                 if (event->is<sf::Event::Closed>())
//                     window.close();
            
//             window.clear();

//             ART(ostrov);
//             usleep(9000);
            
//             window.display();
//         }

//         break;
//     }
    
//     return 0;
// }
