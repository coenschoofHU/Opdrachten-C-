#ifndef WALL_HPP
#define WALL_HPP

#include "window.hpp"
#include "rectangle.hpp"
#include "wall.hpp"
#include <iostream>

class wall : public rectangle {
private:
	bool filled;
	int update_interval;
	int update_count;
	vector bounce;
public:
	wall( window & w, const vector &location, const vector &end, const int &update_interval, vector bounce);
	void draw() override;
	void update() override;
};

#endif // WALL_HPP
