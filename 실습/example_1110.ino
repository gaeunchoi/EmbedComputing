/*
 * 201901723
 * 최가은
 * 2022.11.10.(목)
 * 수업 실
*/
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.println("Hello OLED");습
  display.display();
  delay(2000);

  display.println("Hello Arduino");
  display.display();
  delay(2000);

  display.println("Hi, Prof.Kim!");
  display.display();
  delay(2000);
}

void loop() {
  
}
