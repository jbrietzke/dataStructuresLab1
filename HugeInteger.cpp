#include <iostream>
#include <sstream>
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
   output << "It has this many significant digits: " << sigDigits << endl;
   output << "The number is: ";
   for (int i = 0; i < sigDigits; ++i)
   {
      output << digitsArray[i];
   }
   cout << endl;
}
// Need to throw in protection for overflow
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
// Need to have check for overflow / protect against overflow
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
// We are going to assume the left hand side is bigger
HugeInteger HugeInteger::operator-(const HugeInteger &op2)
{
   int value = 0;
   int carryOver = 0;
   string final;
   for (int i = sigDigits-1, j = op2.sigDigits-1; i >= 0; --i, --j)
   {
      if (j < 0)
      {
         value = digitsArray[i] + carryOver;
      }else
      {
         value = digitsArray[i] - op2.digitsArray[j] + carryOver;
      }
      if (value < 0)
      {
         carryOver = -1;
         value += 10;
      }else
      {
         carryOver = 0;
      }
      final += to_string(value);
   }
   // This makes sure there are no preceding zeros
   if (HugeInteger::operator==(op2) == true)
   {
      final = "0";
   }else
   {
      // Here we are getting rid of the zeros if they are first
      while(final[final.length()-1] == '0')
      {
         final = final.substr(0, final.length()-1);
      }
   }
   HugeInteger result(final, false);
   return result;
}
// We are going to assume the divisor is a storable number and it is an int
HugeInteger HugeInteger::operator/(const HugeInteger &op2)
{
   string divisorString;
   string numberOfTimesDivided;
   string remainderStr;
   int divisorNumber;
   int remainderInt;
   int newlyCreatedDivisibleNumber = 0;
   int totalCounter = 0;
   for (int i = 0; i < op2.sigDigits; ++i)
   {
      // creating a total number that we can turn into an int
      divisorString += to_string(op2.digitsArray[i]);
   }
   istringstream(divisorString) >> divisorNumber;
   do
   {
      string largeNumberStr;
      int largeNumberInt;
      if (newlyCreatedDivisibleNumber)
      {
         numberOfTimesDivided += (newlyCreatedDivisibleNumber >= divisorNumber) ? to_string(newlyCreatedDivisibleNumber / divisorNumber) : "0";
         remainderInt = newlyCreatedDivisibleNumber % divisorNumber;
         remainderStr = to_string(newlyCreatedDivisibleNumber % divisorNumber);
      }else
      {
         for (int i = 0; i < totalCounter+1; ++i)
         {
            largeNumberStr += to_string(digitsArray[i]);
         }
         istringstream(largeNumberStr) >> largeNumberInt;
         if (largeNumberInt / divisorNumber > 0)
         {
            numberOfTimesDivided += to_string(largeNumberInt / divisorNumber);
            remainderStr = (largeNumberInt % divisorNumber == 0) ? "1" : to_string(largeNumberInt % divisorNumber);
            remainderStr += to_string(digitsArray[totalCounter+1]);
            istringstream(remainderStr) >> newlyCreatedDivisibleNumber;
         }
      }
      totalCounter++;
   }while(totalCounter < sigDigits);
   HugeInteger result(numberOfTimesDivided, true);
   return result;
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

bool HugeInteger::isZero()
{
   bool isThisZero = digitsArray[0] == 0 ? true : false;
   return isThisZero;
}
// cin stops on spaces
// We are assuming there will be a spcade in between inputs
// We should implement a check to make sure not greater than 40 digits
// Look into cin.get() and cin.putback()
istream &operator>>(istream &input, HugeInteger &largeObject)
{
   string x;
   // The counter here is used to show how many we have skipped b/c ','
   int counter = 0;
   input >> x;
   x = (x.length() > 40) ? x.substr(0,40) : x;
   for (int i = 0; i < x.length(); ++i)
   {
      // This allows us to input numbers with commas
      if (x[i] == ',')
      {
         counter++;
         // This is to stop the input if the user put in a letter
      }else if (!isdigit(x[i]))
      {
         cout << "You made a mistake and entered a letter in a number!\n";
         break;
      }else{
         // Turns the string into an integer
         largeObject.digitsArray[i-counter] = x[i] - '0';
      }

   }
   // The significant digits = the length of string minus number of ','s
   largeObject.sigDigits = x.length() - counter;
   return input;
}
// This doesn't have to be passed by reference or value, but if by reference make const
ostream &operator<<(ostream &output, const HugeInteger &largeObject)
{
   largeObject.display(output);
   return output;
}
