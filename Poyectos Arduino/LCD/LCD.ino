#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C pantalla(0x3F,16,2);
void setup() 
{
  Wire.begin();
  pantalla.begin(16,2);
  pantalla.clear();
  pantalla.backlight();
}

void loop() 
{
  pantalla.setCursor(0,0);
  pantalla.print("Hola Mundo"); 
}
