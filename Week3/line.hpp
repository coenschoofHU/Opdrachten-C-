#ifndef LINE_HPP
#define LINE_HPP

#include "window.hpp"
#include "vector.hpp"
#include "drawable.hpp"

class line : public drawable {
private:
   vector end;
public:
   line( window & w, const vector & location, const vector & end ):
      drawable( w, location, end - location ),
      end( end )
   {}
   void draw() override;

   void setLocation(vector new_location) {
	   location = new_location;
   }
   void setEnd(vector new_end) {
	   end = new_end;
   }
};

#endif // LINE_HPP
