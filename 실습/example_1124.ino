#define INPUT_PULSE 2
#define OUTPUT_VOLTAGE A0

float preVoltage = 0; // 0~10
float voltage = 0;    // 0~5V
float dustDensity = 0;
float sumDustDensity = 0;
float avgDustDensity = 0;

void setup() {
  pinMode(INPUT_PULSE, OUTPUT);
  pinMode(OUTPUT_VOLTAGE, INPUT);
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
    delayMicroseconds(9680);
    voltage = preVoltage * 5.0 / 1024.0;
    dustDensity = (voltage - 0.3) / 0.005;
    sumDustDensity += dustDensity;
    delay(10);
  }

  avgDustDensity = sumDustDensity / 30.0;
  Serial.print("dustDensity : ");
  Serial.println(avgDustDensity);
  delay(1000);
}
