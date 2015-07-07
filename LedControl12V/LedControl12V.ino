#include <RCSwitch.h>

// Pins for RGB output 
const int RED_PIN = 3;
const int GREEN_PIN = 5;
const int BLUE_PIN = 6;

// Variables for RGB output
int red = 100;
int green = 0;
int blue = 100;

// Change in RGB
int deltaRed = 0;
int deltaGreen = 0;
int deltaBlue = 0;

// Delay to make effects
int pulseDelay = 0;

// State to indikate if the lights should be on
bool lightOn = true;

// Variable for receiver
RCSwitch receiver = RCSwitch();

// Loop to setup pins and receiver
void setup() {
	Serial.begin(115200);
	receiver.enableReceive(0); // Pin 

	// Set output pin
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
	Serial.println("Ready to receive");
}

void loop() {
	receiveValue();
	updateRGB();
}

/*
*	Get and decode the received value
*/
void receiveValue() {
	if (receiver.available()) {
		int value = receiver.getReceivedValue();
		Serial.print(value);
		Serial.print(" - ");
		
		// Decode
		if (value > 0 && value < 1024) {
			// Get the value so it can be decoded
			value = value % 1024;

			if (value == 1) {
				red = 0;
				blue = 0;
				green = 0;
				deltaRed = 0;
				deltaGreen = 0;
				deltaBlue = 0;
				pulseDelay = 0;
			}

			// Switch lights on or off
			if (value == 10) {
				lightOn = false;
				Serial.print("Ligths off");
			}
			else if (value == 11) {
				lightOn = true;
				Serial.print("Lights on");
			}

			// Set everything to 100
			if (value == 100) {
				red = 100;
				green = 100;
				blue = 100;
			}

			// Set to purple
			if (value == 140) {
				red = 150;
				blue = 150;
				green = 0;
			}

			// Set the change in RGB
			if (value >= 170 && value < 180) {
				deltaRed = value % 10;
			}
			else if (value >= 180 && value < 190) {
				deltaGreen = value % 10;
			}
			else if (value >= 190 && value < 200) {
				deltaBlue = value % 10;
			}
			// Set pulse delay
			if (value >= 200 && value < 250) {
				pulseDelay = value % 50;
				Serial.print("Delay = ");
				Serial.print(pulseDelay);
			}

			// Set to white
			if (value == 255) {
				red = 255;
				blue = 255;
				green = 255;
			}

			// Update RGB values
			if (value >= 256 && value < 512) {
				red = value % 256;
				Serial.print("Red = ");
				Serial.print(red);
			}
			else if (value >= 512 && value < 768) {
				green = value % 256;
				Serial.print("Green = ");
				Serial.print(green);
			}
			else if (value >= 768 && value < 1024) {
				blue = value % 256;
				Serial.print("Blue = ");
				Serial.print(blue);
			}
		}
		Serial.println(" - end");
		receiver.resetAvailable();
	}
}

/*
*	Update the RGB values of the LED
*/
void updateRGB() {
	if (lightOn) {
		red += deltaRed;
		green += deltaGreen;
		blue += deltaBlue; 

		if (red <= 0 || red >= 255) {
			deltaRed *= -1;
			red += deltaRed;
		}
		if (green <= 0 || green >= 255) {
			deltaGreen *= -1;
			green += deltaGreen;
		} 
		if (blue <= 0 || blue >= 255) {
			deltaBlue *= -1;
			blue += deltaBlue;
		}

		analogWrite(RED_PIN, red);
		analogWrite(GREEN_PIN, green);
		analogWrite(BLUE_PIN, blue);

		//Serial.print("Red = ");
		//Serial.print(red);
		//Serial.print(", Green = ");
		//Serial.print(green);
		//Serial.print(", Blue = ");
		//Serial.println(blue);
		delay(pulseDelay);
	}
	else {
		analogWrite(RED_PIN, 0);
		analogWrite(GREEN_PIN, 0);
		analogWrite(BLUE_PIN, 0);
	}
}
