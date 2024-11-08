/*
 * Student ID : 201901723
 * Student Name : 최가은
 * Writing Date : 2022.11.08(화)
 * My feel about this assignment
 * 이전 실습에서 진행한 Tricolor LED를 이용하여 금일 실습과 결합하여 사용한 것이 재미있었습니다.
 * 초음파 센서를 처음 사용해보았는데, 거리를 측정하고 이를 시리얼 모니터로 직접 확인할 수 있는 것이 신선하게 다가왔습니다.
*/

#define ECHO 2
#define TRIG 3
#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9

void colorChange(int red, int blue, int green){
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);  
}

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(RED_PIN,OUTPUT);
  pinMode(GREEN_PIN,OUTPUT);
  pinMode(BLUE_PIN,OUTPUT); 
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  long duration = pulseIn(ECHO, HIGH);

  if(duration == 0) return;

  long distance = duration * 0.034 / 2;

  if(distance <= 10){
    Serial.println("Occupied !");
    colorChange(255, 0, 0);
  } else {
    Serial.println("Empty !");
    colorChange(0, 255, 0);
  }
  
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(2000);
}
