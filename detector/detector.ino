#include <LiquidCrystal.h>

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

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  /*pinMode(LCDRS, OUTPUT);
  pinMode(LCDE, OUTPUT);
  pinMode(LCDDB0, OUTPUT);
  pinMode(LCDDB1, OUTPUT);
  pinMode(LCDDB2, OUTPUT);
  pinMode(LCDDB3, OUTPUT);
  pinMode(LCDDB4, OUTPUT);*/
  
  lcd.begin(16, 2);
  
  Serial.begin(9600);
  
}

void loop()
{
  /*digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)*/
  
  int co2SensorData;
  co2SensorData = analogRead(CO2sensor);
  
  Serial.println(co2SensorData);
  
  lcd.setCursor(00,00);
  lcd.print("NIVEL DE CO2");
  lcd.setCursor(00,01);
  lcd.print(co2SensorData);
  
  if(co2SensorData <= 500){
  
    lcd.setCursor(06, 01);
    lcd.print("BAJ CO2");
    
  }
  
  else if(co2SensorData > 500 && co2SensorData < 700){
  
    lcd.setCursor(06, 01);
    lcd.print("MED CO2");
    
  }
  
  else if(co2SensorData >= 700){
  
    lcd.setCursor(06, 01);
    lcd.print("ALT CO2");
    
  }

  delay(300);
}
