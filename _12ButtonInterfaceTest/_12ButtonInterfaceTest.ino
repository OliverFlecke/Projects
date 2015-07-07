void setup() {
  // put your setup code here, to run once:
  for(int i = 1; i <= 7; i++){
    pinMode(i, INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  for(int i = 1; i <= 7; i++) {
    if( digitalRead(i) == LOW)
    {
      Serial.println("Hey, I'm HIGH!" + 1);
    } 
  } 
}
