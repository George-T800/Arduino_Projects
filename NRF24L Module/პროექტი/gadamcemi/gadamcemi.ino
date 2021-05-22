#include <Wire.h>
#include <SPI.h>
#include "RF24.h" 

RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL; 
int msg[1]; 
int val_1; 
int val_2; 

const int MPU_addr=0x68;   
int16_t AcX,AcY;

void setup()
{

  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  
  Wire.write(0);     
  Wire.endTransmission(true);
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(pipe); 
}

void loop()
{
  
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true); 
  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  
val_1 = map(AcX, -17000, 17000, 0, 127),msg[0] = val_1,radio.write(msg, 1);
val_2 = map(AcY, -17000, 17000, 128, 256),msg[0] = val_2,radio.write(msg, 1);
}
