#include <iostream>
#include "HugeInteger.h"

using namespace std;

/*To connect this to the header file we use the name of the class, scope resolution
 operator, and the name of the method
*/
HugeInteger::HugeInteger()
{
   for (int i = 0; i < 40; ++i)
   {
      digitsArray[i] = 0;
   }
}

HugeInteger::HugeInteger(int size)
{
   for (int i = 0; i < 40; ++i)
   {
      digitsArray[i] = 0;
   }
   sigDigits = size;
}
/* We can use the member initializer to run the defaultConstructor first
 This constructor may not be necessary for me because I am already over-
 loading the cin operator
 */
HugeInteger::HugeInteger(int a[], int s)
{
   sigDigits = 0;
   for (int i = s-1, j = MAXDIGITS -1; i >= 0; i--, j--)
   {
      digitsArray[j] = a[i];
      sigDigits++;
   }
}
// This constructor is getting the string in  the reverse order
HugeInteger::HugeInteger(string numberString, bool isInOrder)
{
   for (int i = 0; i < 40; ++i)
   {
      digitsArray[i] = 0;
   }
   sigDigits = numberString.length();
   if (isInOrder)
   {
     for (int i = 0; i < sigDigits; ++i)
     {
        digitsArray[i] = numberString[i] - '0';
     }
   }else
   {
      for (int i = sigDigits-1, j = 0; i >= 0; --i, j++)
      {
         digitsArray[j] = numberString[i] - '0';
      }
   }
}

HugeInteger::~HugeInteger()
{
}

void HugeInteger::getSize()
{
   cout << MAXDIGITS << endl;
}

string HugeInteger::getDigits()
{
   string result = "";
   for (int i = 0; i < sigDigits; ++i)
   {
      cout << sigDigits << endl;
      result += digitsArray[i] + '0';
   }
   return result;
}

string HugeInteger::change(string reversedString)
{
   string newString = "";
   for (int i = reversedString.length()-1; i >= 0; --i)
   {
      newString += reversedString[i];
   }
   return newString;
}

void HugeInteger::display(ostream &output) const
{
   output << "sigDigits == " << sigDigits << endl;
   for (int i = 0; i < sigDigits; ++i)
   {
      output << digitsArray[i];
   }
   cout << endl;
}

HugeInteger HugeInteger::operator+(const HugeInteger &op2)
{
   /* Create a HugeInteger object to store the result
      Only on non-static methods is the *this there becuase statics are shared
   */
   string summedNumberString = "";
   int carryOver = 0;
   int biggestInt = (sigDigits >= op2.sigDigits) ? sigDigits : op2.sigDigits;
   int mySigDigs = sigDigits;
   int otherSigDigs = op2.sigDigits;
   int summedNumber[biggestInt+1];
   for (int i = 0; i < biggestInt+1; ++i)
   {
      summedNumber[i] = -9999;
   }
   // We do -1 because we need to have room for a possible carry over
   // Eventually refactor to make it more clear what is going on
   for (int i = biggestInt-1, j = 0, k = mySigDigs-1, m = otherSigDigs-1; i >= -1; i--, j++, k--, m--)
   {
      int individualPlaceValue;
      if (k < 0 && m >= 0)
      {
         individualPlaceValue = op2.digitsArray[m] + carryOver;
      }else if(m < 0 && k >= 0)
      {
         individualPlaceValue = digitsArray[k] + carryOver;
      }else if(k < 0 && m < 0)
      {
         individualPlaceValue = carryOver;
      }else
      {
         individualPlaceValue = digitsArray[k] + op2.digitsArray[m] + carryOver;
      }

      if (individualPlaceValue >= 10)
      {
         individualPlaceValue -= 10;
         carryOver = 1;
      }
      else
      {
         carryOver = 0;
      }
      summedNumber[j] = individualPlaceValue;
   }
   for (int i = biggestInt-1, j = 0; i >= -1; i--, j++)
   {
      // If I take out this cout the program doesn't work... I do not know why
      //cout << "I am being called JACKSON: " <<to_string(summedNumber[j]) << endl;
      summedNumberString += to_string(summedNumber[j]);
   }
   int lastDigit = summedNumberString.length() - 1;
   if (summedNumberString[lastDigit] == '0')
   {
      summedNumberString = summedNumberString.substr(0,lastDigit);
   }
   HugeInteger result(summedNumberString, false);
   return result;

}

HugeInteger HugeInteger::operator*(const HugeInteger &op2)
{
   HugeInteger result;
   return result;
}

istream &operator>>(istream &input, HugeInteger &largeObject)
{
   string x;
   cout << "Please enter your huge integer here: ";
   input >> x;
   for (int i = 0; i < x.length(); ++i)
   {
      if (!isdigit(x[i]))
      {
         break;
      }
      largeObject.digitsArray[i] = x[i] - '0';
   }
   largeObject.sigDigits = x.length();
   return input;
}
// This doesn't have to be passed by reference or value, but if by reference make const
ostream &operator<<(ostream &output, const HugeInteger &largeObject)
{
   largeObject.display(output);
   return output;
}
