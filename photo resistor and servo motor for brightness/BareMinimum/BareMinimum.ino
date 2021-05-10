#include <Servo.h>
Servo myServo;
int servoPin = 53;
int lightPin = A1;
int buzzPin = 3;
int lightVal;
int angle;
float l = 5.0;
float h = 150;
int d = 10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin,INPUT);
  pinMode(servoPin,OUTPUT);
  pinMode(buzzPin,OUTPUT);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  //myServo.write(servoPosition);
  //610 to 70
  angle = (-18./l)*lightVal+18.*h/l;
  myServo.write(angle);
  if(l*10+10>=lightVal){
    for(int i = 0 ; i<d ; i++){
      digitalWrite(buzzPin,HIGH);
      //delay(d);
      digitalWrite(buzzPin,LOW);
    }
  }
}
