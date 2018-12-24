#include "button.h"

 bool isButtonOpen = false;
 bool isButtonStop = false;
 bool isButtonClose = false;

void buttonInit(){
	
	
	BUTTON_CLOSE_DIRECTION_INPUT();
	BUTTON_STOP_DIRECTION_INPUT();
	BUTTON_OPEN_DIRECTION_INPUT();

}

void getReadButton(){
	
	uint16_t buttonOpenDebounce = 1 ;
	uint16_t buttonStopDebounce = 1 ;
	uint16_t buttonCloseDebounce = 1;
	
				if( ! (BUTTON_OPEN() ) ){
		
    		for(uint32_t debounceCounter = 0 ; debounceCounter <=500000 ; debounceCounter++){
    				buttonOpenDebounce *= ( ! (BUTTON_OPEN() ) );
    			}
    		if (buttonOpenDebounce){
    			isButtonOpen = true;
    		}
    		else
    			isButtonOpen = false;	
    	}
		else			
			isButtonOpen = false;
	
		
		
		
				if( !(BUTTON_STOP() ) ){
				
				for(uint32_t debounceCounter = 0 ; debounceCounter <=500000 ; debounceCounter++){
						buttonStopDebounce *= ( ! (BUTTON_STOP() ) );
				}
				if(buttonStopDebounce){
					isButtonStop = true;
				}
				else
					isButtonStop = false;
			 }
			else
	    	isButtonStop = false;	
		
		
		
	

		if( !(BUTTON_CLOSE() ) ){
			
				for(uint32_t debounceCounter = 0 ; debounceCounter <=500000 ; debounceCounter++){
						buttonCloseDebounce *= ( ! (BUTTON_CLOSE() ) );
				}
				if(buttonCloseDebounce){
					isButtonClose = true;
				}
				else
					isButtonClose = false;
			}
	else
		isButtonClose = false;	
	
	

				

			
			
			
			
			


} 	


