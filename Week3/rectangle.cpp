// example:
// definition of the functions of a rectangle object

#include "rectangle.hpp"

rectangle::rectangle( window & w, const vector & start, const vector & end ):
   drawable( w, start, end - start ),
   start( start ),
   end( end ),
   left(   w, vector( start.x, start.y ), vector( start.x, end.y   ) ),
   right(  w, vector( end.x,   start.y ), vector( end.x,   end.y   ) ),
   top(    w, vector( start.x, start.y ), vector( end.x,   start.y ) ),
   bottom( w, vector( start.x, end.y   ), vector( end.x,   end.y   ) )
{}

void rectangle::draw(){
   left.draw();
   right.draw();
   top.draw();
   bottom.draw();
}

void rectangle::retract(){
	for(int i = start.x - 1; i <= end.x + 1; i++) {
		for(int j = start.y - 1; j <= end.y + 1; j++) {
			w.draw(vector(i,j));
		}
	}
}