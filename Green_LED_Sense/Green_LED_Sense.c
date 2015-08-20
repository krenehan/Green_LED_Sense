/*
 * Green_LED_Sense.c
 *
 * Created: 8/11/2015 5:46:26 PM
 *  Author: biocrede1
 */ 

#include "Green_LED_sense_irq.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include "ADC.h"
#include "Interrupt.h"

int main(void)
{
	//Interrupt enabling
	interrupt_init();
	
	//ADC enabling
	ADC_init();
	
	//LED control
	light_ddr |= (1<<light_ddr_spec);
	
	//Power Control
	PRR |= (1<<PRTIM0) | (1<<PRTIM1) | (1<<PRTIM2) | (1<<PRTWI) | (1<<PRUSART0) | (1<<PRSPI);
	
	DDRB |= (1<<DDB0);
	
    while(1)
    {
		 set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    }
}