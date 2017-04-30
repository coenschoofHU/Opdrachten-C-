#include "rectangle.hpp"

void rect::print(){
	for(int i = start_x; i <= end_x; i++)
		for(int j = start_y; j <= end_y; j++)
			w.draw(i,j);
}
