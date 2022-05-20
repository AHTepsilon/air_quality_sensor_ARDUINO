#include <LiquidCrystal_I2C.h>
#include <MQ135.h>
#include <Wire.h>
// C++ code

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int co2SensorData;
int redLed = 12;
int blueLed = 11;
int greenLed = 10;

int button1 = 7;
int button2 = 6;

int button1state = 0;
int button2state = 0;

float co2Level = 0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  lcd.begin(16, 2);

  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  
  Serial.begin(9600);
  
}

void loop()
{
  button1state = digitalRead(button1);
  button2state = digitalRead(button2);

  if(button1state == HIGH){
    button2state = 0;
    co2Level = 400;
  }

  else if(button2state == HIGH){
    button1state = 0;
    co2Level = 913;
  }
  
  lcd.setCursor(00,00);
  lcd.print("NIVEL DE CO2");
  lcd.setCursor(00,01);
  lcd.print(co2Level);
  lcd.setCursor(05, 01);
  lcd.print("ppm");
  
  if(co2Level <400){
      displayColor(0, 0, 255);
  }
 
  else if(co2Level >= 400 && co2Level < 600){
    displayColor(123, 0, 255);
  }

  else if(co2Level >= 600 && co2Level < 800){
     displayColor(170, 255, 0);
  }

  else if(co2Level >= 800 && co2Level < 1000){
    displayColor(255, 170, 0);
  }

  else if(co2Level >= 1000 && co2Level <= 1100){
    displayColor(100, 100, 0);
  }

  else if(co2Level >= 1100 && co2Level <1200){
    displayColor(255, 0, 0);
  }

  else if(co2Level >= 1200){
    displayColor(255, 0, 0);
    delay(500);
    displayColor(0, 0, 0);
    delay(500);
  }

  delay(300);
}

void displayColor(int r, int g, int b){

  digitalWrite(redLed, r);
  digitalWrite(greenLed, g);
  digitalWrite(blueLed, b);

}
