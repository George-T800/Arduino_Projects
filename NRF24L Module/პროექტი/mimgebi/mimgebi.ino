#include <SPI.h> //ბიბილიოთეკა SPI პროტოკოლის
#include "RF24.h" //RF მოდულის ბიბლიოთეკა 



RF24 radio(9,10);
const uint64_t RF = 0xE8E8F0F0E1LL;  // RF მოდული 
int msg[1]; 
int data; 
int pos;

//მოძრაობის მიმართულებები 
int fspeed;             
int bspeed;            
int fspeed1;           
int bspeed1;          

// ძრავის მოდულის პინები 
const int in1 = 4;     
const int in2 = 5;    
const int ena = 3;    
const int in3 = 6;    
const int in4 = 7;    
const int enb = 8;    


void setup()
{
  // პინების აღწერა 
  pinMode(in1, OUTPUT);      
  pinMode(in2, OUTPUT);      
  pinMode(ena, OUTPUT);      
  
  pinMode(in3, OUTPUT);      
  pinMode(in4, OUTPUT);      
  pinMode(enb, OUTPUT);      

  
  



delay(50);
radio.begin();
radio.openReadingPipe(1,RF); 
radio.startListening();

}


void stop()
{
  
  analogWrite(ena, 0); 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enb, 0); 
  digitalWrite(in3, LOW);
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




void loop()
{
  if (radio.available())radio.read(msg, 1);
  
  if (msg[0] >=0 && msg[0] <=50)data = msg[0], bspeed = map(data, 50, 0, 230, 0), backward(bspeed);
  if (msg[0] >=76 && msg[0] <=126)data = msg[0], fspeed = map(data, 76, 126, 230, 0), forward(fspeed);
  
  if (msg[0] >51 && msg[0] <75)data = msg[0], stop();
 if (msg[0] >176 && msg[0] <214)data = msg[0], stop();
  
  if (msg[0] >=127 && msg[0] <=175)data = msg[0], bspeed1 = map(data, 175, 127, 230, 0), backward1(bspeed1);
  if (msg[0] >=215 && msg[0] <=255)data = msg[0], fspeed1 = map(data, 255, 215, 230, 0), forward1(fspeed1);
}


