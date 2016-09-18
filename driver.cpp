/*
This is the driver program to test out the HugeInteger class
The user enters an equation and then the program sends a response.
*/
#include <iostream>
#include "HugeInteger.h"

using namespace std;
int main()
{
   string op;
   HugeInteger op1, op2;
   cout << "Please enter an equation with spaces: \n";
   cin >> op1 >> op >> op2;
   HugeInteger result;
   bool answer;
   if (op == "+")
   {
      result = op1 + op2;
      cout << result;
   }else if (op == "*")
   {
      result = op1 * op2;
      cout << result;
   }else if(op == "-")
   {
      result = op1 - op2;
      cout << result;
   }else if(op == "/")
   {
      result = op1 / op2;
      cout << result;
   }else if (op == ">=")
   {
      answer = op1 >= op2;
      cout << boolalpha << answer << endl;
   }else if (op == "<=")
   {
      answer = op1 <= op2;
      cout << boolalpha << answer << endl;
   }else if (op == "!=")
   {
      answer = op1 != op2;
      cout << boolalpha << answer << endl;
   }else if (op == "==")
   {
      answer = op1 == op2;
      cout << boolalpha << answer << endl;
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
