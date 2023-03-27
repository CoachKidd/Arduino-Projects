#include <Arduino.h>

/*
  Simple Blink sketch
  simple-blink.cpp
  Use for PlatformIO demo

  From original Arduino Blink Sketch
  https://www.arduino.cc/en/Tutorial/Blink
  
  DroneBot Workshop 2021
  https://dronebotworkshop.com
*/

// Set LED_BUILTIN if undefined or not pin 13
#define LED_PIN 13

void blink_led(int LED, int delaytime)
{
  // Set output HIGH for specified time.
  digitalWrite(LED, HIGH);
  delay(delaytime);

  // Set output LOW for specified time.
  digitalWrite(LED,LOW);
  delay(delaytime);
}

void setup()
{
  // Initialize LED pin as an output.
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // Blink the LED at half-second interval six times.
  for (int i = 0;i < 6; i++) {
    blink_led(LED_PIN, 500);  
  }
  // Blink the LED at two-second interval three times.
  for (int i = 0;i < 3; i++) {
    blink_led(LED_PIN, 2000);  
  }
}