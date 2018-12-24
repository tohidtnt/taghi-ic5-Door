#include "ic5.h"


void ic5Init(void)
{
	modbusInit();
}

void ic5Start(bool direction)
{
	modbusWriteRegister(IC5_DEVICE_ADDR, 0x05, direction ? 2 : 4);
}

void ic5Stop()
{
	modbusWriteRegister(IC5_DEVICE_ADDR, 0x05, 1);
}

void ic5SetFrequency(uint8_t freq)
{
	modbusWriteRegister(IC5_DEVICE_ADDR, 0x04, freq * 100);
}

uint8_t ic5GetFrequecy(void)
{
	uint16_t result = modbusReadRegister(IC5_DEVICE_ADDR, 0x04, 1);
	return result / 100;
}

bool ic5IsStarted(void)
{
	uint16_t result = modbusReadRegister(IC5_DEVICE_ADDR, 0x05, 1) & 0x0F;
	return result == 2 || result == 4;
}

uint16_t ic5GetCurrent (void){
	
	uint16_t result = modbusReadRegister(IC5_DEVICE_ADDR , 0x08 , 1) ;
  return result;	
}	

bool ic5IsStoped (void){
	
		bool result = modbusReadRegister(IC5_DEVICE_ADDR, 0x0D, 1) & 0x01;
	return result;
	
}
