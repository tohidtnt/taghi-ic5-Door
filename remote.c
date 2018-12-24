#include "remote.h"




 bool isRemoteClose = false;
 bool isRemoteStop = false;
 bool isRemoteOpen = false ;
 


void remoteInit(void){
	
	REMOTE_CLOSE_DIRECTION_INPUT();
	REMOTE_STOP_DIRECTION_INPUT();
	REMOTE_OPEN_DIRECTION_INPUT();
	

}

void getReadRemote(void){
	
	
	uint8_t remoteCloseDebounce = 1;
	uint8_t remoteStopDebounce = 1 ;
	uint8_t remoteOpenDebounce = 1  ;
	
				if( !(REMOTE_CLOSE() ) ){
				
				for(uint32_t debounceCounter = 0 ; debounceCounter <=500000 ; debounceCounter++){
				
				remoteCloseDebounce *= ( ! (REMOTE_CLOSE() ) );
		  	}
				
			if(remoteCloseDebounce){
				isRemoteClose = true;
			 }
			 else
				isRemoteClose  = false;
	
		 }
	   else
			isRemoteClose  = false; 




  	
	
	
			if( !(REMOTE_STOP() ) ){
				
				for(uint32_t debounceCounter = 0 ; debounceCounter <=500000 ; debounceCounter++){
					remoteStopDebounce *= ( ! (REMOTE_STOP() ) );
				}
				if(remoteStopDebounce){
					isRemoteStop = true;
				}
				else
					isRemoteStop  = false;
			}
				else
	      	isRemoteStop  = false;

	
		
		if( !(REMOTE_OPEN() ) ){
			
			for(uint32_t debounceCounter = 0 ; debounceCounter <=500000 ; debounceCounter++){
				remoteOpenDebounce *= ( ! (REMOTE_OPEN() ) );
			}
			if(remoteOpenDebounce){
				isRemoteOpen = true;
       }
      else
        isRemoteOpen  = false;
    }
			else
			isRemoteOpen  = false;	


}   	