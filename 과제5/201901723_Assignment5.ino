/*
201901723 최가은
2022.10.04.(화)
*/

int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop() {
  int temp = 0;             // Initial temperature
  while(temp < 100){
    Serial.println(temp);
    temp += 3;              // Every 1000ms, +3C
    delay(1000); 
  }

  if(temp > 100){           // When it exceeds 100C
    for(int i = 0 ; i < 10 ; i++){    // Blinking 10 times
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
    }

    while(temp >= 0){       // After blinking 10 times
      Serial.println(temp); 
      temp -= 3;            // decrease the temp 3C every 1000ms
      delay(1000);
    }

    temp = 0;               // Set it zero
    Serial.println("Repeat");   // repeat
  }
}
