/*
 * Student ID : 201901723
 * Student Name : 최가은
 * Writing Date : 2022.11.08(화)
 * My feel about this assignment
 * 
*/

#define ECHO 2
#define TRIG 3
#define MARK0_GO 1
#define MARK0_STOP 0
#define CAR_SPEED 2

long totalDistance;

int askMark0(int dist){
  if(dist >= 15){
    return MARK0_GO;
  } else {
    return MARK0_STOP;
  }
}

void setup() {
  totalDistance = 0;
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duration = pulseIn(ECHO, HIGH);

  if(duration == 0) return;

  long distance = duration * 0.034 / 2;

  if(askMark0(distance) == MARK0_GO){
    Serial.println("Go !");
    totalDistance += CAR_SPEED * 2;
  } else {
    Serial.println("Stop !");
  }

  
  Serial.print("Total Distance: ");
  Serial.print(totalDistance);
  Serial.println("cm");
  delay(2000);
}
