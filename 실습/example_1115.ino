/*
 * 201901723
 * 최가은
 * 2022.11.15.(화)
 * 수업 실습 
*/

#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

void doScroll(){
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);  
}

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.println("Hello OLED");
  display.display();
  delay(2000);
  
  display.setTextColor(BLACK, WHITE);
  display.println("Hello Arduino");
  display.display();
  delay(2000);

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 32);
  display.setTextColor(WHITE);
  display.println("Hi, Prof.Kim!");
  display.display();
  delay(2000);

  doScroll();
}

void loop() {
  
}
