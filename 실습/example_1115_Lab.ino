/*
 * 201901723
 * 최가은
 * 2022.11.15(화)
 * Lab: drawBitmap 
*/
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C

#define LOGO_HEIGHT 16
#define LOGO_WIDTH 16

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

static const unsigned char PROGMEM logo_bmp[] = {
  0b00000000, 0b01000000,
  0b00111100, 0b00111000,
  0b00000000, 0b00000000,
  0b00000100, 0b00100000,
  0b00001010, 0b01010000,
  0b00000000, 0b00000000,
  0b00000100, 0b00100000,
  0b00000000, 0b00000000,
  0b00000000, 0b00000000,
  0b00010000, 0b00001000,
  0b00001000, 0b00010000,
  0b00000111, 0b11100000,
  0b00000000, 0b00000000,
  0b00000000, 0b00000000,
  0b00000000, 0b00000000,
  0b00000000, 0b00000000};

void drawMybitmap(void){
  display.clearDisplay();
  display.drawBitmap((display.width() - LOGO_WIDTH) / 2,
  (display.height() - LOGO_HEIGHT) / 2, 
  logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(1000);
}

void doScroll() {
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  display.startscrolldiagleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  display.startscrolldiagright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
}

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();

  // Display My Student Number
  display.setTextColor(BLACK, WHITE);
  display.setTextSize(1.2);
  display.println("Student Number");
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.println("201901723\n");

  // Display My Full Name
  display.setTextColor(BLACK, WHITE);
  display.setTextSize(1.2);
  display.print("Full Name");
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.println(" Choi GaEun\n");

  // Display My City
  display.setTextColor(BLACK, WHITE);
  display.setTextSize(1.2);
  display.print("My City");
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.println(" Siheung\n");

  // Display My Feelings
  display.setTextColor(BLACK, WHITE);
  display.setTextSize(1.2);
  display.print("My Feelings");
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.println(" Happy!");

  display.display();
  delay(10000);

  doScroll();
  delay(10000);
  drawMybitmap();
}

void loop() {
  // put your main code here, to run repeatedly:
}
