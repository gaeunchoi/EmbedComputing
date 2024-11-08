/*
201901723 최가은
20220920(화)
기본적인 실습 예제와 같은 과제라 어려움 없이 해결하였습니다.
*/

int led = 12;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  Serial.println("LED ON");
  delay(2000);
  digitalWrite(led, LOW);
  Serial.println("LED OFF");
  delay(2000);
}
