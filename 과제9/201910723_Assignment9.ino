/*
* Student No : 201901723
* Student Name : 최가은
* Date : 2022.10.18.화
* What I feel about this assignment : 5초마다 switch 기능을 하기 위해 if문을 사용하여 통제를 진행하였습니다. 
* switch가 없이도 다음과 같이 코드로 깔끔하게 정리할 수 있음을 확인하는 좋은 과제를 진행하였다고 생각합니다.
* 추가로 시리얼통신으로만 출력했던 실습에서 LED를 추가하여 실습해보는 재미있는 과제라고 생각했습니다 :)
*/

int dPin1 = 8;
int dPin2 = 7;
int val = 0;
unsigned long cnt;

void setup() {
  Serial.begin(9600);
  pinMode(dPin1, OUTPUT);         
  pinMode(dPin2, INPUT_PULLUP);   // Connect LED (+) with Arduino built-in pullup resistor
  cnt = 0;                        
}

void loop() {
  val = digitalRead(dPin2);       // Read D8 every 1 second
  Serial.print(cnt);
  Serial.print(") Digital Read : ");
  Serial.print(val);
  cnt++;

  if(cnt % 5 == 0){               
    digitalWrite(dPin1, HIGH);
    Serial.println(" LED ON ");   // display "LED ON" if it is 
  } else {
    digitalWrite(dPin1, LOW);
    Serial.println(" LED OFF ");  // or display "LED OFF" 
  }

  delay(1000);

}
