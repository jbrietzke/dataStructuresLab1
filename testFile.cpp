#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "HugeInteger.h"
#include <iostream>

using namespace std;
TEST_CASE( "+operator1", "works on numbers of the same value" )
{
    // My string constructor expects the string in the reverse order!!
    HugeInteger x("12");
    HugeInteger y("12");
    HugeInteger addedNum = x + y;
    REQUIRE( addedNum.getDigits() == "42");
}

TEST_CASE("+operator2", "works on numbers with different sigDigits")
{
   HugeInteger x("1");
   HugeInteger y("12");
   HugeInteger addedNum = x + y;
   REQUIRE(addedNum.getDigits() == "22");
}

TEST_CASE("+operator3", "works on numbers with zeros")
{
   HugeInteger x("0");
   HugeInteger y("0");
   HugeInteger addedNum = x + y;
   REQUIRE(addedNum.getDigits() == "0");
}

TEST_CASE("+operator4", "works on larger numbers")
{
   HugeInteger x("654");
   HugeInteger y("987");
   HugeInteger addedNum = x + y;
   REQUIRE(addedNum.getDigits() == "1245");
}

TEST_CASE("+operator5", "works for the in class example")
{
   HugeInteger x("747474450453637585");
   HugeInteger y("48484848484449");
   HugeInteger addedNum = x + y;
   REQUIRE(addedNum.getDigits() == "585830802539323231");
}

TEST_CASE("reverse string", "Checking to see if reversing string works")
{
   HugeInteger x("321");
   string y = x.change("321");
   REQUIRE(y == "123");
   string z = x.change("1010100");
   REQUIRE(z == "0010101");
}

// TEST_CASE("*multiplying1", "works for same number single digits")
// {
//    HugeInteger x("2");
//    HugeInteger y("2");
//    HugeInteger multiNum = x * y;
//    REQUIRE(multiNum.getDigits() == "4");
// }
