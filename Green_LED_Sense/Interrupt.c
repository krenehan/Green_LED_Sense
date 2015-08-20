/*
 * Interrupt.c
 *
 * Created: 8/19/2015 6:07:34 PM
 *  Author: biocrede1
 */ 

#include "Green_LED_sense_irq.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "ADC.h"
#include "Interrupt.h"

volatile uint8_t collect;
volatile unsigned int adc_reading;


//Enabling interrupts
void interrupt_init(void)
{
	sei();
	EIMSK |= (1<<INT0); //External interrupt 0 is enabled
	EICRA |= (1<<ISC00); //Logic change triggers interrupt
	
}

//Interrupt from pin 4
ISR(INT0_vect)
{
	if (PIND & (1<<PIND2)) //If INT0 pin is high
	{
		collect = 0;
		light_on;
		_delay_ms(motor_movement_time);
		for (int i = 0; i < 1; i++)
		{
			adc_reading = ADC_get(i);
			convert(adc_reading);
			if (Vin > 2.5) //Light is not reaching sensor, SNAP still in tube
			{
				collect += (1<<i); //Bit shift over to collect value
			}
		}
		light_off;
		if (collect > 0)
		{
			PORTB |= (1<<PORTB0);
		}
	}
	else {PORTB &= ~(1<<PORTB0);}
}
