#include <DHT.h>

#define DHTPIN 2     
#define DHTTYPE DHT11
#define PIRPIN 3
#define LEDPIN 4
#define FANPIN 5

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(PIRPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(FANPIN, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // PIR Sensor
  int motion = digitalRead(PIRPIN);
  if (motion == HIGH) {
    digitalWrite(LEDPIN, HIGH); // Lampu nyala
  } else {
    digitalWrite(LEDPIN, LOW); // Lampu mati
  }

  // Suhu
  float temp = dht.readTemperature();
  Serial.print("Temp: ");
  Serial.println(temp);

  if (temp > 30.0) {
    digitalWrite(FANPIN, HIGH); // Kipas nyala
  } else {
    digitalWrite(FANPIN, LOW); // Kipas mati
  }

  delay(1000);
}
