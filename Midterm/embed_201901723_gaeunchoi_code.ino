/*
 * Midterm Title : Mountain Rabbits Mini Auto Piezo Speaker
 * Student No : 201901723
 * Student Name : 최가은
 * Writing Date : 2022.10.30(일) ~ 2022.11.01.(화)
*/

#define dPin1 12 // Green LED
#define dPin2 8 // Red LED
#define dPin3 4 // Piezo Speaker

// 이전 과제에서 선언한 것 사용 
enum DoReMi {DO = 0, RE, MI, FA, SOL, RA, SI, DO1};
int melody[8] = {262, 294, 330, 349, 392, 440, 494, 523};
int Rabbits[] = {SOL, MI, MI, SOL, MI, DO, RE, MI, RE, DO, MI, SOL};
int beats[]={1000, 500, 500, 500, 500, 1000, 1000, 500, 500, 500, 500, 1500};
unsigned long cnt = 0;

// Current Sound Name 출력을 위해 새로 선언한 문자열
String NoteOfRabbits[] = {"SOL", "MI", "MI", "SOL", "MI", "DO", "RE", "MI", "RE", "DO", "MI", "SOL"};

// LED ON/OFF를 위한 함수 작성 -> 중복을 줄이기 위해 선언 
void turnOnOffLed(int b, int fn){                    // b = beats, fn = FrequencyNumber
  if(fn >= 392 && fn % 2 == 0){
    if(b >= 1000){                                   // Green & Red LED 조건 -> Green 조건을 만족하면서 1000ms 이상이면 
      Serial.println("RG");                          // 켜지는 LED 이름 출력
      digitalWrite(dPin1, HIGH);  
      digitalWrite(dPin2, HIGH);
      delay(b);
      digitalWrite(dPin1, LOW);
      digitalWrite(dPin2, LOW);
      delay(b);
    } else {                                         // Green LED 조건 -> 제일 큰 if문만 만족하고 1000ms가 넘지 않으면 
      Serial.println("G");
      digitalWrite(dPin1, HIGH);
      delay(b);
      digitalWrite(dPin1, LOW);
      delay(b);
    }
  } else {                                           // Red LED 조건
     Serial.println("R");                            // 켜지는 LED 이름 출력
     digitalWrite(dPin2, HIGH);
     delay(b);
     digitalWrite(dPin2, LOW);
     delay(b);
  }
}

void displayInfo(int iter){
  Serial.print("[Iteration Number : ");
  Serial.print(12*cnt + iter);                       // Iteration Number 출력 
  Serial.print("]  Current Sound Name : ");
  Serial.print(NoteOfRabbits[iter]);                 // Current Sound Name 출력
  Serial.print(",  Current Sound Frequency : ");
  Serial.print(melody[Rabbits[iter]]);               // Sound Frequency 출력
  Serial.print(",  Turned-on LED Name :  ");
}

void setup() {
  Serial.begin(9600);
  pinMode(dPin1, OUTPUT); 
  pinMode(dPin2, OUTPUT); 
  pinMode(dPin3, OUTPUT);
}

void loop() {
  while(true){
    if(cnt % 3 == 0){                                // first 12 notes
      for(int i = 0 ; i < 12 ; i++){
        displayInfo(i);
        tone(dPin3, melody[Rabbits[i]], beats[i]);  // Piezo Speaker 출력 

        turnOnOffLed(beats[i], melody[Rabbits[i]]);               
      }
    } else if(cnt % 3 == 1){                         // second 12 notes
      for(int i = 0 ; i < 12 ; i++){
        displayInfo(i);
        tone(dPin3, melody[Rabbits[i]], (int)beats[i]/2);
          
        turnOnOffLed((int)beats[i]/2, melody[Rabbits[i]]); 
      }
    } else {                                         // play the melody silently 
      for(int i = 0 ; i < 12 ; i++){
        displayInfo(i);     

        turnOnOffLed(beats[i], melody[Rabbits[i]]); 
      }
    }
    cnt++;
  }
}
