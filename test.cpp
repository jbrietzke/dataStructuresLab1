#include <iostream>
#include "HugeInteger.h"

using namespace std;

int main()
{
   HugeInteger num1, num2;
   cin >> num1 >> num2;
   HugeInteger result = num1 / num2;
   cout << result;
   return 0;
}