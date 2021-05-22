#include <LiquidCrystal.h>
#include "DHT.h"
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
#define DHTPIN 8
#define red 9
#define yellow 10
#define blue 11

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  //led
  pinMode ( red,    OUTPUT );
  pinMode ( blue,  OUTPUT );
  pinMode ( yellow, OUTPUT );

  //Serial comunication
  lcd.begin(20, 4);
  //Tem and hum sensor descrioption
  dht.begin();
  //lcd displaty pins and text
  lcd.setCursor(7, 1);
  lcd.print(" Hello");
  lcd.setCursor(6, 2);
  lcd.print("Mr Giorgi ");
  delay ( 5000 );
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("I'am  New generation");
  lcd.setCursor(0, 1);
  lcd.print("  and  intelligent  ");
  lcd.setCursor(0, 2);
  lcd.print("    system Jaris ");
  lcd.setCursor(0, 3);
  lcd.print("GEO-ARDUINO-PROJECTS");
  delay ( 10000 );
  lcd.clear();

}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    lcd.print("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  lcd.setCursor(5, 0); //4 aris x gerdzi da 0 aris y gerdzi
  lcd.print("Temperature ");
  lcd.setCursor(7, 1);
  lcd.print(t);
  lcd.print(" C ");
  lcd.display();
  lcd.setCursor(6, 2);
  lcd.print("Humidity ");
  lcd.setCursor(7, 3);
  lcd.print(h);
  lcd.print("  %");

  if (t > 22)
  {
    digitalWrite(blue, HIGH);

  }
  else
    digitalWrite(blue, LOW);

  if ( t < 22 ) {
    digitalWrite (9,  HIGH);
    delay ( 500 );
    digitalWrite (9,  LOW);
    delay ( 500 );
    digitalWrite (10, HIGH);
    delay ( 500 );
    digitalWrite (10, LOW);
    delay (500);
  }

}

