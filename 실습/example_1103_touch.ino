#define TOUCH_STATE 7

void setup() {
  Serial.begin(9600);
  pinMode(TOUCH_STATE, INPUT);

}

void loop() {
  int touchValue = digitalRead(TOUCH_STATE);

  if(touchValue == HIGH){
    Serial.println("Touched");
    delay(200);
  } 
}
