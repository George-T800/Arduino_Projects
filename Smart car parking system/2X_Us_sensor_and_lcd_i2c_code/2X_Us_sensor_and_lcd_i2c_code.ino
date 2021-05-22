//LCD I2C Display library

#include <LiquidCrystal_I2C.h>

//LCD display pins on arduino 

LiquidCrystal_I2C lcd(0x27,16,2);  

 //description of the variable | Us Sensor -_-_- Front Side | 

#define US_1_echoPin 11 
#define US_1_trigPin 10 

 //description of the variable | Us Sensor -_-_- Back Side | 

#define US_2_echoPin 13 
#define US_2_trigPin 12


//US Sensor function variable
long duration, distance; 
long duration2, distance2; 


void setup() {
  //Serial comunication 
  Serial.begin (9600);

  //US sensor description, whitch is OUTPUT and INPUT
  pinMode(US_1_trigPin, OUTPUT);
  pinMode(US_1_echoPin, INPUT);
  pinMode(US_2_trigPin, OUTPUT);
  pinMode(US_2_echoPin, INPUT);
 
  lcd.init(); // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  // Blinking block cursor
  lcd.blink_on();
}

void loop() {
 
  
   delay(900);  //Pause 

  
  //Front US sensor switch on\off
   
   digitalWrite(US_1_trigPin, LOW); 
   delayMicroseconds(2); 
   digitalWrite(US_2_trigPin, LOW); 
   delayMicroseconds(2);


  //Back US sensor switch on \off
  
   digitalWrite(US_1_trigPin, HIGH);
   delayMicroseconds(10); 
   digitalWrite(US_2_trigPin, HIGH);
   delayMicroseconds(10);
   
   digitalWrite(US_1_trigPin, LOW);
   duration = pulseIn(US_1_echoPin, HIGH);

   digitalWrite(US_2_trigPin, LOW);
   duration2 = pulseIn(US_2_echoPin, HIGH);
   
   //Calculate the distance (in cm) based on the speed of sound.
   distance = duration/58.2;

    distance2 = duration2/58.2;
   
   // display on lcd. Front display print on LCD 
   
   String disp = String(distance);
 
   lcd.clear();
   lcd.setCursor (0,0 );
   lcd.print("Front :"); // first line 
   lcd.setCursor(8, 0); // second line
   lcd.print(disp);
   lcd.print(" cm");

  //Back display print on LCD 

      String disp2 = String(distance2);
   
   //lcd.clear();
  
   lcd.setCursor ( 0, 1 );
   lcd.print("Back  :"); // first line 
   lcd.setCursor(8, 1); // second line
   lcd.print(disp2);
   lcd.print(" cm     ");

   

}
