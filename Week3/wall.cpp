#include "wall.hpp"

wall::wall( window & w, const vector & location, const vector & end, const int & update_interval, vector bounce):
	rectangle ( w, location, end),
	update_interval(update_interval),
	bounce( bounce )
{drawable::bounce = bounce;}


void wall::draw(){
	filled = 1;
	rectangle::draw();
	if (filled == 1){
		for(int x0 = location.x; x0 < end.x; ++x0){
			for(int y0 = location.y; y0 < end.y; ++y0){
				w.draw(vector (x0,y0));
			}
		}
	}
}

void wall::update() {
	
}
