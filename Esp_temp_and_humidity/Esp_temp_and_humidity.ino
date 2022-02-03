#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
DHT dht;
char auth[] = "Gmainauthentification code here";
char ssid[] = "network ssid ";
char pass[] = "network password";
#define DHTPIN 2

BlynkTimer timer;

void sendSensor()
{
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  Blynk.virtualWrite(V5, temperature);
  Blynk.virtualWrite(V6, humidity);
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  int DHT, begin;
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
