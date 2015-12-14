//#define F_TEST
#define USE_OCTOWS2811    // Important! make fastLED use octoWS2811
#include <AccelStepper.h>
#include <OctoWS2811.h>
#include <FastLED.h>
#include <ArduinoJson.h>
#include <espduino.h>
#include <mqtt.h>


#include "PS_Settings.h"
#include "PS_Data.h"

#include "PS_Bulb.h"
#include "PS_Winch.h"
#include "PS_WifiController.h"
#include "PS_Animator.h"


// LED strip stuff
Bulb bulb;

// Stepper stuff
Winch winch;

// Wifi
WifiController wifi;

// 
Animator animator;

// timer
elapsedMillis sinceLast;
elapsedMillis sinceLastLedUpdate;
elapsedMillis sinceLastIsr;

// Create an IntervalTimer object 
IntervalTimer stepTimer;

void priorityTask() {
	winch.run();
	animator.run();

	if (sinceLastIsr > 1000)
	{
		sinceLastIsr = 0;
		DEBUG_PRINTLN(millis());
	}
}

void setup() {
	// put your setup code here, to run once:
	Serial1.begin(19200);
	Serial.begin(115200);
	
#ifdef F_TEST
	winch.begin();
	bulb.begin();
#else
	winch.begin();
	bulb.begin();
	//wifiInit();
	wifi.begin(true);
	animator.begin(&bulb, &winch, &wifi);
#endif
	sinceLastIsr = 0;
	stepTimer.begin(priorityTask, 1000);
}

void loop() {
	// put your main code here, to run repeatedly:
	//static  uint16_t count = 0;
	//static char msg[50];

#ifdef F_TEST
	delay(1);


	noInterrupts();
	winch.setTarget(-STEPPER_MIN);
	if (sinceLast >= 100) {
		sinceLast = 0; // sinceLast - 100;
		
		count += 33;
		if (count > 255)
			count = 0;
		bulb.setTarget(count);
	}
	interrupts();

#else
	
	// Handle esp comms
	wifi.process();
	//esp.process();

#endif
}
