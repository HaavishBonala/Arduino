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

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  HT.begin();
  delay(dt);
}

void loop() {
  // put your main code here, to run repeatedly:
  a=sr04.Distance();
  int tempReading = analogRead(ThermistorPin);
  // This is OK
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  int tempCC = tempK - 273.15;            // Convert Kelvin to Celcius
  int tempFF = (tempCC * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
  humidity=HT.readHumidity();
  tempC=HT.readTemperature();
  lcd.print("TempC:");
  lcd.print(" P:");
  lcd.print(tempCC);
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
