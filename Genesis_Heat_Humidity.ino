#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT22
#define dht_pin 8
#define heat_pin 7
#define fan_pin 4
#define heat_fan_pin 2

DHT dht1(dht_pin,DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht1.begin();
  pinMode(fan_pin, OUTPUT);
  pinMode(heat_pin,OUTPUT);
  pinMode(heat_fan_pin,OUTPUT);
  

}

void loop() {
  
  float tempC = dht1.readTemperature();
  float humidity = dht1.readHumidity();
  Serial.println(tempC);
  Serial.println(humidity);
  
  if(tempC>32){
    digitalWrite(fan_pin,HIGH);
    digitalWrite(heat_pin,LOW);
    digitalWrite(heat_fan_pin,LOW);
  }
  else if(tempC<32){
    digitalWrite(heat_pin,HIGH);
    digitalWrite(heat_fan_pin,HIGH);
    digitalWrite(fan_pin,LOW);
  }
  else{
    digitalWrite(heat_pin,LOW);
    digitalWrite(heat_fan_pin,LOW);
    digitalWrite(fan_pin,LOW);
  }


}
