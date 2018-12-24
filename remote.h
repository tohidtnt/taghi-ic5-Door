#include  <LPC17xx.h>
#include  <stdbool.h>

#ifndef _REMOTE_H
#define _REMOTE_H


extern bool isRemoteOpen ;
extern bool isRemoteStop;
extern bool isRemoteClose;



#define REMOTE_OPEN_DIRECTION_INPUT()             ( LPC_GPIO1->FIODIR &= ~(1<<18) )
#define REMOTE_OPEN()                             ( ( LPC_GPIO1->FIOPIN & (1<<18) ) >>18 )

#define REMOTE_STOP_DIRECTION_INPUT()							( LPC_GPIO0->FIODIR &= ~(1<<30) )
#define REMOTE_STOP()                             ( ( LPC_GPIO0->FIOPIN & (1<<30) ) >>30 )


#define REMOTE_CLOSE_DIRECTION_INPUT()					  ( LPC_GPIO0->FIODIR &= ~(1<<29) )
#define REMOTE_CLOSE()                            ( ( LPC_GPIO0->FIOPIN & (1<<29) ) >>29 )


void remoteInit(void);
void getReadRemote(void);




#endif
