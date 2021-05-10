#include <Stepper.h>
int stepsPerRevelution=2048;
int motSpeed =10;
int dt = 1000;
int bPin = 53;
int bVal;
int motDir = 1;
int newv;
int oldv = 1;
Stepper myStepper(stepsPerRevelution, 8,10,9,11); 
void setup() {
  // put your setup code here, to run once:
  myStepper.setSpeed(motSpeed);
  pinMode(bPin,INPUT);
  digitalWrite(bPin,HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  newv = digitalRead(bPin);
  if(oldv == 1 && newv == 0){
    motDir = motDir*(-1);
  }
  myStepper.step(motDir*1);
//  myStepper.step(stepsPerRevelution);
//  delay(dt);
//  myStepper.step(-stepsPerRevelution);
//  delay(dt);

}
