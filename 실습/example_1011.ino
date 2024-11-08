#define DX 12

int abc[] = {262, 294, 330, 349, 392, 440, 494, 523};

void mtone(int dx, int hz, unsigned long tm){
  unsigned long t = millis();
  unsigned long ns = (long)500000 / hz;

  while(millis() - t < tm){
    digitalWrite(dx, HIGH);
    delayMicroseconds(ns);
    digitalWrite(dx, LOW);
    delayMicroseconds(ns);
  }
}

void setup() {
  pinMode(DX, OUTPUT);  
}

void loop() {
  for(int i = 0 ; i < 8 ; i++){
    mtone(DX, abc[i], 500);
    delay(50);
  }
//  digitalWrite(12, HIGH);
//  delay(2);
//  digitalWrite(12, LOW);
//  delay(2);
//  delay(1000);
//   return;
//  analogWrite(11, 51);
}
