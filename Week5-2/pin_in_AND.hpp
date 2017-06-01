/// @file

/// \brief   
/// including libraries
/// \details
/// Including the libraries

#ifndef PIN_IN_AND_HPP
#define PIN_IN_AND_HPP

#include "hwlib.hpp"

class pin_in_AND : hwlib::pin_in
{
private:
	hwlib::pin_in & pin_in1;
	hwlib::pin_in & pin_in2;
public:
	pin_in_AND(hwlib::pin_in & ipin_in1, hwlib::pin_in & ipin_in2);
	bool get(hwlib::buffering buf = hwlib::buffering::unbuffered) override;
};

#endif // PIN_IN_AND_HPP
