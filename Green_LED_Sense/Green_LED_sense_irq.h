/*
 * Green_LED_sense_irq.h
 *
 * Created: 8/18/2015 11:40:11 AM
 *  Author: biocrede1
 */ 


#ifndef GREEN_LED_SENSE_IRQ_H_
#define GREEN_LED_SENSE_IRQ_H_


//Defines
#define F_CPU 1000000
#define motor_movement_time 10000
#define light_ddr DDRD
#define light_ddr_spec DDD7
#define light_port PORTD
#define light_port_spec PORTD7
#define light_on light_port |= (1<<light_port_spec)
#define light_off light_port &= ~(1<<light_port_spec)



#endif /* GREEN_LED_SENSE_IRQ_H_ */