#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define GREEN_PIN 13
#define TOUCH 7
#define PIEZO 12
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(

SCREEN_WIDTH, SCREEN_HEIGHT);

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
    display.display();
    delay(2000);

    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2.5);

    randomSeed(analogRead(0));

    Serial.begin(9600);

    pinMode(GREEN_PIN, OUTPUT);
    pinMode(TOUCH, INPUT);
    pinMode(PIEZO, OUTPUT);
}

void loop() {
    int chance = 0;

    int randomNumber[5];
    for (int j = 0; j < 5; j++) {
        randomNumber[j] = random(0, 100);
        Serial.println(randomNumber[j]);
    }

    int answer = randomNumber[random(0, 5)];
    Serial.print("answer = ");
    Serial.println(answer);

    int j = 0;
    while(true){
        display.clearDisplay();
        display.setCursor(0, 32);
        delay(1000);
        display.println(randomNumber[(j++) % 5]);
        display.display();

        for (int k = 0; k < 5; k++) {
            tone(PIEZO, 300, 10);
            delay(1000);

            int touchValue = digitalRead(TOUCH);

            if (touchValue == HIGH) {             // 터치가 입력되었을 때

                int tryValue = randomNumber[j];

                if (tryValue == answer) {           // 선택한 숫자가 정답과 동일하다면(정답)

                    for (int l = 0; l < 2; l++) {   // GREEN LED 2번 깜빡
                        digitalWrite(GREEN_PIN, HIGH);
                        delay(1000);
                        digitalWrite(GREEN_PIN, LOW);
                        delay(1000);
                    }

                    display.println("Success!");  // OLED 출력
                    display.display();
                    delay(2000);
                    return;

                } else {                              // 숫자가 정답과 다르다면(오답)

                    chance++;
                    tone(PIEZO, 300, 500);            // 부저 길게 1번 울리기
                    delay(1000);

                    if (chance == 2) {                // 2번 모두 오답을 내면

                        display.println("Failed!");   // OLED 출력
                        display.display();
                        delay(2000);
                        return;

                    }
                }
            }
        }
    }
}
