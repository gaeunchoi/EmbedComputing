/*
 * 201901723
 * 최가은 
 * 2022.11.22.(화)
 * 
*/

#define PIR_PIN 7
#define BUILTIN_LED 13

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(PIR_PIN);
  if(value == HIGH){
    digitalWrite(BUILTIN_LED, HIGH);
    Serial.println("Detected!");
  } else {
    digitalWrite(BUILTIN_LED, LOW);
    Serial.println("Not Detected!");
  }
  delay(1000);
}
