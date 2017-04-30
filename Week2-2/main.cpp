#include "ostream"
#include "vector.hpp"


// needed to get Catch working with MinGW
#define TWOBLUECUBES_CATCH_REPORTER_JUNIT_HPP_INCLUDED
namespace Catch{ class JunitReporter{ ~JunitReporter(); }; };

#include "catch_with_main.hpp"

TEST_CASE( "equality, equal (==)" ){
   vector vctr( 4, 7 );
   REQUIRE( vctr == vector( 4, 7 ) ); 
}

TEST_CASE( "multiply by integer ( vector * int)" ){
   vector vctr( 1, 1 );
   vector x = vctr * 5;
   REQUIRE( vctr == vector( 1, 1 ) );
   REQUIRE( x == vector( 5, 5 ) );
}

TEST_CASE( "add vector into vector (vctr += vector) " ){
   vector vctr( 1, 1 );
   vctr += vector( 1, 1 ); 
   REQUIRE( vctr == vector( 2, 2 ) );
}

TEST_CASE( "multiply two vectors" ){
   vector vctr( 1, 1 );
   vctr *= 3; 
   REQUIRE( vctr == vector( 3, 3 ) );
}

TEST_CASE( "multiply an int by a vector" ){
   vector vctr(1, 1);
   vector s = 6 * vctr;
   REQUIRE( s == vector( 6, 6 ) );
}

TEST_CASE( "add two vectors" ){
   vector vctr(1, 1);
   vector s(1, 1);
   vector c = vctr + s;
   REQUIRE( c == vector( 2, 2 ) );
}






