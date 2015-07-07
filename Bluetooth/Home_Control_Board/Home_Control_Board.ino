#include <SoftwareSerial.h>  

// Transmitter and reciever pins 
int txPin = 11;
int rxPin = 10;

int ledPin = 13; 

// Create a softwareSerial class
SoftwareSerial connection(rxPin, txPin);

// Data from the PC
int bluetooth_data; 


// Data storage for hex colors. Apperently, it needs to be four spaces, even through I'm only useing three of them. 
int RBG_data[3];
// The number zero (0) in char value
const int zero = 48;

int current_color;




void setup(){
  Serial.begin(115200);
  connection.begin(115200);
  connection.println("Bluetooth On");
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  ledpin_control();
  /*
  current_color = recieve_hex();
  if (current_color > 0 && current_color <= 255) {
    Serial.println(current_color); 
  }
  */
}

int recieve_hex(){
  int num_of_bytes = 0;
  
  if (connection.available()) {
    num_of_bytes = connection.read();
  } 
  
  if (num_of_bytes == 0) {
    return 0; 
  }
  int data_recieved[num_of_bytes];
  
  data_recieved[0] = -1;
  
  int count = 0;
  while (count < num_of_bytes) {
    if (connection.available()) {
      data_recieved[count] = connection.read();
      //Serial.println(data_recieved[count]);
      
      count++;
      //delay(1);
    } 
  }
  
  return convert_string_to_number(data_recieved);
}  

/*
*  Converts a 3 int array into an hex number
 */
int convert_string_to_number(int array_of_numbers[]) {
  //Serial.println("First value: " + array_of_numbers[0]);
  int length_of_array = sizeof(array_of_numbers) / sizeof(int);
  //Serial.println(length_of_array);
  int number = 0;
  
  for (int i = 0; i < length_of_array; i++) {
    // The current number is multiplied by ten, and the next number is added. 
    number = (number * 10) + (array_of_numbers[i] - zero);
  }
  return number;
}



/*
 *  Methode used to recieve strings
 */
String recieve_String() {
  String data = "";
  char current_data;

  while (current_data != 'E') {
    if (connection.available() > 0) {
      data += current_data;
      current_data = connection.read();
    }
    delay(10);
  }

  return data;
}

/*
 *  Methode for recieving hex colors. The methodes use the RBG_data array to store the numbers.
 *  Used with BT terminal on WP8
 */
void recieve_RBG() {
  int recieve_count = 0;
  int temp_storage[3];

  // To recive three numbers
  while(recieve_count < 3) {
    if (connection.available()) {
      // Code to convert 3 recieved numbers in to one
      int temp_count = 0;

      while (temp_count < 3) {
        if (connection.available()) {
          temp_storage[temp_count] = connection.read();
          Serial.println(temp_storage[temp_count]);

          temp_count++;

          // Same as below, have to discard to commands
          connection.read();
          connection.read();
        }
        delay(1);
      }
      //Serial.println("Recieved number:");
      //Serial.println(convert_string_to_number(temp_storage));

      // Put the data int the array 
      RBG_data[recieve_count] = convert_string_to_number(temp_storage);    
      Serial.println(RBG_data[recieve_count]); 
      recieve_count++; 

      // Each time I send a message, it is followed by a 10 and a 13. Send from WP8. 
      // This solves the problem, by discarding the to following reads. 
      connection.read();
      connection.read();
    }
    delay(1);
  }
}

/*
*  Test program. Able to turn the diode on pin 13 on and off, by sending 1 or 0, or L and l
 */
void ledpin_control() { 
  if (connection.available()) {
    bluetooth_data = connection.read();

    // If the data recieved is 1, turn on the LED
    if (bluetooth_data == '1' || bluetooth_data == 'L') {
      digitalWrite(ledPin, HIGH);
      connection.println("LED on");
      Serial.println("LED on");
    }
    // If it is 0, turn the LED off
    else if (bluetooth_data == '0' || bluetooth_data == 'l') {
      digitalWrite(ledPin, LOW);
      connection.println("LED off");
      Serial.println("LED off");
    }
    /*
    if (bluetooth_data == 'L'){
      digitalWrite(ledPin, HIGH);
      connection.println("LED turned on");
    } 
    else if (bluetooth_data == 'l') {
      digitalWrite(ledPin, LOW);
      connection.println("LED turned off");
    }    
    */
  }  

  // Delay between each command 
  delay(100);
}

void test_connection() {
  if (connection.available()) {
    bluetooth_data = connection.read();
    connection.println("Command recieved");
    Serial.println(bluetooth_data);
  } 
  delay(1);
}


