#ifndef _SENSOR_H
#define _SENSOR_H

#include <lpc17xx.h>
#include <stdbool.h>


extern bool isSensorClose;
extern bool isSensorCloseSlower;
extern bool isSensorOpenSlower;
extern bool isSensorOpen;

extern bool isSensorCloseStateZeroTohigh;
extern bool isSensorCloseSlowerStateHighToZero;
extern bool issensorOpenSlowerStateZeroToHigh;
extern bool isSensorOpenStateZeroToHigh;





#define SENSOR_OPEN_DIRECTION_INPUT()             ( 	LPC_GPIO0->FIODIR &= ~(1<<17) 		 )       
#define SENSOR_OPEN()                      			  ( ( LPC_GPIO0->FIOPIN & (1<<17) ) >>17 )

#define SENSOR_OPEN_SLOWER_DIRECTION_INPUT()      ( 	LPC_GPIO0->FIODIR &= ~(1<<15)			 )        
#define SENSOR_OPEN_SLOWER()               			  ( ( LPC_GPIO0->FIOPIN & (1<<15) ) >>15 ) 
#define SENSOR_OPEN_SLOWER_MASK_ENABLE()					(   LPC_GPIO0->FIOMASK |= (1<<15)      )
#define SENSOR_OPEN_SLOWER_MASK_DISABLE()					(   LPC_GPIO0->FIOMASK &= ~(1<<15)     )

#define SENSOR_CLOSE_SLOWER_DIRECTION_INPUT()     (   LPC_GPIO0->FIODIR &= ~(1<<16)      )     
#define SENSOR_CLOSE_SLOWER()              		    ( ( LPC_GPIO0->FIOPIN & (1<<16) ) >>16 )
#define SENSOR_CLOSE_SLOWER_MASK_ENABLE()					(   LPC_GPIO0->FIOMASK |= (1<<16)      )
#define SENSOR_CLOSE_SLOWER_MASK_DISABLE()				(   LPC_GPIO0->FIOMASK &=~(1<<16)      )

#define SENSOR_CLOSE_DIRECTION_INPUT()            (  LPC_GPIO2->FIODIR &= ~(1<<9)        )      
#define SENSOR_CLOSE()                      		  ( ( LPC_GPIO2->FIOPIN & (1<<9) ) >>9   )                    














 void sensorInit(void);
 void getReadSensor(void);



#endif