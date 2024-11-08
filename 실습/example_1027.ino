#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_Sensor.h>


#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float hum, temp, di;
  delay(2000);
  di = (float)9 / 5 * temp -0.55*((float)1-hum/100)*((float)9/5*temp-26)+32;
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  if(isnan(hum) || isnan(temp)){
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(hum, 1);
  Serial.print("% Temperature: ");
  Serial.print(temp, 1);
  Serial.print("C DI: ");
  Serial.print(di, 1);
  Serial.println(" pt");
}
