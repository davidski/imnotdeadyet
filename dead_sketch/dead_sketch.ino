/*
  I'm Not Dead Yet (INDY)

 When a pushButton on pin 2 is pressed, execute the sendmail script
 on the Linio python side. Check for response and light the 
 proper response LED. Wait for the reset button before retriggering.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2015
 by David F. Severski
 https://github.com/davidski/imnotdeadyet
 modified 27 Oct 2015

 */

// constants won't change. They're used here to
// set pin numbers:
const int sendButtonPin = 2;     // the number of the pushbutton pin
const int resetButtonPin = 3;
const int goodLedPin =  13;  // the number of the good send LED pin
const int badLedPin =  13;   // the number of the bad send LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int mailTriggered = 0;			 // 

void setup() {
  // initialize the success LED pin as an output:
  pinMode(goodLedPin, OUTPUT);
  // initialize the failure LED pin as an output:
  pinMode(badLedPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  sendButtonState = digitalRead(sendButtonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (sendButtonState == HIGH) {
		mailTriggered = 1;
		//execute process
		//wait for process to finish
		//check status
		if (p.return == "success") {
	    // turn LED on:
  	  digitalWrite(goodLedPin, HIGH);
    } else {
			digitalWrite(badLedPin, HIGH);
		}
  }

	resetButtonState = digitalRead(resetButtonPin);

	if (reseButtonState == HIGH) {
		mailTriggered = 0;
		digitalWrite(badLedPin, LOW);
		digitalWrite(goodLedPin, LOW);
  }


}