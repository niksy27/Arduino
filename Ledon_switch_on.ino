#include <Arduino_FreeRTOS.h>


void switch_led(void *parm);
const uint8_t led = 8;
const uint8_t push_button = 7;
TaskHandle_t Taskhandle1;
void setup() {
 Serial.begin(9600);
 delay(1000);
 pinMode(led,OUTPUT);
 pinMode(push_button,INPUT);
 digitalWrite(led,LOW);
 xTaskCreate(switch_led,"switch_led",100,NULL,1,&Taskhandle1);
 vTaskStartScheduler();

}

void loop() {
  // put your main code here, to run repeatedly:

}


void switch_led(void *parm)
{
  
 while(1) 
  {
    
    if(digitalRead(push_button)==1)
     {
      digitalWrite(led,HIGH);
     
      while(digitalRead(push_button)==1);
     }
     else
     {
     digitalWrite(led,LOW);
      while(digitalRead(push_button)==0);
   
     }
    
  }
  
}
