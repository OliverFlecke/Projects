
int led = 13;

void setup() {
  pinMode(led, OUTPUT);
}

void loop(){
  digitalWrite(led, HIGH); // Set the pin to high
  delay(1000);    // Wait a second 
  digitalWrite(led, LOW);
  delay(1000);
}
