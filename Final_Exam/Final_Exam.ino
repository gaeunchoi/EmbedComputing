#define GREEN 8
#define TRIG 3
#define ECHO 2
#define PIR_PIN 4
#define TOUCH 7

unsigned long startTime;
unsigned long touchTime;
unsigned int score;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(TOUCH, INPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600); 
}

void loop() {
  startTime = millis();
  int touchValue = digitalRead(TOUCH);
  if(touchValue == HIGH){
    touchTime = millis() - startTime;
    if(touchTime >= 5000){
      digitalWrite(GREEN, HIGH);
      Serial.println("READY");
      delay(1000);
      
//      delay(1000);
      int shootTouch = digitalRead(TOUCH);
      if(shootTouch == HIGH){
        int randomNumber = random(0, 100);
        if(randomNumber < 10){        // 10% 확률 치명타 발생시 출력 
          Serial.println("Lucky!"); 
          delay(1000);
        } else {
          Serial.println("BOOM");
          delay(1000);
        }
        
        
        int pirValue = digitalRead(PIR_PIN);
        if(pirValue == HIGH){             // PIR 센서가 범위 내의 인체 움직임 탐지하면
          digitalWrite(TRIG, HIGH); // 초음파 센서로 거리 재기 
          delayMicroseconds(10); 
          digitalWrite(TRIG, LOW); 
          long duration = pulseIn(ECHO, HIGH);   
          if(duration == 0) return;
          long distance = duration * 0.034 / 2;

          if(distance <= 100) {           // 거리가 1미터 이내면 맞은것 간주 
            Serial.println("HIT!");
            if(randomNumber <= 10){         // 치명타인 경우 점수 2배 
              if(distance >= 90){           // 후에 거리 구간에 따라 점수 부여
                score += 20;
              } else if(distance >= 80){
                score += 16;
              } else if(distance >= 70){
                score += 14;
              } else if(distance >= 60){
                score += 12;
              } else if(distance >= 50){
                score += 10;
              } else if(distance >= 30){
                score += 8;
            }
            } else {                        // 일반 거리 구간에 따른 점수 부여 
              if(distance >= 90){          
                score += 10;
              } else if(distance >= 80){
                score += 8;
              } else if(distance >= 70){
                score += 7;
              } else if(distance >= 60){
                score += 6;
              } else if(distance >= 50){
                score += 5;
              } else if(distance >= 30){
                score += 4;
              }
            }
          }  
          Serial.print("Score = ");
          Serial.println(score);
        }

        digitalWrite(GREEN, LOW);
        delay(1000);
        int coolTime = 5;
        for(int i = coolTime ; i > 0 ; i--){
          shootTouch = digitalRead(TOUCH);
          if(shootTouch == HIGH) Serial.println("COOLTIME");
          Serial.println(i);
          delay(1000);
        }
        touchTime = 0;
      } else {    // 대기상태일 때 
          Serial.println("STANDBY");
          delay(1000);
    
          int shootTouch = digitalRead(TOUCH);
          if(shootTouch == HIGH){
            int standby = 5;
            for(int i = standby ; i > 0 ; i--){
              Serial.println(i);
              delay(1000);
            }
          }
    }
    } 
  }
  
 
}
