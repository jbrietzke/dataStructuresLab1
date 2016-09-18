/*
This file is a driver program to specifically test parts of my application
I want to test.
*/
#include <iostream>
#include "HugeInteger.h"

using namespace std;

int main()
{
   HugeInteger num1, num2;
   char op;
   cin >> num1 >> op >> num2;
   HugeInteger result = num1 + num2;
   cout << result;
   return 0;
}
