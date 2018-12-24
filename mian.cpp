#include "process.h"





int main () {
	
	
	uart2Init(9600);
	
	while(1){
	uart2WriteByte(0xFF);
	for(int i =0 ; i<=300000 ; i++);
	}
	
  //startProcess();

	
}