const int outPin = 4;
const int inPin = 7;

void setup(){
  Serial.begin(9600);
  
  pinMode(outPin, OUTPUT);
  pinMode(inPin, INPUT);  
}

void loop() {
  long  duration, cm;
  
  // Sends a signal on the output pin
  digitalWrite(outPin, LOW);
  delayMicroseconds(2);
  digitalWrite(outPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(outPin, LOW);
  
  // Listen for the signal 
  duration = pulseIn(inPin, HIGH);
  
  // Get the distance
  cm = microsecondsToCentimeters(duration);
  
  Serial.print("Distance in cm: ");
  Serial.print(cm);
  Serial.println();
  
  delay(100);
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
