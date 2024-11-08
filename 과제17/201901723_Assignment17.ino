/*
 * Student Number: 201901723
 * Student Name: 최가은 
 * Writing Date: 2022.11.25(금) 
 * My feel about this assignment:
 * MagneticSwitch와 달리 Dust Sensor는 제가 제어할 수 없어서 다양한 값이 출력되는것을 확인할 수 없어서 아쉬웠습니다.
 * 하지만 코드를 생각해봤을때 과제 내의 조건은 모두 잘 만족시켜 작성한 것 같습니다.
 * 다양한 환경 속에서 직접 실험해보면 좋았을것이라는 아쉬움이 남았습니다.
*/
// DustSensor --------------
#define INPUT_PULSE 2
#define OUTPUT_VOLTAGE A0
float preVoltage = 0; // 0~1023V
float voltage = 0;    // 0~5V
float dustDensity = 0;
float sumDustDensity = 0;
float avgDustDensity = 0;

// Tri-color LED -----------
#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9

void colorChange(int red, int green, int blue){
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

void setup() {
  pinMode(INPUT_PULSE, OUTPUT);
  pinMode(OUTPUT_VOLTAGE, INPUT);
  
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT); 
  pinMode(BLUE_PIN, OUTPUT);
  
  Serial.begin(9600);  
}

void loop() {
  sumDustDensity = 0;

  for(int i = 0 ; i < 30 ; i++){
    digitalWrite(INPUT_PULSE, LOW);
    delayMicroseconds(280);           // 0.28ms
    preVoltage = analogRead(OUTPUT_VOLTAGE);
    delayMicroseconds(40);            // 0.04ms
    digitalWrite(INPUT_PULSE, HIGH);
    delayMicroseconds(9680);          // 9.68ms
    voltage = preVoltage * 5.0 / 1024.0;
    dustDensity = (voltage - 0.3) / 0.005;
    sumDustDensity += dustDensity;
    delay(10);
  }

  avgDustDensity = sumDustDensity / 30.0;

  if(avgDustDensity <= 30) {          // Good(Blue)
    colorChange(0, 0, 255);
    Serial.print("Good, ");
  } else if(avgDustDensity <= 50) {   // Normal(Green)
    colorChange(0, 255, 0);
    Serial.print("Normal, ");
  } else if(avgDustDensity <= 100) {  // Bad(Orange)
    colorChange(255, 165, 0);
    Serial.print("Bad, ");
  } else {                            // Polluted(Red)
    colorChange(255, 0, 0);
    Serial.print("Polluted, ");
  }
  
  Serial.print("dustDensity : ");
  Serial.println(avgDustDensity);
  delay(1000);

}
