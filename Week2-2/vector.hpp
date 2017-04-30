#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iomanip>

/// @file

/// \brief
/// Vector
/// \details
/// Here the class vector will be made consisting of x and y coordinates.

class vector {
private:
   int x;
   int y;

public:

   /// \brief
   /// constructor from explicit values
   /// \details
   /// This constructor initializes a vector from its coordinates called x and y.
   /// The default value for both coordinates are 0, so a vector be initialized
   /// at the origin of the given vector.
   vector( int x = 0, int y = 0 ):
     x( x ), y( y )
   {}
   
	int get_x() const {
		return x;
   }
   
   int get_y() const {
		return y;
   }
   
   /// \brief   
   /// compare two vectors
   /// \details
   /// This operator tests for equality. It returns true
   /// if and only if the x and y value of both
   /// vectors are equal.
   bool operator==( const vector & vctr ) const {
      return ( x == vctr.x) && ( vctr.y == y );
   }
	
   /// \brief
   /// output operator for a vector
   /// \details
   /// This operator<< prints a constructor in the format
   /// (x,y) where both values are printed as
   /// decimal values.
   friend std::ostream & operator<<( std::ostream & lhs, const vector & vctr ){
      return lhs 
		 << "("
		 << vctr.x
		 << ","
		 << vctr.y
		 << ")";
   }   
   /// \brief   
   /// add a vector by another vector
   /// \details
   /// This operator+ adds two vectors.
   vector operator+( const vector & vctr) const {
      return vector( x + vctr.x , y + vctr.y);
   }
   /// \brief   
   /// multiply a vector by an integer
   /// \details
   /// This operator* multiplies a vector by an integer value.
   vector operator*( const int n ) const {
      return vector( x * n , y * n);
   }
   
   /// \brief   
   /// multiply a vector by an int
   /// \details
   /// This operator* multiplies a vector by an integer value.
   vector operator*=( const int n){
      x *= n;
      y *= n;
      return *this;
   }
   
   
   /// \brief   
   /// add a vector by another vector
   /// \details
   /// This operator+= adds two vectors.
   vector & operator+=( const vector & vctr ){
      x += vctr.x;
      y += vctr.y;
      return *this;
   }
   
};
   /// \brief
   /// multiply a vector by an int
   /// \details
   /// This operator*= multiplies an integer with a vector.
	vector operator*( const int n, const vector vctr) {
      return vector( vctr.get_x() * n, vctr.get_y() * n);
   }
#endif