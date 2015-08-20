/*
 * ADC.h
 *
 * Created: 8/19/2015 6:15:57 PM
 *  Author: biocrede1
 */ 


#ifndef ADC_H_
#define ADC_H_


extern volatile float Vin;

void convert(unsigned int x);
void ADC_init(void);
unsigned int ADC_get(int pin);


#endif /* ADC_H_ */