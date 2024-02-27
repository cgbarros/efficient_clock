#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED width,  in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels

// create an OLED display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void hour_top_v(uint16_t color) {
  oled.drawLine(10, 3, 20, 27, color);
  oled.drawLine(30, 3, 20, 27, color);
}

void hour_bottom_v(uint16_t color) {
  oled.drawLine(20, 34, 10, 61, color);
  oled.drawLine(20, 34, 30, 61, color);
}

void hour_left_i(uint16_t color) {
  oled.drawLine(4, 22, 4, 42, color);
}

void hour_right_i(uint16_t color) {
  oled.drawLine(36, 22, 36, 42, color);
}

void hour_top_i(uint16_t color) {
  oled.drawLine(20, 1, 20, 11, color);
}

void separator(uint16_t color) {
  oled.fillCircle(46, 22, 2, color);
  oled.fillCircle(46, 42, 2, color);
}

void min_dec_bottom(uint16_t color) {
  oled.drawLine(56, 48, 80, 48, color);
  oled.drawLine(56, 40, 56, 48, color);
  oled.drawLine(68, 43, 68, 48, color);
  oled.drawLine(80, 40, 80, 48, color);
}

void min_dec_left_i(uint16_t color) {
  oled.drawLine(62, 16, 62, 32, color);
}

void min_dec_right_i(uint16_t color) {
  oled.drawLine(74, 16, 74, 32, color);
}

void min_uni_v (uint16_t color) {
  oled.drawLine(96, 22, 108, 54, color);
  oled.drawLine(108, 54, 120, 22, color);
}

void min_uni_top (uint16_t color) {
  oled.drawLine(94, 10, 122, 10, color);
  oled.drawLine(94, 10, 94, 18, color);
  oled.drawLine(108, 10, 108, 15, color);
  oled.drawLine(122, 10, 122, 18, color);
}

void min_uni_left (uint16_t color) {
  oled.drawLine(92, 30, 92, 46, color);
}

void min_uni_right (uint16_t color) {
  oled.drawLine(124, 30, 124, 46, color);
}

void setup() {
  Serial.begin(9600);

  // initialize OLED display with I2C address 0x3C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }

  delay(2000);         // wait two seconds for initializing
  oled.clearDisplay(); // clear display

  hour_top_v(WHITE);
  hour_bottom_v(WHITE);
  hour_left_i(WHITE);
  hour_right_i(WHITE);
  hour_top_i(WHITE);

  separator(WHITE);

  min_dec_bottom(WHITE);
  min_dec_left_i(WHITE);
  min_dec_right_i(WHITE);
  
  min_uni_v(WHITE);
  min_uni_top(WHITE);
  min_uni_left(WHITE);
  min_uni_right(WHITE);

  
  


  // oled.setTextSize(1);         // set text size
  // oled.setTextColor(WHITE);    // set text color
  // oled.setCursor(0, 2);       // set position to display (x,y)
  // oled.println("Robotronix"); // set text
  oled.display();              // display on OLED
}

void loop() {

  delay(500);
  separator(BLACK);
  oled.display();
  delay(500);
  separator(WHITE);
  oled.display();

}
