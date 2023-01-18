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

bool XO4::shot(char who, int num)
{

    if ((num < 0) || (num > 6)) return false;

    for (int x = 5; x >= 0; x--)
    {
        if (this->map[x][num] == '*')
        {
            this->map[x][num] = who;
            return true;
            break;
        }
    }
    return false;
}

char XO4::testFull()
{
    this->testVertical();
    this->testHorizontal();
    this->testAngleL();
    this->testAngleR();

    return '*';
}

char XO4::testVertical()
{
    for (int y = 0; y < 7; y++)
    {
        if (this->map[5][y] == '*') continue;

        else
        {
            char tempWhu = this->map[5][y];
            int tempInt = 0;
            for (int x = 5; x >= 0; x--)
            {
                if (tempWhu == this->map[x][y])
                {
                    tempInt++;
                    if (tempInt == 4)
                    {
                        std::cout << "Finish "<< tempWhu<<std::endl;
                        return tempWhu;
                    }
                }
                else if ('*' == this->map[x][y]) break;
                else
                {
                    tempInt = 1;
                    tempWhu = this->map[x][y];
                }
            }
        }
    }

    
    return '*';
}

char XO4::testHorizontal()
{
    
    for (int x = 5; x >= 0; x--)
    {
        for (int y = 0; y < 5; y++)
        {

            if (this->map[x][y] == '*') continue;
            else
            {
                char tempWhu = this->map[x][y];
                if ((this->map[x][y] == this->map[x][y + 1]) && (this->map[x][y] == this->map[x][y + 2]) && (this->map[x][y] == this->map[x][y + 3]))
                {
                    std::cout << "Finish " << tempWhu << std::endl;
                    return tempWhu;
                }
            }
        }
    }
    return '*';
}

char XO4::testAngleL()
{
    for (int x = 5; x >= 3; x--)
    {
        for (int y = 6; y >=3; y--)
        {

            if (this->map[x][y] == '*') continue;
            else
            {
                char tempWhu = this->map[x][y];
                if ((this->map[x][y] == this->map[x - 1][y - 1]) && (this->map[x][y] == this->map[x - 2][y - 2]) && (this->map[x][y] == this->map[x - 3][y - 3]))
                {
                    std::cout << "Finish " << tempWhu << std::endl;
                    return tempWhu;
                }
            }
        }
    }
    return '*';
}

char XO4::testAngleR()
{
    for (int x = 5; x >= 3; x--)
    {
        for (int y = 0; y < 5; y++)
        {

            if (this->map[x][y] == '*') continue;
            else
            {
                char tempWhu = this->map[x][y];
                if ((this->map[x][y] == this->map[x - 1][y + 1]) && (this->map[x][y] == this->map[x - 2][y + 2]) && (this->map[x][y] == this->map[x - 3][y + 3]))
                {
                    std::cout << "Finish " << tempWhu << std::endl;
                    return tempWhu;
                }
            }
        }
    }
    return '*';
}
