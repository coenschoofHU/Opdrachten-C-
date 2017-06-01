/// @file

/// \brief   
/// including libraries
/// \details
/// Including the libraries


#ifndef VICTIM_HPP
#define VICTIM_HPP

#include "window.hpp"
#include "rectangle.hpp"
#include "vector.hpp"

class victim : public rectangle
{
private:
	bool changed = true;
	bool in_contact = false;
public:
	victim(window & w, const vector start, const vector end):
		rectangle( w, start, end)
	{}
	
	void draw() override;
	void interact( drawable & other ) override;
	
};

#endif // VICTIM_HPP
