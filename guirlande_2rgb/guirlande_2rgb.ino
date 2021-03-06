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

  Runtime::setName("ard-home");

  Runtime::registerService(new DispatcherService());
  Runtime::registerService(new ConfigurationService());
  Runtime::registerService(new WifiNetworkService());
  Runtime::registerService(new WifiSetupService(CONFIG_PIN));
  Runtime::registerService(new HttpService());
  Runtime::registerService(new IrcService(nullptr, "#arduino-home", "rpi2-devel.mti-team2.dyndns.org")); // hub-irc.home.mti-team2.dyndns.org
  Runtime::registerService(new InfoService());
  Runtime::registerService(new RGBService(RGB1_RED_PIN, RGB1_GREEN_PIN, RGB1_BLUE_PIN, "rgb1"));
  Runtime::registerService(new RGBService(RGB2_RED_PIN, RGB2_GREEN_PIN, RGB2_BLUE_PIN, "rgb2"));
  
  Runtime::setup();
}

void loop() {
  Runtime::loop();
}

