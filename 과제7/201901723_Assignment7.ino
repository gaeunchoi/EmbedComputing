/*
* Student no : 201901723 
* Student Name : 최가은
* Writing Date : 2022.10.12.(수)
* My feel about this assignment
* 피에조 스피커를 다뤄보는 실습을 진행했습니다. 
* 제 피에조 스피커가 문제가 있어 처음에 소리를 제대로 출력되지 않았는데
* 실습기기 변경 후 소리를 출력하여 들어보았고, 이를 사용하여 멜로디를 출력하는 과제를 진행했습니다.
* 이전에 실습을 하던 LED나 시리얼 모니터만 사용하는 것이 아니라 새로운 경험을 했다고 생각합니다.
* 반복문을 돌면서 작은별 음계에 대한 멜로디를 피에조 스피커를 이용하여 출력해보았고,
* 이에 대해 이해가 완전히 되었다고 볼 수 있습니다.
*/

#define DX 12

// 열거형으로 도레미파솔라시도 음계 
enum DoReMi {DO=0, RE, MI, FA, SOL, RA, SI, DO1};

// 도레미파솔라시도 멜로디 선언
int melody[8] = {262, 294, 330, 349, 392, 440, 494, 523};

// 산토끼 음계
int rabbits[] = {SOL, MI, MI, SOL, MI, DO, RE, MI, RE, DO, MI, SOL};

// 산토끼 비트 
int beats[]={3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 3};

void setup() { 
}

void loop() {
  for(int i = 0 ; i < 12 ; i++){
    tone(DX, melody[rabbits[i]], 500);    
    delay(beats[i]*200);
    noTone(DX);
    delay(500);
  }
  delay(1000);
}
