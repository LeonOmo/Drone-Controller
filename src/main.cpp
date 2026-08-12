#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <AlfredoCRSF.h>

#define JOY1_X 32
#define JOY1_Y 33
#define JOY1_SW 34
#define JOY2_X 35
#define JOY2_Y 4
#define JOY2_SW 5

#define POT1 25
#define POT2 2
#define POT3 0

#define SW_FM 36
#define SW_Buzzer 39
#define SW_GEAR 14
#define SW_ARM 26
#define SW_FOLD 27

#define LED_GEAR 12
#define LED_ARMS 13
#define LED_ON  15

#define OLED_SCL 22
#define OLED_SDA 21
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define RX 16
#define TX 17 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
AlfredoCRSF crsf;

void setup() {
  Serial.begin(115200);

  pinMode(SW_FM, INPUT);
  pinMode(SW_Buzzer, INPUT);
  pinMode(SW_GEAR, INPUT_PULLUP);
  pinMode(SW_ARM, INPUT_PULLUP);
  pinMode(SW_FOLD, INPUT_PULLUP);
  pinMode(JOY1_SW, INPUT_PULLUP);
  pinMode(JOY2_SW, INPUT_PULLUP);

  pinMode(LED_ARMS, OUTPUT);
  pinMode(LED_GEAR, OUTPUT);
  pinMode(LED_ON, OUTPUT);

  digitalWrite(LED_ARMS, LOW);
  digitalWrite(LED_GEAR, LOW);
  digitalWrite(LED_ON, LOW);

  Wire.begin(OLED_SDA, OLED_SCL);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Display was not found!"); 
  } else {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(5, 0);
    display.println("OMO SYSTEMS :)");
    display.setCursor(5, 15);
    display.println("Connecting RP1...");
    display.setCursor(5, 30);
    display.println("Welcome!");
    display.display();
    delay(2000);
  }

  Serial1.begin(420000, SERIAL_8N1, RX, TX);
  crsf.begin(Serial1);
}

void loop() {
  int roll     = map(analogRead(JOY1_X), 0, 4095, 191, 1792);
  int pitch    = map(analogRead(JOY1_Y), 0, 4095, 191, 1792);
  int yaw      = map(analogRead(JOY2_X), 0, 4095, 191, 1792);
  int throttle = map(analogRead(JOY2_Y), 0, 4095, 191, 1792);

  int Pot1Val = map(analogRead(POT1), 0, 4095, 191, 1792);
  int Pot2Val = map(analogRead(POT2), 0, 4095, 191, 1792);
  int Pot3Val = map(analogRead(POT3), 0, 4095, 191, 1792);

  int swFm     = (digitalRead(SW_FM) == LOW)     ? 1792 : 191;
  int swBuzzer = (digitalRead(SW_Buzzer) == LOW) ? 1792 : 191;
  int swGear   = (digitalRead(SW_GEAR) == LOW)   ? 1792 : 191;
  int swArm    = (digitalRead(SW_ARM) == LOW)    ? 1792 : 191;
  int swFold   = (digitalRead(SW_FOLD) == LOW)   ? 1792 : 191;

  digitalWrite(LED_ARMS, (swArm == 1792) ? HIGH : LOW);
  digitalWrite(LED_GEAR, (swGear == 1792) ? HIGH : LOW);

  bool isConnected = crsf.isLinkUp();
  digitalWrite(LED_ON, isConnected ? HIGH : LOW);

  crsf_channels_t crsfChannels;
  crsfChannels.ch0  = roll;
  crsfChannels.ch1  = pitch;
  crsfChannels.ch2  = throttle;
  crsfChannels.ch3  = yaw;
  crsfChannels.ch4  = swArm;
  crsfChannels.ch5  = swFm;
  crsfChannels.ch6  = swBuzzer;
  crsfChannels.ch7  = swGear;
  crsfChannels.ch8  = swFold;
  crsfChannels.ch9  = Pot1Val;
  crsfChannels.ch10 = Pot2Val;
  crsfChannels.ch11 = Pot3Val;

  crsf.writeChannels(0xC8, &crsfChannels);
  crsf.update();

  static unsigned long lastDisplayUpdate = 0;
  if (millis() - lastDisplayUpdate > 100) {
    lastDisplayUpdate = millis();
    
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("OMO");
    display.println(isConnected ? "[CONNECTED]" : "[NO SIGNAL]");
    display.println("--------------");

    float batteryVolts = 15.8;
    int rssi = isConnected ? crsf.getLinkStatistics()->active_antenna : 0;
    int speedKmH = 0;
    int altitudeMeters = 0;

    display.printf("Bat: %.1fV | Sig: %d%%\n", batteryVolts, rssi);
    display.printf("Alt: %dm   | Spd: %dkm/h\n", altitudeMeters, speedKmH);
    display.println("--------------");

    display.printf("ARM: %s | GEAR: %s\n", 
                   (swArm == 1792) ? "ON " : "OFF",
                   (swGear == 1792) ? "DOWN" : "UP");
    display.display();
  }
}
