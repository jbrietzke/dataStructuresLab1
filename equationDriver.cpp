/*
Working with class composition because it is composed of other objects
Eventually move to pointers... For everything
This is a driver program to test out the Equation class
Users input their equation and get the result
It ends when users plug in the equation inputs of '0'
*/
#include <iostream>
#include "Equation.h"
#include "HugeInteger.h"
#include "HugeInteger.cpp"

using namespace std;

int main()
{
   bool isValidEquation = true;
   cout << "Welcome to the Equationator! Please enter equations when prompted" <<
   " and when you are done enter an equation with zeros as the inputs" << endl;
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
