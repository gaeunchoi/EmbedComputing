#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9
#define TOUCH_STATE 7
unsigned long cnt = 0;

void colorChange(int red, int green, int blue){
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(TOUCH_STATE, INPUT);
}

void loop() {  
  int touchValue = digitalRead(TOUCH_STATE);
  
  if(touchValue == HIGH){
    cnt++;
    Serial.println("Count : ");
    Serial.print(cnt);
    Serial.println(", Sensor Touched!!");

    switch(cnt % 5){
      case 0:
        colorChange(0, 0, 0);
        break;
      case 1:
        colorChange(255, 0, 0);
        break;
      case 2:
        colorChange(80, 80, 0);
        break;
      case 3:
        colorChange(0, 255, 0);
        break;
      case 4:
        colorChange(0, 0, 255);
        break;
    }
    
    delay(200);
  } 
}
