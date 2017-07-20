#include <ESP8266WiFi.h>          // https://github.com/esp8266/Arduino
#include <EEPROM.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>          // https://github.com/tzapu/WiFiManager
#include <ArduinoJson.h>          // https://github.com/bblanchon/ArduinoJson
#include <ArduinoHomeLibrary.h>   // https://github.com/arduino-home/arduino-home-library

#define CONFIG_PIN      D1
#define RGB1_RED_PIN    D5
#define RGB1_GREEN_PIN  D6
#define RGB1_BLUE_PIN   D7
#define RGB2_RED_PIN    D2
#define RGB2_GREEN_PIN  D3
#define RGB2_BLUE_PIN   D4

void setup() {
  AH_DEBUG_INIT();

  Runtime::setName("Guirlande");

  Runtime::registerService(new DispatcherService());
  Runtime::registerService(new ConfigurationService());
  Runtime::registerService(new WifiSetupService(CONFIG_PIN));
  Runtime::registerService(new HttpService());
  Runtime::registerService(new InfoService());
  Runtime::registerService(new RGBService(RGB1_RED_PIN, RGB1_GREEN_PIN, RGB1_BLUE_PIN, "rgb1"));
  Runtime::registerService(new RGBService(RGB2_RED_PIN, RGB2_GREEN_PIN, RGB2_BLUE_PIN, "rgb2"));
  
  Runtime::setup();
}

void loop() {
  Runtime::loop();
}

