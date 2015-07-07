int y[] = {8, 12, 7, 10, 6, 0, 5};
int x[] = {11, 4, 3, 9, 1}; 

int numYLED = 7;
int numXLED = 5; 


void setup() {
  for (int i = 0; i < numYLED; i++){
    pinMode(y[i], OUTPUT);
  }
  
  for (int i = 0; i < numXLED; i++) {
    pinMode(x[i], OUTPUT);
  }

}

void loop() { 
  for (int i = 0; i < numYLED; i++){
    digitalWrite(y[i], HIGH);
  }
  
  for (int i = 0; i < numXLED; i++){
    digitalWrite(x[i], HIGH);
  }
}
