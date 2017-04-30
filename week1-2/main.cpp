// example: 
// using a line that requires its window

#include <iostream>

#include "window.hpp"
#include "rectangle.hpp"

int main(int argc, char **argv){
   window w( 128, 128, 2 );
   rect Rectangle( w, 5, 5, 30, 40 );
   rect Rectangle2( w, 40, 40, 65, 75 );
   Rectangle.print();
   Rectangle2.print();
   
 
   
   return 0;
}


