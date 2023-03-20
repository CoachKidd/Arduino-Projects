/*
Tutorial from https://docs.arduino.cc/hacking/software/LibraryTutorial
Created: 07 Feb 2022
By: Andrew Kidd

Creating my own library.
Starting with this monolithic code block.
*/
/*
int pin = 13;

void setup()
{
  pinMode(pin, OUTPUT);
}

void loop()
{
  dot(); dot(); dot();
  dash(); dash(); dash();
  dot(); dot(); dot();
  delay(3000);
}

void dot()
{
  digitalWrite(pin, HIGH);
  delay(250);
  digitalWrite(pin, LOW);
  delay(250);
}

void dash()
{
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(250);
}
*/

#include <Morse.h>

Morse morse(13);

void setup()
{
}

void loop()
{
  /* // SOS
  morse.dot(); morse.dot(); morse.dot();
  morse.dash(); morse.dash(); morse.dash();
  morse.dot(); morse.dot(); morse.dot();
  delay(3000);
  
  // "Andrew" becomes : .-/-./-../.-././.--//
  morse.dot(); morse.dash(); 
  morse.dash();morse.dot();
  morse.dash();morse.dot();morse.dot();
  morse.dot();morse.dash();morse.dot();
  morse.dot();
  morse.dot();morse.dash();morse.dash();
  delay(3000);

  */
  // "I love you" becomes ..//.-../---/...-/.//-.--/---/..-//
  
  morse.dot();morse.dot();
  delay(1000);
  morse.dot();morse.dash();morse.dot();morse.dot();
  morse.dash();morse.dash();morse.dash();
  morse.dot();morse.dot();morse.dot();morse.dash();
  morse.dot();
  delay(1000);
  morse.dash();morse.dot();morse.dash();morse.dash();
  morse.dash();morse.dash();morse.dash();
  morse.dot();morse.dot();morse.dash();
  delay(3000);
}