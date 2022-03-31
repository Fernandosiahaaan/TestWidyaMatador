 #include <SoftwareSerial.h>

SoftwareSerial serial(11, 12);

void setup()
{
  serial.begin(9600);  
  Serial.begin(9600);
  delay(100);
}


void loop()
{
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 'kirim':
     serial.println("AT+CMGF=1"); 
     delay(1000);  
     serial.println("nomor=\"+62xxxxxxxxxx\"\r"); 
     delay(1000);
     serial.println("Halo :)");
     delay(100);
     serial.println((char)26);
      delay(1000);
      break;

    case 'r':
      serial.println("AT+CNMI=2,2,0,0,0"); 
      delay(1000);
      break;
  }

 if (serial.available()>0)
   Serial.write(serial.read());
}
