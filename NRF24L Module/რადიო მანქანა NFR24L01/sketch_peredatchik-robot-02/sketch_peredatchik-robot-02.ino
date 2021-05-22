#include <SPI.h>
#include "RF24.h" 
RF24 radio(9,10);
const uint64_t pipe = 0xF0F0F0F000LL; 
int msg[3]; 
int potpin_1 = A0; 
int val_1; 
int potpin_2 = A6; 
int val_2; 
int potpin_3 = A7; 
int val_3; 
int potpin_4 = A1; 
int val_4; 
int potpin_5 = A2; 
int val_5; 
int potpin_6 = A3; 
int val_6; 
int potpin_7 = A4; 
int val_7; 
int potpin_8 = A5; 
int val_8; 


void setup(void){
radio.begin();
radio.openWritingPipe(pipe); 

}
void loop() {
val_1 = analogRead(potpin_1),val_1 = map(val_1, 0, 1023, 0, 21),msg[0] = val_1,radio.write(msg, 1);
val_4 = analogRead(potpin_4),val_4 = map(val_4, 0, 1023, 22, 43),msg[0] = val_4,radio.write(msg, 1);
val_5 = analogRead(potpin_5),val_5 = map(val_5, 0, 1023, 44, 65),msg[0] = val_5,radio.write(msg, 1);
val_6 = analogRead(potpin_6),val_6 = map(val_6, 0, 1023, 66, 87),msg[0] = val_6,radio.write(msg, 1);
val_7 = analogRead(potpin_7),val_7 = map(val_7, 0, 1023, 88, 109),msg[0] = val_7,radio.write(msg, 1);
val_8 = analogRead(potpin_8),val_8 = map(val_8, 0, 1023, 110, 127),msg[0] = val_8,radio.write(msg, 1);

val_2 = analogRead(potpin_2),val_2 = map(val_2, 0, 1023, 128, 192),msg[0] = val_2,radio.write(msg, 1);
val_3 = analogRead(potpin_3),val_3 = map(val_3, 0, 1023, 193, 255),msg[0] = val_3,radio.write(msg, 1);

  
}

