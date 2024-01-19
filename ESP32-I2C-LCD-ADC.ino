#include <LiquidCrystal_I2C.h>
// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;
// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6) 
const int potPin = 34;
// variable for storing the potentiometer value
int potValue = 0;
// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
//define sound speed in cm/uS
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  
void setup(){
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  Serial.begin(115200); // Starts the serial communication
   delay(1000);
}
void loop(){
  potValue = analogRead(potPin);
  Serial.print("ADC Value :");
  Serial.println(potValue);
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("ADC Value: ");
  lcd.setCursor(0,1);
  lcd.print(potValue);
  lcd.print("");
  delay(1000);
  lcd.clear();   
}
