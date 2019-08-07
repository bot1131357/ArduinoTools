/*
 Name:		Example.ino
 Created:	8/7/2019 3:12:45 PM
 Author:	y.tan
*/

void foo() {
	Serial.print("foo: Time is: ");
	Serial.println(millis());
}

#include "ArduinoTools.h"
void setup() {
	Serial.begin(9600);
}


void loop() {
	// use static initialisation so that the variable persists between loops

	// using function ptr
	static AT::Tick tick_foo(&foo, 3000);
	tick_foo();

	// using lambda 
	static AT::Tick tick_lambda([]() {
		Serial.print("lambda: Time is: ");
		Serial.println(millis());
	}, 5000);
	tick_lambda();
}
