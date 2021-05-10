#include <Servo.h>
Servo myServo;
int servoPin = 52;
int servoPosition = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  myServo.write(servoPosition);
}
