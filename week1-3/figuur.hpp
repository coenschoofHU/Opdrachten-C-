#ifndef FIG_HPP
#define FIG_HPP

#include "window.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "line.hpp"
#include "figuur.hpp"

class figuur {
private:   
   int x;
   int y;
   bool z;
   window & w;
   
   rect body;
   circle wheel;
   circle wheel2; 
   circle wheel3;
   line cabin;
   line cabin2;
   line cabin3;
   
public:
   figuur( window & w, int x, int y, bool z):
      x( x ),
      y( y ),
	  z( z ),
      w( w ),
	  body( w, x+35, y, x+90, y+24 ),
	  wheel( w, x+45, y+30, 7 ),
	  wheel2(w, x+85, y+30 , 7),
	  wheel3(w, x+65, y+30, 7),
      cabin(w, x+90, y+24 , x+100 , y+24),
      cabin2(w, x+90, y, x+100 , y),
      cabin3(w, x+100, y, x+100 , y+24)
   {}
   void print();
};
   

#endif // FIG_HPP
