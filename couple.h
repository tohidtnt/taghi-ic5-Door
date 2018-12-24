#ifndef _COUPLE_H
#define _COUPLE_H


#include <lpc17xx.h>
#include <stdbool.h>


#define COUPLE_DIRECTION_OUTPUT()     ( LPC_GPIO0->FIODIR |= (1<<0) )
#define COUPLE_ENABLE()								( LPC_GPIO0->FIOSET |= (1<<0) )
#define COUPLE_DISABLE()							( LPC_GPIO0->FIOCLR |= (1<<0) )

#define COUPLE_WAIT													300 

void coupleInit( void );
void coupleEnable (void);
void coupleDisable (void );




#endif
