#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <ostream>
#include "window.hpp"
#include "vector.hpp"

/// \brief   
/// Drawable function
/// \details
/// A bounce vector is added in the drawable function to take care of the ball to bounce across the window


class drawable {
protected:
   window w;
   vector location;
   vector size;
   vector bounce;
public:
   drawable( window & w, const vector & location, const vector & size, const vector & bounce = vector(1,1) );   
   bool overlaps( const drawable & other );
   virtual void draw() = 0;
   virtual void update(){}
   virtual void interact( drawable & other ){}
   vector getBounce() {
	   return bounce;
   }
   
   std::ostream & print( std::ostream & out ) const;
};

std::ostream & operator<<( std::ostream & lhs, const drawable & rhs );

#endif // DRAWABLE_HPP
