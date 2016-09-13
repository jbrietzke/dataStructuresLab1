#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "HugeInteger.h"
#include <iostream>

using namespace std;
// TEST_CASE( "+operator1", "works on numbers of the same value" )
// {
//     // My string constructor expects the string in the reverse order!!
//     HugeInteger x("12", true);
//     HugeInteger y("12", true);
//     HugeInteger addedNum = x + y;
//     REQUIRE( addedNum.getDigits() == "24");
// }

// TEST_CASE("+operator2", "works on numbers with different sigDigits")
// {
//    HugeInteger x("1", true);
//    HugeInteger y("12", false);
//    HugeInteger addedNum = x + y;
//    REQUIRE(addedNum.getDigits() == "22");
// }

// TEST_CASE("+operator3", "works on numbers with zeros")
// {
//    HugeInteger x("0", false);
//    HugeInteger y("0", false);
//    HugeInteger addedNum = x + y;
//    REQUIRE(addedNum.getDigits() == "0");
// }

// TEST_CASE("+operator4", "works on larger numbers")
// {
//    HugeInteger x("654", false);
//    HugeInteger y("987", false);
//    HugeInteger addedNum = x + y;
//    REQUIRE(addedNum.getDigits() == "1245");
// }

// TEST_CASE("+operator5", "works for the in class example")
// {
//    HugeInteger x("747474450453637585", false);
//    HugeInteger y("48484848484449", false);
//    HugeInteger addedNum = x + y;
//    REQUIRE(addedNum.getDigits() == "585830802539323231");
// }

// TEST_CASE("reverse string", "Checking to see if reversing string works")
// {
//    HugeInteger x("321", true);
//    string y = x.change("321");
//    REQUIRE(y == "123");
//    string z = x.change("1010100");
//    REQUIRE(z == "0010101");
// }

// TEST_CASE("*multiplying1", "works for same number single digits")
// {
//    HugeInteger x("1", true);
//    HugeInteger y("5", true);
//    HugeInteger multiNum = x * y;
//    REQUIRE(multiNum.getDigits() == "5");
// }

// TEST_CASE("*multiplying2", "works with the second number being larger")
// {
//    HugeInteger x("9", true);
//    HugeInteger y("9", true);
//    HugeInteger multiNum = x * y;
//    REQUIRE(multiNum.getDigits() == "81");
// }

TEST_CASE("*multiplying3", "works with double digit numbers")
{
   HugeInteger x("10", true);
   HugeInteger y("10", true);
   HugeInteger multiNum = x * y;
   REQUIRE(multiNum.getDigits() == "100");

}
