
//#include <Servo.h>
#include <SPI.h>
#include "RF24.h"
/*Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
*/
RF24 radio(40,42);
const uint64_t pipe = 0xF0F0F0F000LL; 
int msg[3]; 
int data; 
int data1;
int pos;
int fspeed;           // forward speed 
int bspeed;           // backward speed
int fspeed1;           // forward1 speed 
int bspeed1;           // backward1 speed
const int in1 = 14;    // direction pin 14
const int in2 = 15;    // direction pin 15
const int ena = 4;    // PWM pin to change speed

const int in3 = 6;    // direction pin 6
const int in4 = 5;    // direction pin 5
const int enb = 7;    // PWM pin to change speed

void setup()
{
  
  pinMode(in1, OUTPUT);      // connection to L298n
  pinMode(in2, OUTPUT);      // connection to L298n
  pinMode(ena, OUTPUT);      // connection to L298n
  
  pinMode(in3, OUTPUT);      // connection to L298n
  pinMode(in4, OUTPUT);      // connection to L298n
  pinMode(enb, OUTPUT);      // connection to L298n
/*  
servo1.attach(8); 
servo2.attach(9); 
servo3.attach(10); 
servo4.attach(11); 
servo5.attach(12); 
servo6.attach(13); 
delay(50);
*/
radio.begin();
radio.openReadingPipe(1,pipe); 
radio.startListening();
}

void loop()
{
  if (radio.available())radio.read(msg, 1); 
      

 /* 
  if (msg[0] <21 && msg[0] >-1)data = msg[0], pos = map(data, 0, 21, 10, 170),servo1.write(pos);
  if (msg[0] <43 && msg[0] >22)data = msg[0], pos = map(data, 22, 43, 10, 170),servo2.write(pos);
  if (msg[0] <65 && msg[0] >44)data = msg[0], pos = map(data, 44, 65, 10, 170),servo3.write(pos);
  if (msg[0] <87 && msg[0] >66)data = msg[0], pos = map(data, 66, 87, 10, 170),servo4.write(pos);
  if (msg[0] <109 && msg[0] >88)data = msg[0], pos = map(data, 88, 109, 10, 170),servo5.write(pos);
  if (msg[0] <127 && msg[0] >110)data = msg[0], pos = map(data, 110, 127, 10, 170),servo6.write(pos);

*/
  
  if (msg[0] >=128 && msg[0] <=156)data = msg[0], bspeed = map(data, 192, 164, -255, 255), backward(bspeed);
  if (msg[0] >=164 && msg[0] <=192)data = msg[0], fspeed = map(data, 156, 128, -255, 255), forward(fspeed);
 //if (msg[0] >157 && msg[0] <163)data = msg[0], stop();

 if (msg[0] >=193 && msg[0] <=221)data1 = msg[0], bspeed1 = map(data1, 255, 227, -255, 255), backward1(bspeed1);
if (msg[0] >=227 && msg[0] <=255)data1 = msg[0], fspeed1 = map(data1, 193, 221, -255, 255), forward1(fspeed1);
  //if (msg[0] >222 && msg[0] <226)data1 = msg[0], stop();
  

}

void stop()
{
  
  analogWrite(ena, 40); // если робот движеться, после остановки, то необходимо уменьшить число, например на 20.
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enb, 40); // если робот движеться, после остановки, то необходимо уменьшить число, например на 20.
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
}

void forward(int fspeed)
{
  
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, bspeed);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, bspeed);
}

void backward(int bspeed)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, fspeed);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, fspeed);
 
}


void forward1(int fspeed1)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, fspeed1);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, fspeed1);
}

void backward1(int bspeed1)
{
    
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, bspeed1);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, bspeed1);
}



