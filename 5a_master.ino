#include <Wire.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h> 

// Define Slave I2C Address
#define SLAVE_ADDR 9
 
// Analog pin for potentiometer
int analogPin = 0;

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

void setup() {
 
  // Initialize I2C communications as Master
  Wire.begin();
  Serial.begin(9600);
  ss.begin(GPSBaud);
  
}
 
void loop() {
  delay(50);
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      lat = gps.location.lat()
      lng = gps.location.lng()
      Serial.print("Latitude= "); 
      Serial.print(lat, 6);
      Serial.print(" Longitude= "); 
      Serial.println(lng, 6);
      Wire.beginTransmission(SLAVE_ADDR);
      Wire.write(lat, lng);
      Wire.endTransmission();
    }
  }
  
}
