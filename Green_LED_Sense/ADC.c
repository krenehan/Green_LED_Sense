/*
 * ADC.c
 *
 * Created: 8/19/2015 5:59:59 PM
 *  Author: biocrede1
 */ 

#include <avr/io.h>
#include "Interrupt.h"
#include "ADC.h"

volatile float Vin;

//Converting ADC reading
void convert(unsigned int x)
{
	Vin = x*5.00/1024.00;
}


//Initialize ADC
void ADC_init(void)
{
	ADCSRA |= (1<<ADPS1) | (1<<ADPS0); //Prescaler 8 for 125kHz input clock
	ADMUX |= (1<<REFS0); //AVcc reference -- Remember to add capacitor to ground on ARef pin
	ADCSRA |= (1<<ADEN); //Enable ADC
}


//Retrieve value from ADC registers
unsigned int ADC_get(int pin)
{
	ADMUX &= ~(1<<MUX0) & ~(1<<MUX1) & ~(1<<MUX2) & ~(1<<MUX3); //Clear previous pin
	ADMUX |= (pin<<MUX0);
	ADCSRA |= (1<<ADSC); //Start conversion
	while (!(ADCSRA & (1<<ADIF))) {} //Wait for ADIF bit to be set indicating a complete conversion
	return ADC;
}

