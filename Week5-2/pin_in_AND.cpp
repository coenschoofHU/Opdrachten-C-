/// @file

/// \brief   
/// including library
/// \details
/// Including the pin_in_AND library

#include "pin_in_AND.hpp"

/// \brief   
/// Main function
/// \details
/// 

pin_in_AND::(hwlib::pin_in & ipin_in1, hwlib::pin_in & ipin_in2):
	pin_in1 (ipin_in1),
	pin_in2 (ipin_in2)
{}

bool pin_in_AND::get(hwlib::buffering) override
{
	return ( !pin_in1.get() && !pin_in2.get());
}