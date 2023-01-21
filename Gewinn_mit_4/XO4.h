#include <iostream>

class XO4
{
private:

   char map[6][7];
   char gameSteps[45];

   void initMap();
    char testVertical();
    char testHorizontal();
    char testAngleL();
    char testAngleR();


public:

    XO4();
    ~XO4();
    void out();

    char getMap(int x, int y);

    bool shot(char who, int num);

    char testFull();



};
