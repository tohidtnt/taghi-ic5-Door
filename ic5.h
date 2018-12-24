#include <lpc17xx.h>
#include "modbus.h"

#ifndef _IC5_H
#define _IC5_H


#define IC5_DEVICE_ADDR				1

void ic5Init(void);
void ic5Start(bool direction);
void ic5Stop();
void ic5SetFrequency(uint8_t freq);
uint8_t ic5GetFrequecy(void);
bool ic5IsStarted(void);
bool ic5IsStoped (void);




#endif