
int redLed = 2;
int blueLed = 3;
int greenLed = 4;

int button1 = 9; //Icesi - 1360ppm
int button2 = 8; //San Buenaventura - 1471ppm
int button3 = 10; // Bochalema - 1190ppm
int button4 = 11; // Valle de Lili - 630ppm
int button5 = 12; // Andrés Sanín - 1352ppm
int button6 = 7; // Cuatro Esquinas - 1286ppm
int button12 = 6; //Chipichape - 611ppm
int button13 = 5; //Normandía - 828ppm

float co2Level = 0;
int button1state = 0;
int button2state = 0;
int button3state = 0;
int button4state = 0;
int button5state = 0;
int button6state = 0;
int button12state = 0;
int button13state = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  pinMode(button12, INPUT);
  pinMode(button13, INPUT);

  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println(co2Level);
  
  button1state = digitalRead(button1);
  button2state = digitalRead(button2);
  button3state = digitalRead(button3);
  button4state = digitalRead(button4);
  button5state = digitalRead(button5);
  button6state = digitalRead(button6);
  button12state = digitalRead(button12);
  button13state = digitalRead(button13);

  if(button1state == HIGH){
    button2state = 0;
    button3state = 0;
    button4state = 0;
    button5state = 0;
    button6state = 0;
    button12state = 0;
    button13state = 0;
    co2Level = 1360;
    Serial.write((int)co2Level);
  }

  else if(button2state == HIGH){
    button1state = 0;
    button3state = 0;
    button4state = 0;
    button5state = 0;
    button6state = 0;
    button12state = 0;
    button13state = 0;
    co2Level = 1471;
    Serial.write((int)co2Level);
  }

  else if(button3state == HIGH){
    button1state = 0;
    button2state = 0;
    button4state = 0;
    button5state = 0;
    button6state = 0;
    button12state = 0;
    button13state = 0;
    co2Level = 1190;
    Serial.write((int)co2Level);
  }

  else if(button4state == HIGH){
    button1state = 0;
    button3state = 0;
    button2state = 0;
    button5state = 0;
    button6state = 0;
    button12state = 0;
    button13state = 0;
    co2Level = 630;
    Serial.write((int)co2Level);
  }

  else if(button5state == HIGH){
    button1state = 0;
    button3state = 0;
    button2state = 0;
    button4state = 0;
    button6state = 0;
    button12state = 0;
    button13state = 0;
    co2Level = 1352;
    Serial.write((int)co2Level);
  }

  else if(button6state == HIGH){
    button1state = 0;
    button3state = 0;
    button2state = 0;
    button4state = 0;
    button5state = 0;
    button12state = 0;
    button13state = 0;
    co2Level = 1286;
    Serial.write((int)co2Level);
  }

  else if(button12state == HIGH){
    button1state = 0;
    button3state = 0;
    button2state = 0;
    button4state = 0;
    button5state = 0;
    button6state = 0;
    button13state = 0;
    co2Level = 611;
  }

  else if(button13state == HIGH){
    button1state = 0;
    button3state = 0;
    button2state = 0;
    button4state = 0;
    button5state = 0;
    button6state = 0;
    button12state = 0;
    co2Level = 828;
  }
    Serial.println(co2Level);
  delay(300);

    /*if(co2Level <400){
      displayColor(0, 0, 255);
      //startPlayback(level1, sizeof(level1));
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
    displayColor(255, 0, 255);
    delay(500); 
    displayColor(0, 0, 0);
    delay(500);
  }
  delay(300);
}*/

displayColor(255, 0, 0);
}
  
void displayColor(int r, int g, int b){

  digitalWrite(redLed, r);
  digitalWrite(greenLed, g);
  digitalWrite(blueLed, b);

}
