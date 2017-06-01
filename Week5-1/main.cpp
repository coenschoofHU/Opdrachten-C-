/// @file

/// \brief   
/// including library
/// \details
/// Including the hardware library

#include "hwlib.hpp"

/// \brief   
/// Blink function
/// \details
/// Taking care of making the LEDs blink. The function takes a certain pattern (in hexadecimal), waits a certain time
/// and bit-shifts it four places, waits a certain time again and repeats the process.
void blink( hwlib::port_out & leds){
	
  while(1)
  {
      leds.set( 0x0F );
      hwlib::wait_ms( 100 );
  }
  {
      leds.set( 0x0F << 4);
      hwlib::wait_ms( 100 );
  }
}

/// \brief   
/// Main function
/// \details
/// The main function takes care of interfacing the LEDs, the spi_bus,
/// shift clock pulse, stop clock pulse and data.
int main(void){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;
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
   blink( leds1 );
}
