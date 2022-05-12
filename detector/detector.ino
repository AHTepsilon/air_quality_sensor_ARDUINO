#include <LiquidCrystal_I2C.h>
#include <MQ135.h>
#include <Wire.h>
// C++ code
//

#define LCDRS 12
#define LCDE 11

#define LCDDB0 7
#define LCDDB1 6
#define LCDDB2 5
#define LCDDB3 4
#define LCDDB4 3

#define CO2sensor A0

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
MQ135 gasSensor = MQ135(CO2sensor);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  lcd.begin(16, 2);
  
  Serial.begin(9600);
  
}

void loop()
{
  /*digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)*/

  float ppm = gasSensor.getPPM();
  float resultShow = ppm/10;

  Serial.println(resultShow);
  
  lcd.setCursor(00,00);
  lcd.print("NIVEL DE CO2");
  lcd.setCursor(00,01);
  lcd.print(resultShow);
  lcd.setCursor(05, 01);
  lcd.print("ppm");
  
  if(resultShow <= 800){
  
    lcd.setCursor(10, 01);
    lcd.print("LO CO2");
    
  }
  
  else if(resultShow > 800 && resultShow < 1200){
  
    lcd.setCursor(10, 01);
    lcd.print("MD CO2");
    
  }
  
  else if(resultShow >= 1200){
  
    lcd.setCursor(10, 01);
    lcd.print("HI CO2");
    
  }

  delay(300);
}
