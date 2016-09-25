/*
Working with class composition because it is composed of other objects
Eventually move to pointers... For everything
*/
#include <iostream>
#include "Equation.h"
#include "HugeInteger.h"
#include "HugeInteger.cpp"

using namespace std;

int main()
{
   bool isValidEquation = true;
   do
   {
      Equation eq;
      cout << "Please enter your Equation: \n";
      cin >> eq;
      isValidEquation = eq.validate();
      if (isValidEquation)
      {
         eq.calculate();
         cout << eq;
      }
   }while(isValidEquation);
   cout << "Thank you for using my application\n";

   return 0;
}
