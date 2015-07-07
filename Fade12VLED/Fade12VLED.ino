/*
 *  This LED strip is powered on one pin with 12V (called common anode),
 *  which means, that the specifik color is powered, when the value of the pin is zero (ground). 
 *  To dime one color, use analogWrite to 255 minus the hex value for that color. 
 *  Eg. if you want green to be at hex 55, you need to say 255 - 55 = 200
 */

// Defining the pins. These are used, because they have PWM
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

int delayTime = 100;

/*
  Used in another projekt to control the brightness. Could be reused 
  */
/*
chosen LED SparkFun sku: COM-09264
 has Max Luminosity (RGB): (2800, 6500, 1200)mcd
 so we normalize them all to 1200 mcd -
 R  250/600  =  107/256
 G  250/950  =   67/256
 B  250/250  =  256/256
 */
// For maksimum brightness
//long bright[3] = { 107, 67, 256};
 

int dRed = 10; 
int dBlue = 5;
// Variebles for the colors. Turn off as default 
int red = 255;
int blue = 0;
int green = 0;

const int off = 255;

// Just define everything as output
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);

  if (red >= 255) {
    red = 0;
  }
  
  if (blue >= 255) {
    blue = 0; 
  }
  
  if (green >= 255) {
    green = 0;
  }

//  analogWrite(redPin, off);
//  delay(100);
//  analogWrite(greenPin, off);
//  delay(100);
//  analogWrite(bluePin, off);
//  delay(100);
}


