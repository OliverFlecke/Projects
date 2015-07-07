#include <VirtualWire.h>
/*
*  Project to get a 433 MHz transiver and reciver kit to 
*  communicate with each other on one Arduino Uno
*/

char *controller;

// Defining tx and rx pins
int TxPin = 9;
int RxPin = 12;
int ledPin = 13;

// Setup
void setup() {
   Serial.begin(9600);
   pinMode(TxPin, OUTPUT);
   pinMode(ledPin, OUTPUT);
   
   vw_set_ptt_inverted(true); // Required for DR3100 ???
   
   // Setting tx and rx pins 
   vw_set_tx_pin(TxPin);
   vw_set_rx_pin(RxPin);
   vw_setup(4000); // speed of data transfer Kbps
   
   vw_rx_start();
}

void loop() {
  TxMessageOn();
  RxMessage();
  delay(2000);
  TxMessageOff();
  RxMessage();
  delay(2000);
}

// Transmitter code for turning on the LED
void TxMessageOn(){
   controller="1" ;
   vw_send((uint8_t *)controller, strlen(controller));
   vw_wait_tx(); // Wait until the whole message is gone
   //digitalWrite(TxPin, 1);
   //delay(2000);
}

// Transmitter code for turning the LED off
void TxMessageOff(){
   controller = "0";
   vw_send((uint8_t *)controller, strlen(controller));
   vw_wait_tx(); // Wait until the whole message is gone
   //digitalWrite(13,0);
   //delay(2000);
}

// Receiver code
void RxMessage(){ 
     
   uint8_t buf[VW_MAX_MESSAGE_LEN];
   uint8_t buflen = VW_MAX_MESSAGE_LEN;

   if (vw_get_message(buf, &buflen)) // Non-blocking
   {
     // If the message is one, turn on LED
     if(buf[0]=='1')
     {  
        digitalWrite(ledPin, HIGH);
        Serial.println("Recived: HIGH");
     }  
     if(buf[0]=='0')
     {
        digitalWrite(ledPin, LOW);
        Serial.println("Recived: LOW");
     }
   }
}
