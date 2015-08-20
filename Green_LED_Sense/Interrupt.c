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

void LED_matrix_init(void) //red LEDs
{
	DDRB |= (1<<DDB1) | (1<<DDB2) | (1<<DDB3) | (1<<DDB4);
}

void LED_sense_init(void) //green LEDs
{
	DDRB |= (1<<DDB0);
	DDRD |= (1<<DDD5) | (1<<DDD6) | (1<<DDD7);
}

void light_on(int light_number) //Turn on green LEDs
{
	if (light_number == 0)
	{
		PORTB |= (1<<PORTB0);
		_delay_ms(light_delay_time);
	}
	else
	{
		PORTD |= (1<<(8-light_number)); //if i = 1 (0b10000000), if i = 2 (0b01000000), etc.
		_delay_ms(light_delay_time);
	}
}

void light_off(int light_number) //Turn on green LEDs
{
	if (light_number == 0)
	{
		PORTB &= ~(1<<PORTB0);
	}
	else
	{
		PORTD &= ~(1<<(8-light_number)); //if i = 1 (0b10000000), if i = 2 (0b01000000), etc.
	}
}

void clear_matrix(void)
{
	PORTB &= ~(1<<PORTB1) | ~(1<<PORTB2) | ~(1<<PORTB3) | (1<<PORTB4);
}

void write_to_matrix(uint8_t write)
{
	PORTB |= (collect<<1); //Bit shift left by 1 to adjust for 1 pin offset between B and C pins
}

//Interrupt from pin 4
ISR(INT0_vect)
{
	if (PIND & (1<<PIND2)) //If INT0 pin is high
	{
		collect = 0x00;
		for (int i = 0; i < 4; i++)
		{
			light_on(i);
			adc_reading = ADC_get(i);
			convert(adc_reading);
			if (Vin < 2.5) //Light is not reaching sensor, SNAP still in tube
			{
				collect += (1<<i); //Bit shift over to collect value
			}
			light_off(i);
		}
		write_to_matrix(collect);
	}
}
