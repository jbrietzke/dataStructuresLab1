#include <iostream>
#include "HugeInteger.h"

using namespace std;
int main()
{
   string op1, op2, op;
   cout << "Please enter an equation with spaces: \n";
   cin >> op1 >> op >> op2;
   HugeInteger num1(op1, true);
   HugeInteger num2(op2, true);
   HugeInteger result;
   bool answer;
   if (op == "+")
   {
      result = num1 + num2;
      cout << "Plus\n";
   }else if (op == "*")
   {
      result = num1 * num2;
      cout << "Times\n";
   }else if (op == ">=")
   {
      answer = num1 >= num2;
      cout << "Greater\n";
   }else if (op == "<=")
   {
      answer = num1 <= num2;
      cout << "Lesser\n";
   }else if (op == "!=")
   {
      answer = num1 != num2;
      cout << "notEqual\n";
   }else if (op == "==")
   {
      answer = num1 == num2;
      cout << "equal\n";
   }else
   {
      cout << "In later additions of the lab this will be available\n";
   }
   cout << result << endl;

   // string bigBoi;
   // string delim = " ";
   // cin >> bigBoi;
   // cout << "This is bigBoi: " << bigBoi << endl;

   // string token1 = bigBoi.substr(0, bigBoi.find(delim));
   // cout << "This is token1: " << token1 << endl;
   // cout << "This is bigBoi: " << bigBoi << endl;

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
