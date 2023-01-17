#include "XO4.h"

void XO4::initMap()
{
    for (int x = 0; x < 6; x++)
    {
        for (int y = 0; y < 7; y++)
        {
             this->map[x][y]='*';
        }
    }
}

XO4::XO4()
{
    this->initMap();
}

XO4::~XO4()
{
}

void XO4::out()
{
    for (int x = 0; x < 6; x++)
    {
        for (int y = 0; y < 7; y++)
        {
            std::cout << this->map[x][y] << " ";
        }
        std::cout << std::endl;
    }
}

void XO4::shot(char who, int num)
{

    num = num % 7;

    for (int x = 5; x > 0; x--)
    {
        if (this->map[x][num] == '*')
        {
            this->map[x][num] = who;
            break;
        }
    }
}
