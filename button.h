#include <LPC17xx.h>
#include  <stdbool.h>
#ifndef _BUTTON_H
#define _BUTTON_H

extern bool isButtonOpen;
extern bool isButtonStop;
extern bool isButtonClose;




#define BUTTON_OPEN_DIRECTION_INPUT()      		 ( LPC_GPIO3->FIODIR &= ~(1<<26) )
#define BUTTON_OPEN()                      		 ( ( LPC_GPIO3->FIOPIN & (1<<26) ) >>26 )
																				   
#define BUTTON_STOP_DIRECTION_INPUT()			 	   ( LPC_GPIO1->FIODIR &= ~(1<<10) )
#define BUTTON_STOP()                          ( ( LPC_GPIO1->FIOPIN & (1<<10) ) >>10 )
																				   
																				   
#define BUTTON_CLOSE_DIRECTION_INPUT()		  	 ( LPC_GPIO1->FIODIR &= ~(1<<17) )
#define BUTTON_CLOSE()                         ( ( LPC_GPIO1->FIOPIN & (1<<17) ) >>17 )
																				   



void buttonInit();
void getReadButton();



#endif