#include <SoftwareSerial.h>  

// Transmitter and reciever pins 
int txPin = 11;
int rxPin = 10;

int ledPin = 13; 

// Create a softwareSerial class
SoftwareSerial connection(rxPin, txPin);

// Data from the PC
int bluetoothData; 

void setup(){
   connection.begin(115200);
   connection.println("Bluetooth On. Pres 1 or 0 to control LED");
   pinMode(ledPin, OUTPUT);
   digitalWrite(ledPin, LOW);
}

void loop() { 
   if (connection.available()) {
     bluetoothData = connection.read();
     
     // If the data recieved is 1, turn on the LED
     if (bluetoothData == '1') {
       digitalWrite(ledPin, HIGH);
       connection.println("LED on");
     }
     
     // If it is 0, turn the LED off
     if (bluetoothData == '0') {
       digitalWrite(ledPin, LOW);
       connection.println("LED off");
     }
     
     if (bluetoothData == 'L'){
       digitalWrite(ledPin, HIGH);
       connection.println("LED turned on");
     } else if (bluetoothData == 'l') {
       digitalWrite(ledPin, LOW);
       connection.println("LED turned off");
     }    
   }  
 
   // Delay between each command 
   delay(100);
}
