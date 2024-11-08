#include <Servo.h>
#define SERVO_PIN 6
#define TOUCH_PIN 7

Servo myservo;
int touchCount = 0;
int pos = 0;
int ang = 180;
unsigned long startTime;
unsigned long touchTime;

void setup() {
  myservo.attach(SERVO_PIN);
  pinMode(TOUCH_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int touchValue = digitalRead(TOUCH_PIN);
  if(touchValue == HIGH) {
    startTime = millis(); // millis() -> 현재 시간
    while(digitalRead(TOUCH_PIN) == HIGH)
    touchTime = millis() - startTime;
    if (touchTime >= 1000 && touchTime <= 3000) {
      touchCount++;
    }
    Serial.print("touchCount = ");
    Serial.print(touchCount);
    Serial.print("\ttouchTime = ");
    Serial.println(touchTime);
  }
  
  if (touchCount % 2 == 1) {
    // motor
    for (pos = 0; pos <= ang; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
    for (pos = ang; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
  }
}
