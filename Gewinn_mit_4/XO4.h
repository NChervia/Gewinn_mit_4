#include <iostream>

class XO4
{
private:

   char map[6][7];

   void initMap();
public:

    XO4();
    ~XO4();
    void out();
    bool shot(char who, int num);
    char testVertical();
    char testHorizontal();
    char testAngleL();
    char testAngleR();
    char testFull();



};
