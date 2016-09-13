#include <iostream>
#include "HugeInteger.h"

using namespace std;
int main()
{
   HugeInteger bigNumberX("511", true);
   HugeInteger bigNumberY("510", true);
   // cin >> bigNumberX >> bigNumberY;
   // cout << bigNumberX * bigNumberY;
   // cin >> bigNumberX >> bigNumberY;
   // cout << bigNumberX << endl << bigNumberY << endl;
   // HugeInteger bigNumberZ = bigNumberX + bigNumberY;
   // cout << bigNumberZ;
   bool isBigger = bigNumberX <= bigNumberY;
   cout << isBigger << endl;
   return 0;
}

/*
   Recommended to start with two 'digitsArray' and make a constructor function
   to handle it.

   It may make more intuitive sense to start from the bottom and move to the
   but can work many ways

   We may want to create a third HugeInteger object that is the result of
   other

*/
