#include "modbus.h"


uint8_t receivedData[20] = "";
uint8_t modbusReceivedDataLen = 0;

uint16_t modbusCrcCalculate(uint8_t *buf, int len)
{  
  uint16_t crc = 0xFFFF;
	uint8_t pos, i;
  for (pos = 0; pos < len; pos++)
  {
		crc ^= (uint16_t)buf[pos];

		for (i = 8; i != 0; i--) {
			if ((crc & 0x0001) != 0) {
				crc >>= 1;
				crc ^= 0xA001;
			}
			else
				crc >>= 1;
    }
  }

  return crc;
}

void modbusInit(void)
{
	static bool isInited = false;
	
	if(!isInited)
	{
		uart2Init(9230);
		uart2SetFunctionOnReceivedData(modbusOnReceivedByte);
	}
}

bool modbusWriteRegister(uint8_t deviceAddress, uint16_t registerAddress, uint16_t data)
{
	uint8_t result[8];
	uint8_t i = 0;
	uint16_t lrc;
	
	result[0] = deviceAddress;
	result[1] = 0x06;
	result[2] = registerAddress >> 8;
	result[3] = registerAddress & 0xFF;
	result[4] = data >> 8;
	result[5] = data & 0xFF;
	
	lrc = modbusCrcCalculate(result, 6);
	
	result[7] = lrc >> 8;
	result[6] = lrc & 0xFF;
	
	modbusReceivedDataLen = 0;
	uart2WriteBuffer(result, 8);

	long timedOut = 3000000;
	
	while(modbusReceivedDataLen != 8 && --timedOut)
	
	while(result[i])
	{
		if(result[i] != receivedData[i])
			return 0;
		
		i++;
	}
	
	modbusClearBuffer();
	
	
	return 1;
}

uint16_t modbusReadRegister(uint8_t deviceAddress, uint16_t registerAddress, uint16_t dataLen)
{
	uint8_t result[8];
	uint16_t lrc;
	uint16_t gotValue;
	
	result[0] = deviceAddress;
	result[1] = 0x03;
	result[2] = registerAddress >> 8;    // extract high byte
	result[3] = registerAddress & 0xFF;  // extract low byte
	result[4] = dataLen >> 8;						 // extract high byte
	result[5] = dataLen & 0xFF;          // extract low byte
	
	lrc = modbusCrcCalculate(result, 6);
	
	result[7] = lrc >> 8;									//extract high byte
	result[6] = lrc & 0xFF;               // extract low byte
	
	modbusReceivedDataLen = 0;
	uart2WriteBuffer(result, 8);
	
	long timedOut = 3000000;
	
	while((modbusReceivedDataLen != 5 + (dataLen * 2)) && --timedOut);
	
	gotValue = (receivedData[3] << 8) | receivedData[4];
	
	modbusClearBuffer();
	
	

	return gotValue;
}

bool modbusWriteBit(uint8_t deviceAddress, uint16_t registerAddress, bool flag)
{
	uint8_t result[8];
	uint8_t i = 0;
	uint16_t lrc;
	
	result[0] = deviceAddress;
	result[1] = 0x05;
	result[2] = registerAddress >> 8;
	result[3] = registerAddress & 0xFF;
	result[4] = (flag ? 0xFF : 0x00);
	result[5] = 0x00;
	
	lrc = modbusCrcCalculate(result, 6);
	
	result[7] = lrc >> 8;
	result[6] = lrc & 0xFF;
	
	modbusReceivedDataLen = 0;
	uart2WriteBuffer(result, 8);
	
	while(modbusReceivedDataLen != 8);
	
	while(result[i])
	{
		if(result[i] != receivedData[i])
			return 0;
		
		i++;
	}
	
	modbusClearBuffer();
	
	return 1;
}

bool modbusReadBit(uint8_t deviceAddress, uint16_t registerAddress, uint16_t bitLen)
{
	uint8_t result[8];
	uint16_t lrc;
	bool gotValue;
	
	result[0] = deviceAddress;
	result[1] = 0x02;
	result[2] = registerAddress >> 8;
	result[3] = registerAddress & 0xFF;
	result[4] = bitLen >> 8;
	result[5] = bitLen & 0xFF;
	
	lrc = modbusCrcCalculate(result, 6);
	
	result[7] = lrc >> 8;
	result[6] = lrc & 0xFF;
	
	modbusReceivedDataLen = 0;
	uart2WriteBuffer(result, 8);
	
	while(modbusReceivedDataLen != 6);
	
	gotValue = receivedData[3];
	
	modbusClearBuffer();

	return gotValue;
}
     
void modbusOnReceivedByte(uint8_t data)
{
	if(modbusReceivedDataLen == 0 && !data)
		return;
	
	receivedData[modbusReceivedDataLen++] = data;

	if(modbusReceivedDataLen >= 20)
		modbusReceivedDataLen = 0;
}

void modbusClearBuffer(void)
{
	modbusReceivedDataLen = 0;
	
	uint8_t i = 20;
	while(i--)
		receivedData[i] = 0;
}
