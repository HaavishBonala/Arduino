#include <SR04.h>
#define TRIG_PIN 29
#define ECHO_PIN 5
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
#include <DHT.h>
#include <LiquidCrystal.h>
#define Type DHT11
int dt = 500;
int sensePin = 2;
DHT HT(sensePin,Type);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
float humidity;
float tempC;
float tempF;
int ThermistorPin = A0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tf;
int Tc;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  HT.begin();
  delay(dt);
}

void loop() {
  // put your main code here, to run repeatedly:
  a=sr04.Distance();
  Vo=analogRead(ThermistorPin);
  R2=R1 * (1023.0 / (float)Vo - 1.0);
  logR2=log(R2);
  T=(1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc=T - 273.15;
  Tf=(Tc * 9.0)/ 5.0 + 32.0; 
  Tc=(Tc - 32) * 5/9 -2;
  humidity=HT.readHumidity();
  tempC=HT.readTemperature();
  lcd.print("TempC:");
  lcd.print(" B:");
  lcd.print(Tc);
  //lcd.print("C");
  lcd.print(" O:");
  lcd.print(tempC);
  //lcd.print("C");
  
  lcd.setCursor(0, 1);
  
  lcd.print("Distance: ");
  lcd.print(a);
  lcd.print(" CM");
  delay(500);
  lcd.clear();                                                                                                       
}
