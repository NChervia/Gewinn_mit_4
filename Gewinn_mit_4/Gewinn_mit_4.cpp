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
    while (a != 13)
    {
        std::cin >> a;
        if (!XO.shot('O', a)) std::cout << "false";
        XO.out();

        XO.testFull();
        std::cin >> a;
        if (!XO.shot('X', a)) std::cout << "false";
        XO.out();

        XO.testFull();
    }
    std::cin >> a;
   
    return 0;
}

