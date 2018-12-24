#include "uart2.h"
#include "stdbool.h"
#ifndef __MODBUS_H
#define __MODBUS_H

void byteToHex(uint8_t byte, uint8_t * dest);
uint8_t hexToByte(uint8_t * dest);

extern uint8_t receivedData[20];
extern uint8_t modbusReceivedDataLen;

uint16_t modbusCrcCalculate(uint8_t *buf, int len);
void modbusInit(void);
bool modbusWriteRegister(uint8_t deviceAddress, uint16_t registerAddress, uint16_t data);
uint16_t modbusReadRegister(uint8_t deviceAddress, uint16_t registerAddress, uint16_t dataLen);
bool modbusWriteBit(uint8_t deviceAddress, uint16_t registerAddress, bool flag);
bool modbusReadBit(uint8_t deviceAddress, uint16_t registerAddress, uint16_t bitLen);
void modbusOnReceivedByte(uint8_t data);
void modbusClearBuffer(void);

#endif
