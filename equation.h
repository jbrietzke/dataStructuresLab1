/*
This is the equation class
It has two numeric inputs (op1, op2)
It has an operator to act on the input (op)
And it can return the result of the equation (calculate)
*/

#ifndef EQUATION_H
#define EQUATION_H
#include "HugeInteger.h"


class Equation
{
   //overload the input and output
   friend istream &operator>>(istream &, Equation &);
   friend ostream &operator<<(ostream &, const Equation &);
  public:
   Equation();
   Equation(const HugeInteger &, const HugeInteger &);
   void calculate();
   bool validate();
  private:
   HugeInteger op1, op2;
   string op;
   bool answer;
   HugeInteger result;
};

#endif
