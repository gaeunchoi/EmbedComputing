int pinNo = 8;

void setup() {
  Serial.begin(9600);
  pinMode(pinNo, INPUT);
}

void loop() {
  int val = digitalRead(pinNo);
  Serial.print("val = ");
  Serial.println(val);  
}
