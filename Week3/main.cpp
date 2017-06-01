/// @file

/// \brief   
/// including libraries
/// \details
/// Including the libraries

#include "window.hpp"
#include "victim.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "wall.hpp"


/// \brief   
/// Main functions
/// \details
/// Walls are made to be 4 pixels wide, by every toggle interval the walls are
/// filled and made empty.
/// The victim is also made and 'explodes' when running the program.


int main(){
   window w( vector( 128, 64 ), 2 );
   wall top( w, vector( 0, 0 ), vector( 127,  4 ), 1, vector( 1, -1) );
   wall right( w, vector( 123, 5 ), vector( 127, 63 ), 1, vector( -1, 1));
   wall bottom( w, vector( 5, 59 ), vector( 127, 58 ), 1, vector( 1, -1) );
   wall left( w, vector( 0, 5 ), vector(   4, 63 ), 1, vector( -1, 1) );
   ball b( w, vector( 60, 30 ), 5, vector( 2, 2 ) );
   victim vict1(w, vector(20,20), vector(40,40));
   drawable * objects[] = { &b, &top, &left, &right, &bottom, &vict1};
   
   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      wait_ms( 100 );
      for( auto & p : objects ){
          p->update();
      }
	  
      for( auto & p : objects ){
         for( auto & other : objects ){
            p->interact( *other );
         } 
      }
   }
}

