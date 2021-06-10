#include <Arduino_FreeRTOS.h>

const int led =8;
const int push_button =7;

void red_led(void * parm);
void serial_print(void *param);
void push_but_read(void *param) ;
TaskHandle_t taskhandle1;
TaskHandle_t taskhandle2;
TaskHandle_t taskhandle3;
void setup() {
  Serial.begin(9600);
  xTaskCreate(red_led,"red_led",100,NULL,2,&taskhandle1);
  xTaskCreate(serial_print,"serial_print",100,NULL,1,&taskhandle2);
  xTaskCreate(push_but_read,"push_but_read",100,NULL,1,&taskhandle3);
  vTaskStartScheduler();
  pinMode(led,OUTPUT);
  pinMode(push_button,INPUT_PULLUP);
  digitalWrite(led,0);
  delay(5000);

}

void loop() {



}


void red_led(void * parm)
{

  while(2)
  {
     digitalWrite(led,1);
     vTaskDelay(1000/portTICK_PERIOD_MS);
     digitalWrite(led,0);
     vTaskDelay(1000/portTICK_PERIOD_MS);

  }
 }

void serial_print(void *param) 
{
  while(2)
  {
  Serial.println("Hellow\n");
  vTaskDelay(3000/portTICK_PERIOD_MS);
  }
}


void push_but_read(void *param) 
{
  while(2)
  {
  Serial.println(digitalRead(push_button));
   Serial.println("\n");
  vTaskDelay(2000/portTICK_PERIOD_MS);
  }
}

