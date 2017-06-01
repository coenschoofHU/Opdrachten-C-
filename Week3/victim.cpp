/// @file

/// \brief   
/// including libraries
/// \details
/// Including the libraries


#include "victim.hpp"
#include "window.hpp"
#include <iostream>

/// \brief   
/// Function that draws the victim
/// \details
/// 

void victim::draw() {
	if (changed == 1) {
		rectangle::retract();
		rectangle::draw();
		changed = 0;
	}
}

/// \brief   
/// Function that takes care of the interaction with the victim.
/// \details
/// 

void victim::interact( drawable & other ){
		
		start.x += 5;
		start.y += 5;
		end.x -= 5;
		end.y -= 5;
		
		left.setEnd(vector(start.x, end.y));
		right.setEnd(vector(end.x, end.y));
		top.setEnd(vector(end.x, start.y));
		bottom.setEnd(vector(end.x, end.y));
		
		left.setLocation(vector(start.x, start.y));
		right.setLocation(vector(end.x, start.y));
		top.setLocation(vector(start.x, start.y));
		bottom.setLocation(vector(start.x, end.y));
		
		changed = true;
		in_contact = false;
	
}