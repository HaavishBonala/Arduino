int tiltPin = 11;
int tiltVal;
int gPin = 52;
int rPin = 53;
void setup() {
  // put your setup code here, to run once:
  pinMode(gPin,OUTPUT);
  pinMode(rPin,OUTPUT);
  pinMode(tiltPin,INPUT);
  digitalWrite(tiltPin,HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltVal=digitalRead(tiltPin);
  Serial.println(tiltVal);
  if(tiltVal==0){
    digitalWrite(rPin,LOW);
    digitalWrite(gPin,HIGH);
  }
  if(tiltVal==1){
    digitalWrite(gPin,LOW);
    digitalWrite(rPin,HIGH);
  }
}
