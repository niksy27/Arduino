#include <Arduino_FreeRTOS.h>

const uint8_t green_led = 8;
const uint8_t blue_led = 11;
uint8_t count =0;
void green_led_fn(void*parm);
void blue_led_fn(void*parm);


TaskHandle_t Taskhandle1;
TaskHandle_t Taskhandle2;
void setup() {
 Serial.begin(9600);

 pinMode(green_led,OUTPUT);
 pinMode(blue_led,OUTPUT);

 digitalWrite(green_led,LOW);
 digitalWrite(blue_led,LOW);
 xTaskCreate(green_led_fn,"green_led_fn",100,NULL,1,&Taskhandle1);
 xTaskCreate(blue_led_fn,"blue_led_fn",100,NULL,2,&Taskhandle2);
 vTaskStartScheduler();
 delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void green_led_fn(void*parm)
{
   
   while(1)
   {
   

    if(count == 20)
    {     
       vTaskResume(Taskhandle2);
    
            
    }
    count++;
    digitalWrite(green_led,HIGH);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    digitalWrite(green_led,LOW);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    
  }
  
}


void blue_led_fn(void*parm)
{
   
   while(1)
   {
   

    if(count == 10)
    {     
       vTaskSuspend(Taskhandle2);
            
    }
   
    digitalWrite(blue_led,HIGH);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    digitalWrite(blue_led,LOW);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    Serial.print(count);
    Serial.print("\n");
    
  }
  
}
