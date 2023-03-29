/*
  Servo Motor Controller Demo for PlatformIO
  servo-control-demo.cpp
  Controls 2 servo motors, uses PCA9685 PWM Controller
  Displays status on 16x2 LCD
  Uses LiquidCrystal PCF8574 LCD Library
  Uses Adafruit PWM library
  Uses 2 potentiometers
  Uses I2C LCD Display

  DroneBot Workshop 2021
  https://dronebotworkshop.com
*/

// Include Arduino framework
#include <Arduino.h>

// Include PCF8574 Library for I2C LCD
#include <LiquidCrystal_PCF8574.h>

// Include Wire Library for I2C Communications
#include <Wire.h>

// Include Adafruit PWM Library
#include <Adafruit_PWMServoDriver.h>
 
// Define I2C Address - change if required
//const int i2c_addr = 0x3F;
const int i2c_addr = 0x27;

// Define LCD object
LiquidCrystal_PCF8574 lcd(i2c_addr); 

// PWM Parameter Definitions
#define MIN_PULSE_WIDTH       650
#define MAX_PULSE_WIDTH       2350
#define FREQUENCY             50

// Define PWM object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Define Potentiometer Inputs
int control0 = A0;
int control1 = A1;

// Define Motor Outputs on PCA9685 board
int motor0 = 0;
int motor1 = 1;

// Define Motor position variables
int mtrDegree0;
int mtrDegree1;

// Define Motor previous position variables
int mtrPrevDegree0 = 0;
int mtrPrevDegree1 = 0;

// Variable to determine if display needs updating
boolean updatedisplay = 0;


// Function to move motor to specific position
void moveMotorDeg(int moveDegree, int motorOut)
{
  int pulse_wide, pulse_width;

  // Convert to pulse width
  pulse_wide = map(moveDegree, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  
  //Control Motor
  pwm.setPWM(motorOut, 0, pulse_width);
}

// Function to convert potentiometer position into servo angle
int getDegree(int controlIn)
{
  int potVal,srvDegree;
  
  // Read values from potentiometer
  potVal = analogRead(controlIn);
  
  // Calculate angle in degrees
  srvDegree = map(potVal, 0, 1023, 0, 180);
  
  // Return angle in degrees
  return srvDegree;
  
}

void setup() 
{
  // Setup PWM Controller object
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  
  // Set display type as 16 char, 2 rows
  lcd.begin(16,2); 

  //Turn on the LCD Backlight
   lcd.setBacklight(255);

   // Clear the display
   lcd.clear();
   lcd.home();

   // Print on first row of LCD
  lcd.setCursor(0,0);
  lcd.print("Servo 0: 0");
  
  // Print on second row of LCD
  lcd.setCursor(0,1);
  lcd.print("Servo 1: 0");
  
  // Start Serial Monitor                                                 
  Serial.begin(19200);  
  
}

void loop() {
 
  //Control Servo Motor 0
  
  // Get desired position
  mtrDegree0 = getDegree(control0);

  // Move motor only if control position has changed
  if (mtrDegree0 != mtrPrevDegree0) {
    // Move motor
    moveMotorDeg(mtrDegree0,motor0);
    // Update motor moved variable
    updatedisplay = 1;
    // Update previous position
    mtrPrevDegree0 = mtrDegree0;
  }

  //Control Servo Motor 1
    
  // Get desired position
  mtrDegree1 = getDegree(control1);
  
  // Move motor only if control position has changed
  if (mtrDegree1 != mtrPrevDegree1){
    // Move motor
    moveMotorDeg(mtrDegree1,motor1);
    // Update motor moved variable
    updatedisplay = 1;
    // Update previous position
    mtrPrevDegree1 = mtrDegree1;
  }

  // Update display if required
  if (updatedisplay == 1) {
    
    // Clear the display
   lcd.clear();
   lcd.home();
    
    // Print on first row of LCD
    lcd.setCursor(0,0);
    lcd.print("Servo 0: ");
    lcd.print(mtrDegree0);
    
    // Print on second row of LCD
    lcd.setCursor(0,1);
    lcd.print("Servo 1: ");
    lcd.print(mtrDegree1);

  }

  // Print to Serial Monitor   
  Serial.print("Motor 0: "); 
  Serial.print(mtrDegree0);
  Serial.print("\t");
  Serial.print("Motor 1: "); 
  Serial.println(mtrDegree1);
 
  // Reset the motor moved variable
  updatedisplay = 0;
  
  // Add short delay
  delay(100);

}