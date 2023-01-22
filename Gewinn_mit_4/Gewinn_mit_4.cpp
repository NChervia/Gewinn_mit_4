#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Start.h"
int main()
{
     Game game;
     game.run();
    //Start  start;
   // start.run();
    /*XO4 XO;
    int a;
    XO.out();
    char sez = '*';
    while (sez == '*')
    {
        std::cin >> a;
        XO.shot('X', a);
        XO.out();
        sez = XO.testFull();
        std::cin >> a;
        XO.shot('O', a);
        XO.out();
        sez = XO.testFull();
    }*/
   
    return 0;
}

