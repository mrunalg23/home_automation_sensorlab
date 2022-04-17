#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLCe049LZ-"
#define BLYNK_DEVICE_NAME "Relay ONOFF"
#define BLYNK_AUTH_TOKEN "4huHcF0DP00YX091AhRe3rZz8oQYULsY"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define DHTTYPE DHT22
#define DHTPIN 2 //D4 of ESP8266
DHT dht(DHTPIN,DHTTYPE);

BlynkTimer timer;

int relay1 = 14; //D5 of ESP8266
int relay2 = 12; //D6 of ESP8266
int relay3 = 13; //D7 of ESP8266
int relay4 = 15; //D8 of ESP8266

char ssid[] = "SILIKON";
char pass[] = "silikon786786786";

void setup()
{
  Serial.begin(115200);
  dht.begin();
  Serial.println("started");
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);
  pinMode(relay4,OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("connected");
}

void loop()
{
  delay(2000);
  float t = dht.readTemperature();
  Serial.println(t);
  if(t > 35.0) digitalWrite(relay1, LOW);
  Blynk.virtualWrite(V4, t);
  Blynk.run();
  delay(500);
}

BLYNK_WRITE(V0) {
  
  int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
  Serial.print(pinValue);
  if (pinValue == 1) {
    digitalWrite(relay1, LOW);
  }
  if(pinValue == 0)
  {
    digitalWrite(relay1, HIGH);
  }
}
BLYNK_WRITE(V1) {
  int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
  Serial.print(pinValue);
  if (pinValue == 1) {
    digitalWrite(relay2, LOW);
  }
  if(pinValue == 0)
  {
    digitalWrite(relay2, HIGH);
  }
}
BLYNK_WRITE(V2) {
  int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
  Serial.print(pinValue);
  if (pinValue == 1) {
    digitalWrite(relay3, LOW);
  }
  if(pinValue == 0)
  {
    digitalWrite(relay3, HIGH);
  }
}
BLYNK_WRITE(V3) {
  int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
  Serial.print(pinValue);
  if (pinValue == 1) {
    digitalWrite(relay4, LOW);
  }
  if(pinValue == 0)
  {
    digitalWrite(relay4, HIGH);
  }
}
