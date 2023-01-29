#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Start.h"
#include "Option.h"
#include <Windows.h>
int main()
{

    Start start;
    Game game;
    Option option;
    int TypeGame = 0;
    int ChipsTextyreNum=0;
    while (true)
    {
        TypeGame = start.run();
        //TypeGame = start.run();
        if (TypeGame == 1)
        {
            game.run(TypeGame, ChipsTextyreNum);
        }
        else if (TypeGame == 2)
        {
            ChipsTextyreNum = option.run();
        }
        else if (TypeGame == 0)
        {
            break;
        }
    }

    return 0;
}

