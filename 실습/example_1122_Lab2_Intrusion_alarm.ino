/*
 * 201901723
 * 최가은 
 * 2022.11.22.(화)
 * 
*/

#define PIR_PIN 7
#define PIEZO 6

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(PIEZO, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(PIR_PIN);
  if(value == HIGH){
    for(int i = 0 ; i < 3 ; i++){
      tone(PIEZO, 523, 250);
      delay(200);
      tone(PIEZO, 783, 250);
      delay(200);
    }
    Serial.println("Detected!");
  } else {
    Serial.println("Not Detected!");
  }
  delay(1000);
}
