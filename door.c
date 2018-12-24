#include "door.h"



void doorInit(void){
	
	sensorInit();
	remoteInit();
	buttonInit();
	coupleInit();
	ic5Init();

}

void doorOpen(void){
	
	ic5Start(1);
	
}

void doorStop(void){
	
	ic5Stop();
	
}


void doorClose(void){
	
  ic5Start(0);	

}