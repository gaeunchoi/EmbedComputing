/*
* Student No : 201901723
* Student Name : 최가은
* Writing date : 2022.10.30.(일)
* My feel about this assignment : LED를 제외하고 처음으로 센서를 다뤄본 실습 및 과제였습니다.
* 온도와 습도를 센서를 통해 확인해보고 이를 출력하고 이 값들을 가지고 시리얼모니터를 통해 출력하는 과제를 진행했는데
* 처음 센서를 다뤄보는 좋은 경험을 한 것 같아서 유익했다고 생각합니다.
*/

#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_Sensor.h>

#define DHTPIN 2
#define DHTTYPE DHT11

unsigned long cnt;
int i = 0;
int j = 10;
float hum, temp, di;
float avg_hum, avg_temp, avg_di;
float sum_hum, sum_temp, sum_di;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  cnt = 0;
}

void loop() {
  int i;
  int j = 10;

  delay(2000);
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  di = (float)9/5*temp - 0.55*((float)1-hum/100)*((float)9/5*temp-26)+32;
  sum_hum += hum;
  sum_temp += temp;
  sum_di += di;

  if(isnan(hum) || isnan(temp)){
    return;
  }

  cnt++;

  if(cnt % 10 == 0){                
    avg_hum = sum_hum/(float)j;
    avg_temp = sum_temp/(float)j;
    avg_di = sum_di/(float)j;
    Serial.print("Avg (H, T, Di) : ");
    Serial.print(avg_hum, 2);
    Serial.print(", ");
    Serial.print(avg_temp, 2);
    Serial.print(", ");
    Serial.println(avg_di, 2);
    sum_hum = 0;
    sum_temp = 0;ㄴ
    sum_di = 0;
  }

    Serial.print(cnt);
    Serial.print(") Humidity : ");
    Serial.print(hum, 2);
    Serial.print("% Temerature : ");
    Serial.print(temp, 2);
    Serial.print("C DI : ");
    Serial.print(di, 2);
    Serial.println(" pt");
  
}
