int speedPin = 10;
int dir1 = 13;
int dir2 = 12;
int mSpeed = 225;
void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
  analogWrite(speedPin,mSpeed);
}
