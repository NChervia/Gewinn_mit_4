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

     
     this->GameWon[0][0] = 8; this->GameWon[0][1] = 8;
     this->GameWon[1][0] = 8; this->GameWon[1][1] = 8;
     this->GameWon[2][0] = 8; this->GameWon[2][1] = 8;
     this->GameWon[3][0] = 8; this->GameWon[3][1] = 8;
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

char XO4::getMap(int x, int y)
{
    if ((x < 0) && (x > 6))return 0;
    if ((y < 0) && (y > 7))return 0;
    return this->map[x][y];
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

bool XO4::testFull()
{
    bool ret = false;
    if (this->testVertical())ret = true;
    if (this->testHorizontal())ret = true;
    if (this->testAngleL())ret = true;
    if (this->testAngleR())ret = true;
    this->wonChange();

    return ret;
}

bool XO4::testVertical()
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
                        this->GameWon[0][0] = x; this->GameWon[0][1] = y;
                        this->GameWon[1][0] = x+1; this->GameWon[1][1] = y;
                        this->GameWon[2][0] = x+2; this->GameWon[2][1] = y;
                        this->GameWon[3][0] = x+3; this->GameWon[3][1] = y;
                        return true;
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

    
    return false;
}

bool XO4::testHorizontal()
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
                    this->GameWon[0][0] = x; this->GameWon[0][1] = y;
                    this->GameWon[1][0] = x; this->GameWon[1][1] = y + 1;
                    this->GameWon[2][0] = x; this->GameWon[2][1] = y + 2;
                    this->GameWon[3][0] = x; this->GameWon[3][1] = y + 3;
                    return true;
                }
            }
        }
    }
    return false;
}

bool XO4::testAngleL()
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
                    this->GameWon[0][0] = x; this->GameWon[0][1] = y;
                    this->GameWon[1][0] = x - 1; this->GameWon[1][1] = y - 1;
                    this->GameWon[2][0] = x - 2; this->GameWon[2][1] = y - 2;
                    this->GameWon[3][0] = x - 3; this->GameWon[3][1] = y - 3;
                    return true;
                }
            }
        }
    }
    return false;
}

bool XO4::testAngleR()
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
                    this->GameWon[0][0] = x; this->GameWon[0][1] = y;
                    this->GameWon[1][0] = x - 1; this->GameWon[1][1] = y + 1;
                    this->GameWon[2][0] = x - 2; this->GameWon[2][1] = y + 2;
                    this->GameWon[3][0] = x - 3; this->GameWon[3][1] = y + 3;
                    return true;
                }
            }
        }
    }
    return false;
}

void XO4::wonChange()
{
    if (map[this->GameWon[0][0]][this->GameWon[0][1]] == 'X')
    {
        map[this->GameWon[0][0]][this->GameWon[0][1]] = 'x';
        map[this->GameWon[1][0]][this->GameWon[1][1]] = 'x';
        map[this->GameWon[2][0]][this->GameWon[2][1]] = 'x';
        map[this->GameWon[3][0]][this->GameWon[3][1]] = 'x';
    }
    else
    {
        map[this->GameWon[0][0]][this->GameWon[0][1]] = 'y';
        map[this->GameWon[1][0]][this->GameWon[1][1]] = 'y';
        map[this->GameWon[2][0]][this->GameWon[2][1]] = 'y';
        map[this->GameWon[3][0]][this->GameWon[3][1]] = 'y';
    }
}
