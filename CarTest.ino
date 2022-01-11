#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX HC-06wrong pin in device

char Incoming_value = 0;

#define trigPIN 13
#define echoPIN 12

long echoDistance(void){
  long duration, distance;
  digitalWrite(trigPIN,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPIN,LOW);
  duration = pulseIn(echoPIN, HIGH);
  distance = (duration/2)/29.1;
  Serial.println(distance);
  delay(500);
  return distance;
}

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(trigPIN, OUTPUT);
  pinMode(echoPIN, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  long distance = echoDistance();
  if(mySerial.available()>0){
    Incoming_value = mySerial.read();
      long distance = echoDistance();
        if(Incoming_value ==  'f'){
          if(distance>10){ 
            digitalWrite(5, HIGH);
            digitalWrite(6, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            delay(800);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
          }
        }
        else if(Incoming_value ==  'b'){
          digitalWrite(6, HIGH);
          digitalWrite(5, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, HIGH);
          delay(800);
          digitalWrite(5, LOW);
          digitalWrite(6, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
        }
        else if(Incoming_value ==  'l'){
          digitalWrite(5, HIGH);
          digitalWrite(6, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, HIGH);
          delay(200);
          digitalWrite(5, LOW);
          digitalWrite(6, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
        }
        else if(Incoming_value ==  'r'){
          digitalWrite(6, HIGH);
          digitalWrite(5, LOW);
          digitalWrite(9, HIGH);
          digitalWrite(10,LOW);
          delay(200);
          digitalWrite(5, LOW);
          digitalWrite(6, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
        }      
        else{
        Serial.println("too clear");
        }
  }
}
