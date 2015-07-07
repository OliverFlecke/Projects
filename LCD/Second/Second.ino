//The code:
#include <LiquidCrystal.h>

#define SCROLL_DELAY 100

// Create display
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int readkey;

/*
  Setup the LCD display
*/
void setup() 
{
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Hello World!");
}

/*
  Display data to the display and register keypresses
*/
void loop() 
{
  lcd.setCursor(0, 0);
  lcd.print("Hello World!"); 
  
  lcd.setCursor(13, 0);
  lcd.print(millis()/1000);
  
  readkey = analogRead(0);
  lcd.setCursor(0, 1);
  lcd.print(readkey); 
  
  if (readkey != 1023) 
  {
    //delay(100);
    //lcd.clear();
  }
  
  // Register the different keys
  lcd.setCursor(6, 1);
  if (readkey >= 630 && readkey <= 650)
  {
    lcd.print("Select");
  }
  else if (readkey == 409) 
  {
    lcd.print("Left");
    lcd.scrollDisplayLeft();
    delay(SCROLL_DELAY);
  }
  else if (readkey == 101) 
  {
    lcd.print("Up");
  }
  else if (readkey == 0) 
  {
    lcd.print("Right");
    lcd.scrollDisplayRight();
    delay(SCROLL_DELAY);    
  }
  else if (readkey == 256) 
  {
    lcd.print("Down");
  }
}
