// Defines the analog input pin for the noise reciver
int inputPin = A0;

// Pin for the LED
int ledPin = 2;
// Varibel for sensor value
int sensorValue = 0;

void setup(){
 Serial.begin(9600);
 
 pinMode(ledPin, OUTPUT);
 // sets the analog input pin
 //pinMode(inputPin, INPUT); 
}

void loop() {
 // Turns the LED off
 digitalWrite(ledPin, LOW);  
  
 sensorValue = analogRead(inputPin);
 //Serial.println(sensorValue);
 //delay(100);  
 
 // If the sensorValue is above 100, turn on LED
  if (sensorValue > 100)
  {
    Serial.println(sensorValue);
    digitalWrite(ledPin, HIGH);
    delay(1000);
  }
}
