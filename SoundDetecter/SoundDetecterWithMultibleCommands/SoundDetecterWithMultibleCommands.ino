// Input pin for sound detector
int inputPin = A0;

// Storage for sensor value
int sensorValue = 0;

// Value to beat for the sensor to be on
int activeValue = 100;

// Time storage
int currentTime = 0;
int lastTime = 0;

/*
*  Make the program able to send data to the computer
 */
void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
}

void loop() {
  // Update lastTime
  updateLastTime();

  sensorValue = analogRead(inputPin);

  if (sensorValue > activeValue) {
    Serial.println("I heard you!");
    currentTime = millis();

    if (lastTime == 0) { 
      updateLastTime();
    }

    // Delay to filter extra noise away
    delay(1);    
  }

  compareTime();
}

/*
*  Updates the last time something was heard
 */
void updateLastTime() {
  lastTime = currentTime; 
}

/*
 *  Compares the time between the two last decteted sounds
 */
void compareTime() {
  int timeBetween = currentTime - lastTime;

  // Not so pretty with all the != 0
  if (timeBetween < 1000 && timeBetween != 0) {
    Serial.println("There was less then a second between those sounds!");
  } 
  else if (timeBetween < 2000 && timeBetween != 0) {
    Serial.println("There was between one or to seconds between those sounds!");
  } 
}








