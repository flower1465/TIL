#include <iostream>
#include "practice2.h"

using namespace std;

int main()
{
    CMyDataEX data;
    data.SetData(20, 30);
    cout << data.GetX() << endl;
    cout << data.GetY() << endl;

    return 0;
}