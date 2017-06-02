/// @file

/// \brief   
/// including library
/// \details
/// Including the hardware library

#include "hwlib.hpp"

/// \brief
/// Function that utilizes two buttons to enable or disable LEDs
/// \details
/// Using the pattern 0xFF, 8 LEDs and the two buttons we are able to bit shift i amount of times to a 
/// certain direction. The code is also made to be 'hufter-proof'.


void buttons( hwlib::port_out & leds, hwlib::pin_in & button1, hwlib::pin_in & button2){
  char i = 7;

  while(1)
  {
    if (!button1.get() && i > 0)
    {
      i--;
      leds.set( 0xFF << i);
      hwlib::wait_ms( 100 );
    }
    else if (!button2.get() && i <= 7)
    {
      i++;
      leds.set( 0xFF << i);
      hwlib::wait_ms( 100 );
    }
  }
}

/// \brief
/// Main function
/// \details
/// Initializes the buttons, LEDs, shift clock pulse, stop clock pulse, et cetera.

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;
   auto button0 = hwlib::target::pin_in( hwlib::target::pins::d2 );
   auto button1 = hwlib::target::pin_in( hwlib::target::pins::d3 );
   auto led0     = target::pin_out( target::pins::d4 );
   auto led1     = target::pin_out( target::pins::d5 );
   auto led2     = target::pin_out( target::pins::d6 );
   auto led3     = target::pin_out( target::pins::d7 );
   auto ds       = target::pin_out( target::pins::d8 );
   auto shcp     = target::pin_out( target::pins::d9 );
   auto stcp     = target::pin_out( target::pins::d10 );
   
   auto spi_bus  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
      stcp, 
      ds, 
      hwlib::pin_in_dummy 
   );
   auto leds = hwlib::hc595( spi_bus, shcp);
   auto leds1 = hwlib::port_out_from_pins( leds.p0, leds.p1, leds.p2, leds.p3, led0, led1, led2, led3 );
   buttons( leds1, button0, button1);
}