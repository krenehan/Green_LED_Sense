/*
 * Interrupt.h
 *
 * Created: 8/19/2015 6:19:56 PM
 *  Author: biocrede1
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

void interrupt_init(void);
void LED_matrix_init(void);
void LED_sense_init(void);
void light_on(int i);
void light_off(int i);
void clear_matrix(void);
void write_to_matrix(uint8_t write);

extern volatile unsigned int adc_reading;
extern volatile uint8_t collect;

#endif /* INTERRUPT_H_ */