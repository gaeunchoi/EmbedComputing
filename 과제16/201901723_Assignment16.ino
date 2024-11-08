/*
 * Student Number: 201901723
 * Student Name: 최가은 
 * Writing Date: 2022.11.22(화)
 * My feel about this assignment:
 * 
*/

#define PIR_PIN 8

#define MAG_PIN 7
#define OPEN 1
#define CLOSE 0

#define RED_PIN 13
#define GREEN_PIN 12
#define BLUE_PIN 11

void colorChange(int red, int green){
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, 0);
}

void setup() {
  Serial.begin(9600);
  
  pinMode(MAG_PIN, INPUT_PULLUP);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT); 
}

void loop() {
  int pir_value = digitalRead(PIR_PIN);
  int mag_value = digitalRead(MAG_PIN);

  if(pir_value == HIGH){
    Serial.print("Motion Detected, ");
    if(mag_value == CLOSE){
      Serial.print("the door is closed:  ");
      Serial.println("the toilet is in use");
      colorChange(255, 0);
    } else {
      Serial.print("the door is opened : ");
      Serial.println("the toilet is empty");
      colorChange(0, 255);
    }
  } else {
    Serial.print("Motion Not Detected, ");
    
    if(mag_value == CLOSE) Serial.print("the door is closed:  ");
    else Serial.print("the door is opened: ");
    
    Serial.println("the toilet is empty");
    colorChange(0, 255);
  }
  delay(2000);
}
