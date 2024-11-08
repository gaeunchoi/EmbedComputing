#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9
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
}

void loop() {
  for(int di = 60 ; di <= 90 ; di += 2){
    Serial.print("DI = ");
    Serial.print(di);
    
    if(di >= 80){
      colorChange(255, 0, 0);
      Serial.println(" -> Turned-On LED : Red");
    } else if(di >= 75){
      colorChange(255, 128, 0);
      Serial.println(" -> Turned-On LED : Orange");
    } else if(di >= 68){
      colorChange(0, 255, 0);
      Serial.println(" -> Turned-On LED : Green");
    } else {
      colorChange(0, 0, 255);
      Serial.println(" -> Turned-On LED : Blue");
    }

    delay(1000);
  }
  
}
