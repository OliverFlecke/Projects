#include <VirtualWire.h>

byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message 

void setup()
{
  Serial.begin(9600);
  Serial.println("Device is ready");
  
  // Initialize the IO and ISR
  vw_setup(2000); // Bits per sec
  vw_rx_start();
}

void loop()
{
  send("Hello there");
  delay(1000);
  
  if (vw_get_message(message, &messageLength))
  {
    Serial.print("Recived: ");
    
    for (int i = 0; i < messageLength; i++)
    {
      Serial.write(message[i]);
    }
    
    Serial.println();
  }
}
  
void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}
