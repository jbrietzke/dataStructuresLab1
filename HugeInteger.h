//This ensures that the header file is only included once
#ifndef HugeInteger_H
#define HugeInteger_H

using namespace std;
// Name of the directive should be the name of the class
class HugeInteger
{
   /* The iostreams are not objects of our class so they must be declared
      globally
   */
   friend istream &operator>>(istream &, HugeInteger &);
   friend ostream &operator<<(ostream &, const HugeInteger &);

   public:
      HugeInteger();
      HugeInteger(int);
      HugeInteger(int a[], int s);
      HugeInteger(string, bool);
      ~HugeInteger();
      void setDigitsArray(string, bool);
      void getSize();
      void setSize();
      string change(string);
      string getDigits();

      /*This doesn;t need to be public because we are going to overload
        void display();
        overloading the '+' operator within the public because it is on the
        left side
      */
      HugeInteger operator+(const HugeInteger &);
      HugeInteger operator*(const HugeInteger &);
      HugeInteger operator-(const HugeInteger &);
      HugeInteger operator/(const HugeInteger &);
      bool operator==(const HugeInteger &);
      bool operator!=(const HugeInteger &);
      bool operator>=(const HugeInteger &);
      bool operator<=(const HugeInteger &);
      bool isZero();
   private:
      //const long MAXDIGITS;
      // static const has to exist before member initializer in constructor
      //static data members will exist before instance of the class is created
      // const is read only and initialized at memory allocation time
      static const int MAXDIGITS = 40;
      int digitsArray[MAXDIGITS];
      // The const keyword at the end of the declaration allows it to work on const objects
      void display(ostream &) const;
      // This will tell us how many significant digits(digits that are used)
      int sigDigits;

};
#endif
