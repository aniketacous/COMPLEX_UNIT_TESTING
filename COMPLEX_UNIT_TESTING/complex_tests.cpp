#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "complex.h"
#include <sstream>

using namespace csis3700;
using namespace std;
TEST_CASE("default should be zero", "complex")
{
    complex c;
    REQUIRE(c.get_real()==0);
    REQUIRE(c.get_imaginary()==0);
}
TEST_CASE("default of imaginary is zero when real has value", "complex")
{
    complex c(4);
    REQUIRE(c.get_real()==4);
    REQUIRE(c.get_imaginary()==0);
}
TEST_CASE("when real and imaginary both has a value","complex")
{
    complex c(4,2);
    REQUIRE(c.get_real()==4);
    REQUIRE(c.get_imaginary()==2);
}
TEST_CASE("magnitude returns the magnitude of complex number","complex")
{
    complex c(4,2);
    REQUIRE(c.magnitude() == Approx(4.47).epsilon(0.01));
}
TEST_CASE("normal returns the normal of complex number","complex")
{ 
   complex c(4,2);
   REQUIRE(c.norm() == 20);
}
TEST_CASE("conjugate will be returned", "complex")
{
   //const complex c(4,2);
    //complex b =c.conjugate();
    //REQUIRE(b == complex(4,-2));
    complex c(4,2);
    complex d(4,-2);
    REQUIRE(c.conjugate() == d);
}
TEST_CASE("Negative Complex Number","complex")
{
    complex c(4,2);
    complex d(-4,-2);
    complex a(-3,2);
    complex b(3,-2);
    complex e(-0,-0);
    complex f(0,0);
    REQUIRE(c.negate() == d);
    REQUIRE(a.negate() == b);
    REQUIRE(e.negate() == f);
}
TEST_CASE("reciprocal returns correct reciprocal", "complex")
{
    complex c(4,2);
    complex d(4.0/20,-2.0/20);
    
    
    REQUIRE(c.reciprocal() == d);
}
TEST_CASE("operator << prints the correct complex number", "complex")
{
   stringstream ss;
   complex c(2,4);
   ss << c;
   REQUIRE(ss.str() == "2 + 4i");
}
TEST_CASE(" operator << should print correct imaginary number and sign must be taken care" , "complex")
{
   stringstream ss;
   complex c(2,-4);
   ss<<c;
   REQUIRE(ss.str() == "2 - 4i");
}
TEST_CASE("imaginary part mjust be printed zero if constructor has only real value given","complex")
{ 
   stringstream ss;
   complex c(2);
   ss<<c;
   REQUIRE(ss.str() == "2");
}
TEST_CASE("if 0,0 is provided then 0 must be printed", "complex")
{ 
   stringstream ss;
   complex c(0,0);
   ss<<c;
   REQUIRE(ss.str() == "0");
}
TEST_CASE("if real part is zero only imaginary part must be printed with an i","complex")
{
   stringstream ss;
   complex c(0,4);
   ss<<c;
   REQUIRE(ss.str() =="4i");
}
TEST_CASE("if imaginary part is zero only real part must be printed ", "complex")
{
   stringstream ss;
   complex c(4,0);
   ss<<c;
   REQUIRE(ss.str()=="4");
}
TEST_CASE("== and != compares complex number correctly","complex")
{ 
   complex c(4,5);
   complex d(4,5);
   complex e(4,6);
   REQUIRE(c==d);
   REQUIRE(c!=e);
}
TEST_CASE("+ and - works perfectly ", "complex")
{
  complex c(4,5);
  complex d(5,6);
  complex e(9,11);
  complex f(-1,-1);
  REQUIRE(c+d==e);
  REQUIRE(c-d==f);
}
TEST_CASE("* and / works perfectly ","complex")
{ 
  complex c(4,5);
  complex d(4,5);
  complex e(-9,40);
  complex f(-285,146);
  complex a(1);
  complex b(5,6);
  complex g(3.196,4.163);
  complex z=e/b;
  REQUIRE(z.get_real() == Approx(3.196).epsilon(0.001));
  REQUIRE(z.get_imaginary() == Approx(4.163).epsilon(0.001));
  REQUIRE(c*d == e);
  REQUIRE(c/d == a);
  REQUIRE(b*e == f);
  //REQUIRE(e/b == g);
  
  
}





















