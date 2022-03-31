Slave with LED
/*
  I2C Slave Control Demo
  i2c-slave-demo-control.ino
  Demonstrate use of I2C bus
  Receives potentimeter position data
  Controls LED blink rate
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Include Arduino Wire library for I2C
#include <Wire.h>

// Define Slave I2C Address
#define SLAVE_ADDR 9

// Define LED Pin
int LED = 13;

// Variable for received data
int rd;

// Variable for blink rate
int br;

void setup() {

  pinMode(LED, OUTPUT);
  
  // Initialize I2C communications as Slave
  Wire.begin(SLAVE_ADDR);
   
  // Function to run when data received from master
  Wire.onReceive(receiveEvent);
  
  // Setup Serial Monitor 
  Serial.begin(9600);
  Serial.println("I2C Slave Demonstration");
}


void receiveEvent() {
  // read one character from the I2C
  rd = Wire.read();
  // Print value of incoming data
  Serial.println(rd);
    
}
void loop() {
   delay(50);
 
  // Calculate blink value
  br = map(rd, 1, 255, 100, 2000);
 
  digitalWrite(LED, HIGH);
  delay(br);
  digitalWrite(LED, LOW);
  delay(br);

}
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
/*
  I2C Slave Control Demo
  i2c-slave-demo-control.ino
  Demonstrate use of I2C bus
  Receives potentimeter position data
  Controls LED blink rate
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/
 
// Include Arduino Wire library for I2C
#include <Wire.h>
 
// Define Slave I2C Address
#define SLAVE_ADDR 9
int rd;
int br;
 
void setup() {
 
  pinMode(LED, OUTPUT);
  
  // Initialize I2C communications as Slave
  Wire.begin(SLAVE_ADDR);
   
  // Function to run when data received from master
  Wire.onReceive(receiveEvent);
  
  // Setup Serial Monitor 
  Serial.begin(9600);
  Serial.println("I2C Slave Demonstration");
}
 
 
void receiveEvent() {
  // read one character from the I2C
  rd = Wire.read();
  // Print value of incoming data
  Serial.println(rd);
    
}
void loop() { 
}
