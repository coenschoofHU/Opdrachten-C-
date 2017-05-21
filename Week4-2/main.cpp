/// @file


/// \brief   
/// including library
/// \details
/// Including the hardware library
#include "hwlib.hpp"

/// \brief   
/// Function that takes care of controlling both the LEDs
/// \details
/// This function makes the LEDs increment by pairs, forwards and backwards. 
void kitt( hwlib::port_out & leds, int ms = 300 ){
   for(;;){
      for( unsigned int i = 0; i < leds.number_of_pins() - 2; ++i ){
         leds.set( 0x03 << i );      
         hwlib::wait_ms( ms );
      }
      for( unsigned int i = leds.number_of_pins() - 2; i > 0; --i ){
         leds.set( 0x03 << i );      
         hwlib::wait_ms( ms );
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
   
   auto leds = hwlib::port_out_from_pins( led1, led2, led3, led4, led5 );
   ::kitt( leds );
}