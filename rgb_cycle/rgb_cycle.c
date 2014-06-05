#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "usb_debug_only.h"
#include "print.h"


#define LEDS_OFF (PORTD = 0);
#define LED_A_ON		(PORTD |= (1<<1))
#define LED_A_OFF		(PORTD &= ~(1<<1))

#define LED_B_ON		(PORTD |= (1<<2))
#define LED_B_OFF		(PORTD &= ~(1<<2))

#define LED_C_ON		(PORTD |= (1<<3))
#define LED_C_OFF		(PORTD &= ~(1<<3))

#define LED_CONFIG	(DDRD |= ( (1<<0) | (1<<1) | (1<<2)) )
#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))

int main(void)
{
	// set for 16 MHz clock, and make sure the LED is off
	CPU_PRESCALE(0);
	LED_CONFIG;

  int i = 0;
  while(1) {
    i++;
    PORTD = i % 8;
    _delay_ms(250);
  }
}
