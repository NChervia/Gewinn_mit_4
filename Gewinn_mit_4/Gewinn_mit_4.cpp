#define WIN32_LEAN_AND_MEAN

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
//#include "Game.h"   //Playing field class
//#include "Start.h"  //Start menu class
//#include "Option.h" //Option menu class
#include "gameUp.h"


int main()
{
  
    gameUp gameUp;
    gameUp.run(0, 0);
    /*

    Start start;     //Class initialization
    Game game;       //Class initialization
    Option option;   //Class initialization
    int NextStep = 0;// Next step : 1 - single player, 2 - options, 3 - server player, 0 - exit.
    int ChipsTextyreNum = 0; //Player skin type
    while (true)     //Main cycle
    {
        NextStep = start.run();  //Menu launch
        
        if (NextStep == 1) game.run(NextStep, ChipsTextyreNum); //Game launch
        else if (NextStep == 3) game.run(NextStep, ChipsTextyreNum); //Game with server launch
        else if (NextStep == 2) ChipsTextyreNum = option.run(); //Launching the options menu
        else if (NextStep == 0) break; //Exit
        else break; //Exit
    }
*/
    return 0;
}

