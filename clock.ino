#include <Wire.h>
#include <time.h>
#include <WiFi.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
#include "SSD1306Wire.h"
// #include "OLEDDisplayUi.h"

// Batery Reader setup
const int MAX_ANALOG_VAL = 4095;
const float MAX_BATTERY_VOLTAGE = 4.2; // Max LiPoly voltage of a 3.7 battery is 4.2

// Wifi and clock setup
const char* ssid     = "Pagliacci";
const char* password = "betegenidora";
long timezone = -3;

// Screen setup
SSD1306Wire oled(0x3c, 5, 4);

void hour_top_v() {
  oled.drawLine(10, 3, 20, 27);
  oled.drawLine(30, 3, 20, 27);
}

void hour_bottom_v() {
  oled.drawLine(20, 34, 10, 61);
  oled.drawLine(20, 34, 30, 61);
}

void hour_left_i() {
  oled.drawLine(4, 22, 4, 42);
}

void hour_right_i() {
  oled.drawLine(36, 22, 36, 42);
}

void hour_top_i() {
  oled.drawLine(20, 1, 20, 11);
}

// Painting the hours

void hour(int n) {
  switch(n) {
    case 1:
      hour_left_i();
      break;
    case 2:
      hour_left_i();
      hour_right_i();
      break;
    case 3:
      hour_left_i();
      hour_right_i();
      hour_top_i();
      break;
    case 4:
      hour_top_v();
      hour_left_i();
      break;
    case 5:
      hour_top_v();
      break;
    case 6:
      hour_top_v();
      hour_right_i();
      break;
    case 7:
      hour_top_v();
      hour_right_i();
      hour_top_i();
      break;
    case 8:
      hour_top_v();
      hour_left_i();
      hour_right_i();
      hour_top_i();
      break;
    case 9:
      hour_top_v();
      hour_bottom_v();
      hour_left_i();
      break;
    case 10:
      hour_top_v();
      hour_bottom_v();
      break;
    case 11:
      hour_top_v();
      hour_bottom_v();
      hour_right_i();
      break;
    case 12:
      hour_top_v();
      hour_bottom_v();
      hour_left_i();
      hour_right_i();
      break;
  }
}

void separator() {
  oled.fillCircle(46, 22, 2);
  oled.fillCircle(46, 42, 2);
}

void min_dec_bottom() {
  oled.drawLine(56, 48, 80, 48);
  oled.drawLine(56, 40, 56, 48);
  oled.drawLine(68, 43, 68, 48);
  oled.drawLine(80, 40, 80, 48);
}

void min_dec_left_i() {
  oled.drawLine(62, 16, 62, 32);
}

void min_dec_right_i() {
  oled.drawLine(74, 16, 74, 32);
}

void minute_dec(int n) {
  switch(n) {
    case 1:
      min_dec_left_i();
      break;
    case 2:
      min_dec_left_i();
      min_dec_right_i();
      break;
    case 3:
      min_dec_bottom();
      break;
    case 4:
      min_dec_bottom();
      min_dec_left_i();
      break;
    case 5:
      min_dec_bottom();
      min_dec_left_i();
      min_dec_right_i();
      break;
  }
}

void min_uni_v () {
  oled.drawLine(98, 24, 108, 52);
  oled.drawLine(108, 52, 118, 24);
}

void min_uni_top () {
  oled.drawLine(94, 10, 122, 10);
  oled.drawLine(94, 10, 94, 18);
  oled.drawLine(108, 10, 108, 15);
  oled.drawLine(122, 10, 122, 18);
}

void min_uni_left () {
  oled.drawLine(92, 30, 92, 46);
}

void min_uni_right () {
  oled.drawLine(124, 30, 124, 46);
}

void minute_uni(int n) {
  switch(n) {
    case 1:
      min_uni_left();
      break;
    case 2:
      min_uni_left();
      min_uni_right();
      break;
    case 3:
      min_uni_top();
      break;
    case 4:
      min_uni_v();
      min_uni_left();
      break;
    case 5:
      min_uni_v();
      break;
    case 6:
      min_uni_v();
      min_uni_right();
      break;
    case 7:
      min_uni_v();
      min_uni_left();
      min_uni_right();
      break;
    case 8:
      min_uni_v();
      min_uni_top();
      break;
    case 9:
      min_uni_v();
      min_uni_top();
      min_uni_right();
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
  separator();
  oled.display();
  delay(500);
  oled.clear();
  hour(h);
  minute_dec(md);
  minute_uni(mu);
  oled.display();
}

void show_all() {
  hour_top_v();
  hour_bottom_v();
  hour_left_i();
  hour_right_i();
  hour_top_i();

  separator();

  min_dec_bottom();
  min_dec_left_i();
  min_dec_right_i();
  
  min_uni_v();
  min_uni_top();
  min_uni_left();
  min_uni_right();

  oled.display();
}

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println();
  Serial.println("Hello");

  oled.init();
  oled.clear();
  oled.setTextAlignment(TEXT_ALIGN_CENTER);
  oled.setFont(ArialMT_Plain_16);
  oled.drawString(64, 22, "Hello");
  oled.setFont(ArialMT_Plain_10);
  oled.drawString(64, 42, "Serial port: 9600");
  oled.display();
  delay(2000);

  oled.clear();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  oled.setFont(ArialMT_Plain_10);
  oled.drawString(64, 22, "Connecting to " + String(ssid));
  oled.display();

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
  oled.clear();
  oled.setFont(ArialMT_Plain_16);
  oled.drawString(64, 22, "Wifi connected");
  oled.setFont(ArialMT_Plain_10);
  oled.drawString(64, 42, "IP address: " + String(WiFi.localIP()));
  oled.display();
  delay(2000);

  Serial.println("Contacting Time Server");
  oled.clear();
  oled.setFont(ArialMT_Plain_16);
  oled.drawString(64, 22, "Contacting Time Server");
  // I'm using the NTP servers in Brazil because they are closer to me
  configTime(3600 * timezone, 0, "time.nist.gov", "0.br.pool.ntp.org", "1.br.pool.ntp.org");
  delay(2000);
}

// int h = 1;
// int m = 0;

void loop() {
  // oled.clear();
  // Getting the local time
  struct tm tmstruct ;
  getLocalTime(&tmstruct);

  // For this clock to work, it's easier to separate tens and unities
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
  Serial.println("h: " + String(h) + " | md: " + String(md) + " | mu: " + String(mu));

  int rawValue = analogRead(A13);
  float voltageLevel = (rawValue / 4095.0) * 2 * 1.1 * 3.3; // calculate voltage level
  float batteryFraction = voltageLevel / MAX_BATTERY_VOLTAGE;
  Serial.println((String)"Raw:" + rawValue + " Voltage:" + voltageLevel + "V Percent: " + (batteryFraction * 100) + "%");

  oled.clear();
  hour(h);
  minute_dec(md);
  minute_uni(mu);
  separator();
  oled.display();
  delay(500);
  oled.clear();
  hour(h);
  minute_dec(md);
  minute_uni(mu);
  oled.display();
  delay(500);

  // if (h == 13) { h = 1; }
  // if (m == 60) { m = 0; }
  // oled.clear();
  // demo(h,m);
  // delay(500);
  // h += 1; m += 1;

  // hour(12);
  // minute_dec(5);
  // minute_uni(9);
  // separator();
  // oled.display();
  // delay(500);
  // oled.clear();
  // hour(12);
  // minute_dec(5);
  // minute_uni(9);
  // oled.display();
  // delay(500);
}
