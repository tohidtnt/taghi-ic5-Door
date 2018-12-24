#include <lpc17xx.h>
#include "sleep.h"
#include "stdbool.h"
#ifndef __UART2_H
#define __UART2_H

#define	UART2_PCLK					24000000UL

#define UART2_RS485_MODE

#ifdef UART2_RS485_MODE
	#define UART2_RS485_PIN_OUT()						LPC_GPIO2->FIODIR|= (1<<6)
	#define UART2_RS485_PIN_ENABLE()				LPC_GPIO2->FIOSET = (1<<6)
	#define UART2_RS485_PIN_DISABLE()				LPC_GPIO2->FIOCLR = (1<<6)
#endif
	
#ifdef __cplusplus
extern "C" {
#endif

typedef void(*Uart2OnReceivedDataCallBack)(uint8_t data);  // ptr to function that give one uint8 Arg

extern Uart2OnReceivedDataCallBack uart2OnReceivedDataCallBack;

void uart2Init(uint32_t baudrate);
void uart2WriteByte(uint8_t byte);
void uart2WriteBuffer(uint8_t * buffer, uint8_t len);
void uart2WriteString(uint8_t * str);
void uart2SetFunctionOnReceivedData(Uart2OnReceivedDataCallBack callback);
void UART2_IRQHandler(void);
	
#ifdef __cplusplus
}
#endif 

#endif
