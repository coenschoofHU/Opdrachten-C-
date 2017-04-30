#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iomanip>

/// @file

/// \brief
/// rational ADT
/// \details
/// This is an ADT that implements rational (fractional) values.
/// The counter and denominator are stored as two (signed) integers.
/// The appropriate constructors and operators are provided.
///
/// Rational values are always simplied (reduced): the counter
/// and denominator have no common factors.
class rational {
private:
   int counter;
   int denominator;
   
   void reduce(){
      int a = counter;
      int b = denominator;

      while( b ){
         int temp = b;
         b = a % b;
         a = temp;
      }

      if( a ){
         counter /= a;
         denominator /= a;
      }
   }
   
public:

   /// \brief
   /// constructor from explicit values
   /// \details
   /// This constructor initializes a rational from its counter and denominator.
   /// The default value for the denominator is 1, so a rational be initialized
   /// with just a whole value.
   rational( int counter, int denominator = 1 ):
     counter( counter ), denominator( denominator )
   {reduce();}
   
   /// \brief   
   /// compare two rational values
   /// \details
   /// This operator tests for equality. It returns true
   /// if and only if the counter and denminator of both
   /// operands are equal.
   bool operator==( const rational & rhs ) const {
      return ( counter == rhs.counter) && ( rhs.denominator == denominator );
   }

   /// \brief
   /// output operator for a rational value
   /// \details
   /// This operator<< prints a constructor in the format
   /// [counter/denominator] where both values are printed as
   /// decimal values.
   friend std::ostream & operator<<( std::ostream & lhs, const rational & rhs ){
      return lhs 
		 //<< "\n-------\n"
         << "[0x" 
		 << std::setw(2)
		 << std::setfill('0')
		 << std::hex
         << rhs.counter 
		 << "/"
		 << "0x"
		 << std::setw(2)
		 << std::setfill('0')
         << std::hex 
         << rhs.denominator
         << "]";
		// << "\n-------\n"
   }   
   
   /// \brief   
   /// multiply a rational by an integer
   /// \details
   /// This operator* multiplies a rational value by an integer value.
   rational operator*( const int rhs ) const {
      return rational( counter * rhs , denominator);
   }
   
   /// \brief   
   /// multiply a rational by a rational
   /// \details
   /// This operator* multiplies a rational value by a rational value.
   rational operator*( const rational & rhs ) const {
      return rational( 
		counter * rhs.counter,
		denominator * rhs.denominator
      );
   }
   
   /// \brief   
   /// add a rational to another rational
   /// \details
   /// This operator+= adds a rational value a rational variable.
   rational & operator+=( const rational & rhs ){
      counter = counter * rhs.denominator + rhs.counter * denominator;
      denominator *= rhs.denominator;
      reduce();
      return *this;
   }
   
   
   /// \brief
   /// multiplies fractions
   /// \details
   /// This operator*= multiplies two fractions and returns a fraction.
   rational operator*=( const rational & rhs ){
      counter = counter * rhs.counter;
      denominator = denominator * rhs.denominator;
      reduce();
      return rational(counter, denominator);
   }
   
};

#endif