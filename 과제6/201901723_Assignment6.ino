/*
201901723 정보통신공학과 최가은
2022.10.07.금
digitalWrite을 사용하여 analogWrite를 구현했습니다.
digital 핀으로만 코딩을 하여 analogWrite와 유사한 결과를 도출해내는 것이 신기하였고 재미있는 실습이 되었다고 생각합니다.
*/

int led = 13;

void setup() {
//  Serial.begin(9600);
  pinMode(led, OUTPUT);  
}

void loop() {
  int high_delay, i;    // 증가할 때 사
  int low_delay, j;     // 감소할 때 사용

  // high delay 0 to 9
  // another for loop : 9 to 0
  for(high_delay = 0 ; high_delay < 10 ; high_delay++){
    for(i = 0 ; i < 10 ; i++){
      digitalWrite(led, HIGH);
      delay(high_delay);
      digitalWrite(led, LOW);
      delay(9-high_delay);
    }
  }
  
  for(low_delay = 9 ; low_delay >= 0 ; low_delay--){
    for(i = 0 ; i < 10 ; i++){
      digitalWrite(led, HIGH);
      delay(low_delay);
      digitalWrite(led, LOW);
      delay(9-low_delay);
    }
  }
}
