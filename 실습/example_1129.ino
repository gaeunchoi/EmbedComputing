#include <Servo.h>
#define SERVO_PIN 6

Servo myservo;
int pos = 0;
int ang = 180;

void setup() {
  myservo.attach(SERVO_PIN);
}

void loop() {
  for(pos = 0 ; pos <= ang ; pos++){
    myservo.write(pos);
    delay(15);
  }

  for(pos = ang ; pos >= 0 ; pos--){
    myservo.write(pos);
    delay(15);
  }

}
