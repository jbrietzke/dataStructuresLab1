class Equation
{
   //overload the input and output
  public:
   Equation();
   Equation(const HugeInteger &, const HugeInteger &);
   void calculate();
  private:
   HugeInteger op1, op2;
   char operator;
   HugeInteger result;
};
