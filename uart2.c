#include "uart2.h"

Uart2OnReceivedDataCallBack uart2OnReceivedDataCallBack;

void uart2Init(uint32_t baudrate)
{
	uint32_t Fdiv;
	
#ifdef UART2_RS485_MODE
	UART2_RS485_PIN_OUT();
#endif
	
	LPC_PINCON->PINSEL0 |= 1<<20;
	LPC_PINCON->PINSEL0 |= 1<<22;
	LPC_SC->PCONP |= 1<<24;
	LPC_UART2->LCR = 0x83;        /* 7 bits, even Parity, 1 Stop bit */
	Fdiv = ( UART2_PCLK / (16  * baudrate) );  
	LPC_UART2->DLM = Fdiv / 256;
	LPC_UART2->DLL = Fdiv % 256;
	LPC_UART2->LCR = 0x03;
	LPC_UART2->FCR = 0x07;
	
	NVIC_EnableIRQ(UART2_IRQn);
	
	LPC_UART2->IER = 1<<0;
	
	sleep(100);
}

void uart2WriteByte(uint8_t byte)
{
#ifdef UART2_RS485_MODE
	sleep(50);
	UART2_RS485_PIN_ENABLE();
#endif
	while (!(LPC_UART2->LSR & 0x20));
	LPC_UART2->THR = byte;
	
	#ifdef UART2_RS485_MODE
	sleep(50);
	UART2_RS485_PIN_DISABLE();
	#endif
}

void uart2WriteBuffer(uint8_t * buffer, uint8_t len)
{
#ifdef UART2_RS485_MODE
	sleep(10);
	UART2_RS485_PIN_ENABLE();
	sleep(10);
#endif
	while(len--)
	{
		while (!(LPC_UART2->LSR & 0x20));
		LPC_UART2->THR = *buffer++;
	}
	
#ifdef UART2_RS485_MODE
	sleep(10);
	UART2_RS485_PIN_DISABLE();
	sleep(10);
#endif
}

void uart2WriteString(uint8_t * str)
{
#ifdef UART2_RS485_MODE
	UART2_RS485_PIN_ENABLE();
	sleep(50);
#endif
	while(*str)
	{
		while (!(LPC_UART2->LSR & 0x20));
		LPC_UART2->THR = *str++;
	}
	#ifdef UART2_RS485_MODE
	sleep(50);
	UART2_RS485_PIN_DISABLE();
#endif
}

void uart2SetFunctionOnReceivedData(Uart2OnReceivedDataCallBack callback)
{
	uart2OnReceivedDataCallBack = callback;
}

void UART2_IRQHandler(void)
{
	uint8_t data = LPC_UART2->RBR;
	if(uart2OnReceivedDataCallBack)
		uart2OnReceivedDataCallBack(data);
}
