#define WIN32_LEAN_AND_MEAN

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
  
#include "Start.h"  //Start menu class
#include "Option.h" //Option menu class
#include "gameUp.h"//Playing field class


int main()
{

    gameUp gameUp;
    Start start;     //Class initialization
    Option option;   //Class initialization
    int NextStep = 0;// Next step : 1 - single player, 2 - options, 3 - server player, 4 - client player, 0 - exit.
    int ChipsTextyreNum = 0; //Player skin type
    while (true)     //Main cycle
    {
        NextStep = start.run();  //Menu launch

        if (NextStep == 1) gameUp.run(NextStep, ChipsTextyreNum); //Game launch
        else if (NextStep == 3) gameUp.run(NextStep, ChipsTextyreNum); //Game with server launch
        else if (NextStep == 4) gameUp.run(NextStep, ChipsTextyreNum); //Game with Client launch
        else if (NextStep == 2) ChipsTextyreNum = option.run(); //Launching the options menu
        else if (NextStep == 0) break; //Exit
        else break; //Exit
    }

    return 0;
}

