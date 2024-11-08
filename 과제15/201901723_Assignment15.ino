/*
 * Student Number : 201901723
 * Student Name : 최가은 
 * Writing Date : 2022.11.19(토)
 * My feel about this assignment
 * 처음으로 Magnetic Switch를 사용해보았습니다. 
 * 교내 모든 강의실에는 세콤이 설치되어있는데 이또한 Magnetic Switch를 사용하여 제어하는것이라고 생각을 하게 되었고,
 * 수업에서 배우는 것을 일상 속에서 쉽게 찾을 수 있다는 것을 확인한 것 같아서 신기했습니다.
*/

#define MAG_PIN 7
#define OPEN 1
#define CLOSE 0
#define DXPIN 12

int RED = 8;

unsigned long opentime;

// Simplify the time message by hiding 0 time value
String getTimeMsg(unsigned long otime) {
  int hour, min, sec;
  String res;
  hour = otime / 3600;
  min = (otime % 3600) / 60;
  sec = otime % 60;

  if(hour == 0) res = String(min)+" m "+String(sec)+" s";
  if(min == 0) res = String(hour)+" h :"+String(sec)+" s";
  if(sec == 0) res = String(hour)+" h "+String(min)+" m ";
    

  if(hour == 0 && min == 0) res = String(sec)+" s";
  if(hour == 0 && sec == 0) res = String(min)+" m";
  if(min == 0 && sec == 0) res = String(hour)+" h";
    
    
  if(hour != 0 && min != 0 && sec != 0) res = String(hour)+" h "+String(min)+" m "+String(sec)+" s ";
  if(hour == 0 && min == 0 && sec == 0) res = "NULL";

  return res;
}

void setup() {
  pinMode(MAG_PIN, INPUT_PULLUP);
  pinMode(RED, OUTPUT);
  pinMode(DXPIN, OUTPUT);
  Serial.begin(9600);
  opentime = 0;
}

void loop() {
  int value = digitalRead(MAG_PIN);
  
  if (value == OPEN) {
    String timeMsg = getTimeMsg(opentime++);
    Serial.print("Open time: ");
    Serial.println(timeMsg);

    // Blinking a red LED every 1s if it lasts more than 20s
    if (opentime >= 20) {
      digitalWrite(RED, HIGH);
      delay(1000);
      digitalWrite(RED, LOW);

      // Alert a sound using tone() if it lasts more than 30s
      if (opentime >= 30) {
        tone(DXPIN, 6271, 150);
        delay(200);
        noTone(DXPIN);
        tone(DXPIN, 4186, 150);
        delay(200);
      }
    }
  } 
  // Stop all output and initialize the open time if the door is closed
  else {
    Serial.println("---Closed---");
    opentime = 0;
  }
  
  delay(1000);
}
