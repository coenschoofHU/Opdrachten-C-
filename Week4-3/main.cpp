/// @file


/// \brief   
/// including library
/// \details
/// Including the hardware library
#include "hwlib.hpp"

/// \brief   
/// Function that takes care of controlling both the LEDs and the buttons
/// \details
/// This function controls the LEDs per click of the button by using bit shifting. Since i've used five LEDs I had to use 
/// 0x1F (11111) to shift with (0x1F means that all LEDs are on). The second conditions in the if-statements prevent the user
/// from bit shifting too far out of bounds. 
void cascadingLEDs( hwlib::port_out & leds, hwlib::pin_in & button1, hwlib::pin_in & button2){
	char bitsToShift = 5;

	while(true)
	{
		if (!button1.get() && bitsToShift > 0)
		{
			bitsToShift--;
			leds.set( 0x1F << bitsToShift);
			while (!button1.get()){} 
		}
		else if (!button2.get() && bitsToShift < 5)
		{
			bitsToShift++;
			leds.set( 0x1F << bitsToShift);
			while (!button2.get()){}
		}
	}
}

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   auto led1 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto led2 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led4 = hwlib::target::pin_out( hwlib::target::pins::d4 );
   auto led5 = hwlib::target::pin_out( hwlib::target::pins::d3 );
   auto button1 = hwlib::target::pin_in( hwlib::target::pins::d8 );
   auto button2 = hwlib::target::pin_in( hwlib::target::pins::d9 );
   
   auto leds = hwlib::port_out_from_pins( led1, led2, led3, led4, led5 );
   cascadingLEDs( leds , button1, button2);
}