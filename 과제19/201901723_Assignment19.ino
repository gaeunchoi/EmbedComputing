/*
 * Student Number: 201901723
 * Student Name: 최가은 
 * Writing Date: 2022.12.01(목)
 * My feel about this assignment: 한학기동안 수고 많으셨습니다!
 * 다양한 과제 및 실습을 하면서 흥미를 느꼈고 한 학기 알차게 보낸 수업이었습니다.
 * 이번 과제는 iOS에 대해 데모 확인을 하지 못해서 아쉬웠지만, 친구의 휴대폰을 이용하여 확인해보았습니다.
 * 코드 자체는 간단하였지만 ios 연결 문제로 제출이 늦어진 점이 아쉽습니다ㅠ 
 */

#include <SoftwareSerial.h>

#define RX 2
#define TX 3
#define LED 7

SoftwareSerial mySerial (RX, TX);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (mySerial.available() > 0) Serial.write(mySerial.read());
  if (Serial.available() > 0) mySerial.write(Serial.read());

  char state = mySerial.read();

  if(state == '1') {
    digitalWrite(LED, HIGH);
    Serial.println("LED ON!");
    delay(1000);
  } else if (state == '0') {
    digitalWrite(LED, LOW);
    Serial.println("LED OFF!");
    delay(1000);
  }
}
