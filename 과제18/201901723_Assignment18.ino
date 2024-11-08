#include <Servo.h>
#define SERVO_PIN 6
#define TOUCH_PIN 7

Servo myservo;
int touchCount = 0;
int pos = 0;      // set the motor position to 0
int ang = 120;
long randNum;
unsigned long startTime;
unsigned long touchTime;

void setup() {
  myservo.attach(SERVO_PIN);
  pinMode(TOUCH_PIN, INPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop() {
  int touchValue = digitalRead(TOUCH_PIN);
  if(touchValue == HIGH) {
    startTime = millis();
    while(digitalRead(TOUCH_PIN) == HIGH);
    touchTime = millis() - startTime;
    if (touchTime >= 1000 && touchTime <= 3000) {
      touchCount++;
    }
    Serial.print("touchCount = ");
    Serial.print(touchCount);
    Serial.print("\t touchTime = ");
    Serial.print(touchTime);
  
    delay(5000);                // Wait 5 seconds
    randNum = random(0, 2);     // decide tis answer randomly(Yes = 0, No = 1)
    Serial.print("\t answer randomly = ");
    Serial.println(randNum);
      
    if (randNum % 2 == 0) {       // If Yes, rotate the motor and reverse it
      for (pos = 0; pos <= ang; pos += 1) {
        myservo.write(pos);
        delay(15);
      }
      for (pos = ang; pos >= 0; pos -= 1) {
        myservo.write(pos);
        delay(15);
      }
    } else {                      // If No, rotate the motor and stop it
      for (pos = 0; pos <= ang; pos += 1) {
        myservo.write(pos);
        delay(15);
      }
    }
  }
}
