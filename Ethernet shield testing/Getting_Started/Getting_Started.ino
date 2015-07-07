#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0x21, 0x10 };
byte ip[] = { 192, 168, 1, 77 };


EthernetClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // Set up ethernet connection with fixed IP and MAC
  Ethernet.begin(mac, ip);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello from Arduino Serial!");
}
