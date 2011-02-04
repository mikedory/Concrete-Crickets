/*
Concrete Crickets Arduino Code
 Michael J. Dory
 www.doryexmachina.com
 Written 04.11.07, revised 11.02.07 
 (thanks to code from Tom Igoe, Clay Shirky and Rob Faludi)
 */

#include "WProgram.h"
void setup();
void loop();
void blinky();
int RangePotPin = 5;    // Analog input pin that the rangefinder is attached to
int RangePotValue = 0;   // value read from the pot

int MP3Pin = 12;    // the pin that the relay controlling the MP3 is attached to 

int blinkyPin = 13; // the pin that the reference LED is attached to

int onOffPin = 11; //the pin that the speaker attach/kill switch relay is on.

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 

  // set pins for output
  pinMode(blinkyPin, OUTPUT);
  pinMode(onOffPin, OUTPUT);
  pinMode(MP3Pin, OUTPUT);

  // initialize both pins at low
  digitalWrite(MP3Pin, LOW);
  digitalWrite(blinkyPin, LOW);

  delay(100);

  // turn MP3 Player on, blink pin 13 for reference
  digitalWrite(MP3Pin, HIGH);
  digitalWrite(blinkyPin, HIGH);
  delay(5000);

  // take both pins low again 
  digitalWrite(MP3Pin, LOW);
  digitalWrite(blinkyPin, LOW);

  delay(100);

  // blink LED three times quickly to show mp3 player is on
  blinky();

  // start playing the MP3
  delay (2000);
  digitalWrite(MP3Pin, HIGH);
  digitalWrite(blinkyPin, HIGH);
  delay(500);
  digitalWrite(MP3Pin, LOW);
  digitalWrite(blinkyPin, LOW);

  // blink three times to show that the MP3 player is playing and setup is complete
  blinky();

  // end setup
}


void loop() {
  RangePotValue = analogRead(RangePotPin);   // read the pot value
  Serial.println(RangePotValue);             // print the rangefinder value back to the debugger pane
  delay(10);                                 // wait 10 milliseconds before the next loop



  if(RangePotValue <= 125) {                // if the rangefinder detects something in range
    digitalWrite(blinkyPin, HIGH);          // turn the light on
    digitalWrite(onOffPin, LOW);            // turn the speakers off
    Serial.println("detected");             // print "detected"

    delay(100);
  } 
  else {
    digitalWrite(blinkyPin, LOW);          // if the rangefinder doesn't detect anything
    digitalWrite(onOffPin, HIGH);          // leave the speakers connected
    Serial.println("not detected");        // print "not detected"
  } 

}

void blinky() {
  int i;
  int blinks = 0;

  for (i=0;i<=blinks;i++) {
    digitalWrite(blinkyPin, HIGH);
    delay(500);
    digitalWrite(blinkyPin, LOW);
    delay(500);
  }
}

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

