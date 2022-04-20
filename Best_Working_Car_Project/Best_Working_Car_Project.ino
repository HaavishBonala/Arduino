#include <IRremote.h>

int lm=9;//pin 9 of arduino to pin 7 of l293d
int lmr=8;//pin 8 of arduino to pin 2 of l293d 
int rm=10;//pin 10 of arduino to pin 10 of l293d
int rmr=11;//pin 11 of arduino to pin 15 of l293d

int RECV_PIN = 3;//pin 6 of arduino to data pin of ir receiver
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode(lm,OUTPUT);
  pinMode(lmr,OUTPUT);
  pinMode(rm,OUTPUT);
  pinMode(rmr,OUTPUT);
  //Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))
    { 
     //Serial.println(results.value, HEX);
     irrecv.resume();
    }
   //to move front
    if(results.value==0x5E35659B)
    {
      //Serial.println("i am at front");
      digitalWrite(lm,LOW);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,LOW);
    }
    //to move back
    if(results.value==0x3C6C09C3)
    {
      //Serial.println("i am at back");
      digitalWrite(lm,HIGH);
      digitalWrite(lmr,LOW);
      digitalWrite(rm,LOW);
      digitalWrite(rmr,HIGH);
    }
    //to move left
     if(results.value==0x3BD830B7)
    {
      //Serial.println("i am at left");
      digitalWrite(lm,LOW);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,LOW);
      digitalWrite(rmr,HIGH);
    }
    //to move right
     if(results.value==0x9F4F514F)
    {
      //Serial.println("i am at right");
      digitalWrite(lm,HIGH);
      digitalWrite(lmr,LOW);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,LOW);
    }
    //to stop
    if(results.value==0xD0362DAD)
    {
      //Serial.println("i am stoping");
      digitalWrite(lm,HIGH);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,HIGH);
    }
}
