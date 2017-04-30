// example:
// declaration of a line class that stores its window

#ifndef RECT_HPP
#define RECT_HPP

#include "window.hpp"

#include "rectangle.hpp"

class rect {
private:
   int start_x;
   int start_y; 
   int end_x;
   int end_y;
   window & w;
public:
   rect( window & w, int start_x, int start_y, int end_x, int end_y ):
      start_x( start_x ),
      start_y( start_y ),
      end_x( end_x ),
      end_y( end_y ),
      w( w )
   {}
   void print();
};

#endif // LINE_HPP
