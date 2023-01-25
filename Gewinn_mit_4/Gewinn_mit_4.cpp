#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Start.h"
#include <Windows.h>
int main()
{
      
    Start start; 
    Game game;
    int TypeGame=0;
    while (true)
    {
       
        TypeGame = start.run();
        //TypeGame = start.run();
        if (TypeGame == 1)
        {
           
            game.run(TypeGame);
           
        }
        else if (TypeGame == 0)
        {
            break;
        }
    }

    return 0;
}

