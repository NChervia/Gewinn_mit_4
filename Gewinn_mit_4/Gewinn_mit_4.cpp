#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Start.h"
#include "XO4.h"
int main()
{
    // Game game;
    //Start  start;
   // start.run();
    XO4 XO;
    int a;
    XO.out();
    std::cin >> a;
    XO.shot('X', 2);
    XO.out();
    std::cin >> a;
    XO.shot('O', 4);
    XO.out();
    std::cin >> a;
   
    return 0;
}

