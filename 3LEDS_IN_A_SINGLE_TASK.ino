#include <Arduino_FreeRTOS.h>


#define  RED 11

#define  GREEN 7

#define  BLUE 8

const uint16_t *Red_led = (uint16_t *)RED;
const uint16_t *Green_led = (uint16_t *)GREEN;
const uint16_t *Blue_led =(uint16_t *)BLUE;



void setup() {
 xTaskCreate(led_control_task,"RED_LED",100,(void *)Red_led,1,NULL);
 xTaskCreate(led_control_task,"GREEN_LED",100,(void *)Green_led,1,NULL);
 xTaskCreate(led_control_task,"BlUe_LED",100,(void *)Blue_led,1,NULL);
 vTaskStartScheduler();

}


void led_control_task(void *pvParameter)
{
  pinMode(RED,"OUTPUT");
  pinMode(GREEN,"OUTPUT");
  pinMode(BLUE,"OUTPUT");
  while(1)
  {
    digitalWrite(pvParameter,digitalRead(pvParameter)^1);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    
    
  }
  
  
}
void loop() {
  // put your main code here, to run repeatedly:

}
