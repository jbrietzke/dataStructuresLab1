#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "HugeInteger.h"
#include <iostream>

using namespace std;
TEST_CASE( "+operator1", "works on numbers of the same value" )
{
    // My string constructor expects the string in the reverse order
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
