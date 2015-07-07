/*
SimpleSend
This sketch transmits a short text message using the VirtualWire library
connect the Transmitter data pin to Arduino TxPin
*/
#include <VirtualWire.h>

// Pin to send data to the RF chip 
const int TxPin = 12;

void setup()
{
  Serial.begin(9600);

  // Initialize the IO and ISR
  vw_set_tx_pin(TxPin);
  vw_setup(2000); // Bits per sec
}

void loop()
{/*
  int count = 0;
  String inData;
  while (Serial.available() > 0 && count <= 20) {
    delay(10);
    char recieved = Serial.read();
    inData += recieved;
    
    Serial.print("Sending: ");
    Serial.println(inData);
    
    sendMessage(inData);
    count++;
  }
  sendMessage("Test message");*/
  char* msg = "HELLO";
  sendMessage(msg);
  delay(1000);
}

// Send the passed message through the RF chip
void sendMessage(char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}

