#include <Arduino_FreeRTOS.h>

void TaskBlink( void *pvParameters );
void TaskAnalogRead( void *pvParameters );

int led= 12;

void setup() {
  
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }

  xTaskCreate(
    TaskBlink
    ,  "Blink"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );

  xTaskCreate(
    TaskAnalogRead
    ,  "AnalogRead"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

}

void loop()
{
}


void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;


  pinMode(led, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelay(portTICK_PERIOD_MS ); 
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay(portTICK_PERIOD_MS ); 
  }
}

void TaskAnalogRead(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  
  for (;;)
  {
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}
