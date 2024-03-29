#include <Wire.h>
#include <time.h>
#include <WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const char* ssid     = "Pagliacci";
const char* password = "betegenidora";
long timezone = -3;


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

// Painting the hours

void hour(int n) {
  switch(n) {
    case 1:
      hour_top_v(BLACK);
      hour_bottom_v(BLACK);
      hour_left_i(WHITE);
      hour_right_i(BLACK);
      hour_top_i(BLACK);
      break;
    case 2:
      hour_top_v(BLACK);
      hour_bottom_v(BLACK);
      hour_left_i(WHITE);
      hour_right_i(WHITE);
      hour_top_i(BLACK);
      break;
    case 3:
      hour_top_v(BLACK);
      hour_bottom_v(BLACK);
      hour_left_i(WHITE);
      hour_right_i(WHITE);
      hour_top_i(WHITE);
      break;
    case 4:
      hour_top_v(WHITE);
      hour_bottom_v(BLACK);
      hour_left_i(WHITE);
      hour_right_i(BLACK);
      hour_top_i(BLACK);
      break;
    case 5:
      hour_top_v(WHITE);
      hour_bottom_v(BLACK);
      hour_left_i(BLACK);
      hour_right_i(BLACK);
      hour_top_i(BLACK);
      break;
    case 6:
      hour_top_v(WHITE);
      hour_bottom_v(BLACK);
      hour_left_i(BLACK);
      hour_right_i(WHITE);
      hour_top_i(BLACK);
      break;
    case 7:
      hour_top_v(WHITE);
      hour_bottom_v(BLACK);
      hour_left_i(BLACK);
      hour_right_i(WHITE);
      hour_top_i(WHITE);
      break;
    case 8:
      hour_top_v(WHITE);
      hour_bottom_v(BLACK);
      hour_left_i(WHITE);
      hour_right_i(WHITE);
      hour_top_i(WHITE);
      break;
    case 9:
      hour_top_v(WHITE);
      hour_bottom_v(WHITE);
      hour_left_i(WHITE);
      hour_right_i(BLACK);
      hour_top_i(BLACK);
      break;
    case 10:
      hour_top_v(WHITE);
      hour_bottom_v(WHITE);
      hour_left_i(BLACK);
      hour_right_i(BLACK);
      hour_top_i(BLACK);
      break;
    case 11:
      hour_top_v(WHITE);
      hour_bottom_v(WHITE);
      hour_left_i(BLACK);
      hour_right_i(WHITE);
      hour_top_i(BLACK);
      break;
    case 12:
      hour_top_v(WHITE);
      hour_bottom_v(WHITE);
      hour_left_i(WHITE);
      hour_right_i(WHITE);
      hour_top_i(BLACK);
      break;
  }
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

void minute_dec(int n) {
  switch(n) {
    case 0:
      min_dec_bottom(BLACK);
      min_dec_left_i(BLACK);
      min_dec_right_i(BLACK);
      break;
    case 1:
      min_dec_bottom(BLACK);
      min_dec_left_i(WHITE);
      min_dec_right_i(BLACK);
      break;
    case 2:
      min_dec_bottom(BLACK);
      min_dec_left_i(WHITE);
      min_dec_right_i(WHITE);
      break;
    case 3:
      min_dec_bottom(WHITE);
      min_dec_left_i(BLACK);
      min_dec_right_i(BLACK);
      break;
    case 4:
      min_dec_bottom(WHITE);
      min_dec_left_i(WHITE);
      min_dec_right_i(BLACK);
      break;
    case 5:
      min_dec_bottom(WHITE);
      min_dec_left_i(WHITE);
      min_dec_right_i(WHITE);
      break;
  }
}

void min_uni_v (uint16_t color) {
  oled.drawLine(98, 24, 108, 52, color);
  oled.drawLine(108, 52, 118, 24, color);
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

void minute_uni(int n) {
  switch(n) {
    case 0:
      min_uni_v(BLACK);
      min_uni_top(BLACK);
      min_uni_left(BLACK);
      min_uni_right(BLACK);
      break;
    case 1:
      min_uni_v(BLACK);
      min_uni_top(BLACK);
      min_uni_left(WHITE);
      min_uni_right(BLACK);
      break;
    case 2:
      min_uni_v(BLACK);
      min_uni_top(BLACK);
      min_uni_left(WHITE);
      min_uni_right(WHITE);
      break;
    case 3:
      min_uni_v(BLACK);
      min_uni_top(WHITE);
      min_uni_left(BLACK);
      min_uni_right(BLACK);
      break;
    case 4:
      min_uni_v(WHITE);
      min_uni_top(BLACK);
      min_uni_left(WHITE);
      min_uni_right(BLACK);
      break;
    case 5:
      min_uni_v(WHITE);
      min_uni_top(BLACK);
      min_uni_left(BLACK);
      min_uni_right(BLACK);
      break;
    case 6:
      min_uni_v(WHITE);
      min_uni_top(BLACK);
      min_uni_left(BLACK);
      min_uni_right(WHITE);
      break;
    case 7:
      min_uni_v(WHITE);
      min_uni_top(BLACK);
      min_uni_left(WHITE);
      min_uni_right(WHITE);
      break;
    case 8:
      min_uni_v(WHITE);
      min_uni_top(WHITE);
      min_uni_left(BLACK);
      min_uni_right(BLACK);
      break;
    case 9:
      min_uni_v(WHITE);
      min_uni_top(WHITE);
      min_uni_left(BLACK);
      min_uni_right(WHITE);
      break;
  }
}

void demo(int h, int m) {
  int md = trunc(m / 10);
  int mu = m % 10;

  Serial.print("h: ");
  Serial.print(h);
  Serial.print(" | ");

  Serial.print("md: ");
  Serial.print(md);
  Serial.print(" | ");

  Serial.print("mu: ");
  Serial.print(mu);
  Serial.print("\n");

  delay(500);
  separator(BLACK);
  oled.display();
  delay(500);
  separator(WHITE);
  hour(h);
  minute_dec(md);
  minute_uni(mu);
  oled.display();
}

void show_all() {
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

  oled.display();
}

void setup() {
  Serial.begin(9600);

  // initialize OLED display with I2C address 0x3C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }
  oled.clearDisplay();

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  int i = 0;

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 20) {
      ESP.restart();
    }
    i++;
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Contacting Time Server");
  configTime(3600 * timezone, 0, "time.nist.gov", "0.br.pool.ntp.org", "1.br.pool.ntp.org");
}

void loop() {
  struct tm tmstruct ;
  getLocalTime(&tmstruct);
  int h = tmstruct.tm_hour % 12;
  int m = tmstruct.tm_min;
  int md = trunc(m / 10);
  int mu = m % 10;
  if (h == 0) {
    h = 12;
  }
  if (h == 0 && m == 0 && tmstruct.tm_sec <= 2) { 
    Serial.println("Contacting Time Server");
    configTime(3600 * timezone, 0, "time.nist.gov", "0.br.pool.ntp.org", "1.br.pool.ntp.org");
  }
  // if (m == 60) { m = 0; }
  // demo(h,m);
  // h += 1; m += 1;

  hour(h);
  minute_dec(md);
  minute_uni(mu);
  separator(WHITE);
  oled.display();

  Serial.println("h: " + String(h) + " | md: " + String(md) + " | mu: " + String(mu));
  

  delay(500);
  separator(BLACK);
  oled.display();
  delay(500);

}
