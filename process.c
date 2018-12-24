#include "process.h"




void startProcess(void){
	
			 doorInit();
    while(1){	
			getReadSensor();
     	getReadButton();
      getReadRemote();
			
    	
    	if( (isRemoteClose || isButtonClose) && !(isSensorClose) ) {
    		

				coupleEnable();
				sleep(COUPLE_WAIT);
				SENSOR_OPEN_SLOWER_MASK_ENABLE();
				SENSOR_CLOSE_SLOWER_MASK_DISABLE();
				sleep(100);
			  ic5SetFrequency(20);
			 	sleep(100);
    	 	doorClose();
				sleep(100);
    	}
	   		
			
			if(isSensorCloseSlower || isSensorOpenSlower){
				sleep(100);
				ic5SetFrequency(5);
				sleep(100);
			}
			

    	if( isRemoteStop || isButtonStop  ){
				
				bool motorStoped=0;
				sleep(100);
    		doorStop();
    		sleep(100);
				do{
					sleep(100);
					 motorStoped = ic5IsStoped();
				}while(!motorStoped);
				sleep(COUPLE_WAIT);
				coupleDisable();
    	}
			
    	if(  (isRemoteOpen || isButtonOpen) && !(isSensorOpen) ){
				
				coupleEnable();
				sleep(COUPLE_WAIT);
				SENSOR_OPEN_SLOWER_MASK_DISABLE();
				SENSOR_CLOSE_SLOWER_MASK_ENABLE();
				sleep(100);
        ic5SetFrequency(20);
    		sleep(100);
    		doorOpen();
    	  sleep(100);
    	}
			
			if ( isSensorOpenStateZeroToHigh || isSensorCloseStateZeroTohigh ){
				sleep(100);
				doorStop();
				sleep(100);
				bool motorStoped=0;
				do{
					 sleep(100);
					 motorStoped = ic5IsStoped();
				}while(!motorStoped);
				sleep(COUPLE_WAIT);
				coupleDisable();
			}
			
 	}    	
}