#include <iostream>

class XO4
{
private:

    char map[6][7];
    char gameSteps[45];
    int GameWon[4][2];

    void initMap();
    bool testVertical();
    bool testHorizontal();
    bool testAngleL();
    bool testAngleR();
    void wonChange();


public:

    XO4();
    ~XO4();
    void out();
    void newmap();
    char getMap(int x, int y);
    bool shot(char who, int num);

    bool testFull();



};
