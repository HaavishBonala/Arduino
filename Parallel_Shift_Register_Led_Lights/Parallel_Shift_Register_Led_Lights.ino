int latchPin = 11;
int clockPin = 9;
int pPin = A0;
float pVal;
int dataPin = 12;

byte leds;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(pPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pVal = analogRead(pPin);
  Serial.println(pVal);
  pVal = 1023./(pVal/8.);
  leds = (pVal/8);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,leds);
  digitalWrite(latchPin,HIGH);
}
