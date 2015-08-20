/*
 * Interrupt.h
 *
 * Created: 8/19/2015 6:19:56 PM
 *  Author: biocrede1
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

void interrupt_init(void);

extern volatile unsigned int adc_reading;
extern volatile uint8_t collect;

#endif /* INTERRUPT_H_ */