#include "sensor.h"


 bool isSensorClose = false ;
 bool isSensorCloseSlower = false;
 bool isSensorOpenSlower = false ;
 bool isSensorOpen = false ; 
 
 bool isSensorOpenStateZeroToHigh = false ; 
// bool issensorOpenSlowerStateZeroToHigh = false ;
// bool isSensorOpenSlowerStateHighToZero = false ; 
 bool isSensorCloseStateZeroTohigh = false ;


 bool tempSensorOpen = false;	
// bool tempSensorOpenSlower = false ;
// bool tempSensorCloseSlower = false;
 bool tempSensorClose = false ;



void sensorInit(void){
	
	SENSOR_CLOSE_DIRECTION_INPUT() ;
	SENSOR_CLOSE_SLOWER_DIRECTION_INPUT();
	SENSOR_OPEN_SLOWER_DIRECTION_INPUT();
	SENSOR_OPEN_DIRECTION_INPUT();
	
	
}


void getReadSensor(void){
	
	
	   uint16_t sensorOpenDebounce = true;
	   uint16_t sensorOpenSlowerdebounce = true;
	   uint16_t sensorCloseSlowerDebounce = true ;
	   uint16_t sensorCloseDebounce = true ;

	
	
	      	if(  (SENSOR_CLOSE() ) ){
		
						for(uint32_t debounceCounter = 0 ; debounceCounter <=500000 ; debounceCounter++){
    				sensorCloseDebounce *= (  (SENSOR_CLOSE() ) );
						}
						if (sensorCloseDebounce){
								isSensorClose = true;
							if ( !(tempSensorClose) && (isSensorClose) )
								isSensorCloseStateZeroTohigh = true;
							else
							isSensorCloseStateZeroTohigh = false;	
						}
						else
								isSensorClose = false;
      	}
		   else{
				isSensorClose = false;
			  isSensorCloseStateZeroTohigh = false;
			 }
			 
			 
			 
			 				
      	if(  (SENSOR_CLOSE_SLOWER() ) ){
		
						for(uint32_t debounceCounter = 0 ; debounceCounter <=500000 ; debounceCounter++){
    				sensorCloseSlowerDebounce *= (  (SENSOR_CLOSE_SLOWER() ) );
						}
						if (sensorCloseSlowerDebounce){
							
							isSensorCloseSlower = true;
							
//							if( ! (tempSensorOpenSlower) && (sensorCloseSlowerDebounce) )
//							   issensorOpenSlowerStateZeroToHigh = true ;
//							else
//								 issensorOpenSlowerStateZeroToHigh = false;
						}
						else
								isSensorCloseSlower = false;
      	}	
				else{
        		isSensorCloseSlower = false;
//						issensorOpenSlowerStateZeroToHigh = false;
				}


				
      	if(  (SENSOR_OPEN_SLOWER() ) ){
		
						for(uint32_t debounceCounter = 0 ; debounceCounter <=500000 ; debounceCounter++){
    				sensorOpenSlowerdebounce *= (  (SENSOR_OPEN_SLOWER() ) );
						}
						if (sensorOpenSlowerdebounce){
							
							isSensorOpenSlower = true;
							
//							if(   (tempSensorCloseSlower) && !( sensorOpenSlowerdebounce ) )
//								 issensorOpenSlowerStateZeroToHigh = true ; 
//							else
//									issensorOpenSlowerStateZeroToHigh  = false ;
						}
						else
								isSensorOpenSlower = false;
      	}	
				else{
        		isSensorOpenSlower = false;
//						issensorOpenSlowerStateZeroToHigh  = false ;
				}
				
	
	      	if(  (SENSOR_OPEN() ) ){
		
						for(uint32_t debounceCounter = 0 ; debounceCounter <=500000 ; debounceCounter++){
								sensorOpenDebounce *= (  (SENSOR_OPEN() ) );
						}
						if (sensorOpenDebounce){
							
							isSensorOpen = true ;
							
							if(  !(tempSensorOpen) && (isSensorOpen)  )
								
								isSensorOpenStateZeroToHigh = true;
							
							else
								isSensorOpenStateZeroToHigh = false;
							
						}
						else
								isSensorOpen = false;
      	}					
					else{
        			isSensorOpen = false;
				    	isSensorOpenStateZeroToHigh = false;
					}
					
					
		   tempSensorOpen				    = 		  isSensorOpen;
//			 tempSensorOpenSlower 	  =       isSensorOpenSlower ;	
//	     tempSensorCloseSlower    =   		isSensorCloseSlower;
			 tempSensorClose          =   		isSensorClose; 
			
			 
			 
			 
			 
				

	
}