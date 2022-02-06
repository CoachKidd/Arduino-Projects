/* 
Created 06 Feb 2022
 by Andrew Kidd
The settings needed to get the VSCode IDE to work with the Arduino IDE were:
"arduino.path": "/Applications"
"arduino.commandPath": "Contents/MacOS/Arduino"
*/
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}
// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second


// now loop the word in Morse code

// where / is a dash length pause between letters
// and // is 2 dash length pauses between words
// e.g. "I love you" becomes ..//.-../---/...-/.//-.--/---/..-//
// "Andrew" becomes : .-/-./-../.-././.--//

// Define the dictionary of letters (letter = str, morse code = str)
// Define time a pause as a dash (pause = int)
// Define time for a dot (dot = int)
// Define time for a dash (dash = int)
// Define string to hold input sentance (input = str)

// Programme ...

}