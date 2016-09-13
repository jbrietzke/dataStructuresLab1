#include <iostream>
#include "HugeInteger.h"

using namespace std;
int main()
{
   string blah1, blah2, op;
   cin >> blah1 >> op >> blah2;
   HugeInteger num1(blah1, true);
   HugeInteger num2(blah2, true);
   HugeInteger result;
   if (op == "+")
   {
      cout << "Plus\n";
   }else if (op == "*")
   {
      cout << "Times\n";
   }else if (op == ">=")
   {
      cout << "Greater\n";
   }else if (op == "<=")
   {
      cout << "Lesser\n";
   }else if (op == "!=")
   {
      cout << "notEqual\n";
   }else if (op == "==")
   {
      cout << "equal\n";
   }else
   {
      cout << "In later additions of the lab this will be available\n";
   }
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
