/*
 * Green_LED_sense_irq.c
 *
 * Created: 8/18/2015 11:41:33 AM
 *  Author: biocrede1
 */ 

#include <avr/io.h>
#include "Green_LED_sense_irq.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>


extern volatile unsigned int adc_reading;
extern volatile uint8_t collect;
extern volatile float Vin;