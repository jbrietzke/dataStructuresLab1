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

void HugeInteger::setDigitsArray(string numberString, bool isInOrder)
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

void HugeInteger::getSize()
{
   cout << MAXDIGITS << endl;
}

string HugeInteger::getDigits()
{
   string result = "";
   cout << "this is the sigDigits: " << sigDigits << endl;
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
//This only works if the left side number is smaller
HugeInteger HugeInteger::operator*(const HugeInteger &op2)
{
   const int MAXLINES = 20;
   int carryOver = 0;
   int individualPlaceValue;
   const int SIZE = 40;
   string linesToBeAdded[SIZE];
   string individualNumber = "";
   HugeInteger final("0", true);

   if (sigDigits <= op2.sigDigits)
   {
      for (int i = sigDigits-1, digitSpot = 0; i >= 0; --i, digitSpot++)
      {
         for (int i = 0; i < digitSpot; ++i)
         {
            individualNumber += "0";
         }
         for (int j = op2.sigDigits-1; j >= -1; --j)
         {
               int value = -9999;
               if (i < 0 && j >= 0)
               {
                  cout << "Here\n";
                  value = op2.digitsArray[j] + carryOver;
               }else if(j < 0 && i >= 0 && carryOver > 0)
               {
                  value = carryOver;
               }else if(i < 0 && j < 0)
               {
                  cout << "HereHereHere\n";
                  value = carryOver;
               }else
               {
                  cout << "DEFDFHERE\n";
                  value = digitsArray[i] * op2.digitsArray[j] + carryOver;
                  cout << "Here is the val: " << digitsArray[i] << '\t'<< op2.digitsArray[j]<< '\t' << carryOver << endl;
               }
               if (value >= 10)
               {
                  individualPlaceValue = value % 10;
                  carryOver = value / 10;
               }else
               {
                  individualPlaceValue = value;
                  carryOver = 0;
               }
               if (individualPlaceValue > 0)
               {
                  individualNumber += individualPlaceValue + '0';
               }else
               {
                  individualNumber += "0";
               }

         }
         linesToBeAdded[i] = individualNumber;
         individualNumber = "";
         char lastDigit = linesToBeAdded[i].back();
         if (lastDigit == '0')
         {
            cout << "The lastDigit is indeed getting hit\n\n";
            cout << linesToBeAdded[i] << " That was before trimming\n";
            cout << "This is op2.sigDigits: " << op2.sigDigits << endl;
            linesToBeAdded[i]=linesToBeAdded[i].substr(0,op2.sigDigits+digitSpot);
            cout << linesToBeAdded[i] << " That is after trimming\n";
         }
      }
      cout << "This is what the linesToBeAdded[0] looks like " << linesToBeAdded[0] << endl;
      cout << "This is what the linesToBeAdded[1] looks like " << linesToBeAdded[1] << endl;
      HugeInteger numbersToBeAdded[MAXLINES];
      for (int ii = 0; ii < op2.sigDigits; ++ii)
      {
         cout << "I am getting hit\n";
         numbersToBeAdded[ii].setDigitsArray(linesToBeAdded[ii], false);
         cout << "this is my new numbersToBeAdded: " << numbersToBeAdded[ii] << endl;
         final = final + numbersToBeAdded[ii];
         cout << "this is final: " << final << endl;
      }
   }else
   {
      for (int i = op2.sigDigits-1, digitSpot = 0; i >= 0; --i, digitSpot++)
      {
         for (int i = 0; i < digitSpot; ++i)
         {
            individualNumber += "0";
         }
         for (int j = sigDigits-1; j >= -1; --j)
         {
               int value = -9999;
               if (i < 0 && j >= 0)
               {
                  cout << "Here\n";
                  value = digitsArray[j] + carryOver;
               }else if(j < 0 && i >= 0 && carryOver >= 0)
               {
                  value = carryOver;
               }else if(i < 0 && j < 0)
               {
                  cout << "HereHereHere\n";
                  value = carryOver;
               }else
               {
                  cout << "DEFDFHERE\n";
                  cout << "This is digitsArray[j]: " << digitsArray[j] << " this is j: " << j << endl;
                  value = op2.digitsArray[i] * digitsArray[j] + carryOver;
                  cout << "Here is the val: " << op2.digitsArray[i] << '\t'<< digitsArray[j]<< '\t' << carryOver << endl;
               }
               if (value >= 10)
               {
                  individualPlaceValue = value % 10;
                  carryOver = value / 10;
               }else
               {
                  individualPlaceValue = value;
                  carryOver = 0;
               }
               if (individualPlaceValue > 0)
               {
                  individualNumber += individualPlaceValue + '0';
               }else
               {
                  individualNumber += "0";
               }

         }
         linesToBeAdded[i] = individualNumber;
         individualNumber = "";
         char lastDigit = linesToBeAdded[i].back();
         if (lastDigit == '0')
         {
            cout << "The lastDigit is indeed getting hit\n\n";
            cout << linesToBeAdded[i] << " That was before trimming\n";
            cout << "This is sigDigits: " << sigDigits << endl;
            linesToBeAdded[i]=linesToBeAdded[i].substr(0,sigDigits+digitSpot);
            cout << linesToBeAdded[i] << " That is after trimming\n";
         }
      }
      cout << "This is what the linesToBeAdded[0] looks like " << linesToBeAdded[0] << endl;
      cout << "This is what the linesToBeAdded[1] looks like " << linesToBeAdded[1] << endl;
      HugeInteger numbersToBeAdded[MAXLINES];
      for (int ii = 0; ii < sigDigits; ++ii)
      {
         cout << "I am getting hit\n";
         numbersToBeAdded[ii].setDigitsArray(linesToBeAdded[ii], false);
         cout << "this is my new numbersToBeAdded: " << numbersToBeAdded[ii] << endl;
         final = final + numbersToBeAdded[ii];
         cout << "this is final: " << final << endl;
      }
   }
   return final;
}

bool HugeInteger::operator==(const HugeInteger &op2)
{
   bool isEqual = true;
   if (sigDigits != op2.sigDigits)
   {
      isEqual = false;
   }else
   {
      for (int i = 0; i < sigDigits; ++i)
      {
         if (digitsArray[i] != op2.digitsArray[i])
         {
            isEqual = false;
            break;
         }
      }
   }
   return isEqual;
}

bool HugeInteger::operator!=(const HugeInteger &op2)
{
   return !(HugeInteger::operator==(op2));
}

bool HugeInteger::operator>=(const HugeInteger &op2)
{
   bool isBigger = false;
   if (sigDigits > op2.sigDigits)
   {
      isBigger = true;
   }else if (sigDigits == op2.sigDigits)
   {
      for (int i = 0; i < sigDigits; ++i)
      {
         if (digitsArray[i] > op2.digitsArray[i])
         {
            isBigger = true;
            break;
         }else if (digitsArray[i] < op2.digitsArray[i])
         {
            isBigger = false;
            break;
         }
      }
      if (!isBigger)
      {
         isBigger = HugeInteger::operator==(op2);
      }
   }
   return isBigger;
}

bool HugeInteger::operator<=(const HugeInteger &op2)
{
   bool isSmaller = !HugeInteger::operator>=(op2);
   if (!isSmaller)
   {
      isSmaller = HugeInteger::operator==(op2);
   }
   return isSmaller;
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
