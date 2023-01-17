#include <iostream>

class XO4
{
private:

   char map[7][6];

   void initMap();
public:

    XO4();
    ~XO4();
    void out();
    void shot(char who, int num);


};
