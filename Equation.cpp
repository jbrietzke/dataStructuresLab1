#include "Equation.h"

Equation::Equation()
{

}
// Invokes the overloaded operator in the HugeInteger class corresponding to input
void Equation::calculate()
{
   if (op == "+")
   {
      result = op1 + op2;
   }else if (op == "*")
   {
      result = op1 * op2;
   }else if(op == "-")
   {
      result = op1 - op2;
   }else if(op == "/")
   {
      result = op1 / op2;
   }else if (op == ">=")
   {
      answer = op1 >= op2;
   }else if (op == "<=")
   {
      answer = op1 <= op2;
   }else if (op == "!=")
   {
      answer = op1 != op2;
   }else if (op == "==")
   {
      answer = op1 == op2;
   }else
   {
      cout << "In later additions of the lab this will be available\n";
   }
}

// Makes sure the equation is valid and not just zeros
bool Equation::validate()
{
   bool response = true;
   if (op1.getDigits() == "0" && op2.getDigits() == "0")
   {
      response = false;
   }
   return response;
}

istream &operator>>(istream &input, Equation &myEquation)
{
   input >> myEquation.op1 >> myEquation.op >> myEquation.op2;
   return input;
}

// This doesn't have to be passed by reference or value, but if by reference make const
// Becuasue some operations are true/false and others are numbers the outputs are different
// Do to that we put that check of output in the overloaded function
ostream &operator<<(ostream &output, const Equation &myEquation)
{
   if (myEquation.op.length() > 1)
   {
      output << boolalpha << myEquation.answer << endl;
   }else
   {
      output << myEquation.result << endl;
   }
   return output;
}
