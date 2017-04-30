// example: 
// using a line that requires its window

#include <iostream>

#include "window.hpp"
#include "figuur.hpp"

int main(int argc, char **argv){
   window w( 256, 64, 2 );
   figuur truck( w, 0, 0, 0);
   truck.print();
 
   
   return 0;
}


