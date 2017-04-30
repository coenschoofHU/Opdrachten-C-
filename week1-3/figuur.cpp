#include "figuur.hpp"

void figuur::print() {
   
   body.print();
   wheel.print();
   wheel2.print();
   if(z) wheel3.print();
   cabin.print();
   cabin2.print();
   cabin3.print();

}