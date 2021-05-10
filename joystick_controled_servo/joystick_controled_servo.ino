#include <Servo.h>
Servo myServo;
int servoPin = 52;
int servoPosition;
int XPin = A0;
int XVal;
int YPin = A1;
int YVal;
int SPin = 53;
int SVal;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(XPin,INPUT);
  pinMode(YPin,INPUT);
  pinMode(SPin,INPUT);
  pinMode(13,OUTPUT);
  myServo.attach(servoPin);
  digitalWrite(SPin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  XVal = analogRead(XPin);
  YVal = analogRead(YPin);
  SVal = digitalRead(SPin);
  delay(100);
  Serial.print("X: ");
  Serial.print(XVal);
  Serial.print(" Y: ");
  Serial.print(YVal);
  Serial.print(" Button: ");
  Serial.println(SVal);


  servoPosition = (180./1023.)*(XVal+YVal);
  Serial.println(servoPosition);
  if(SVal == 0){
    digitalWrite(13,HIGH);
  }
  if(SVal == 1){
    digitalWrite(13,LOW);
  }
  myServo.write(servoPosition);
}
