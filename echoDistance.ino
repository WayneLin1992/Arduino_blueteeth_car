#define trigPIN 13
#define echoPIN 12
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPIN, OUTPUT);
  pinMode(echoPIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(trigPIN,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPIN,LOW);
  duration = pulseIn(echoPIN, HIGH);
  distance = (duration/2)/29.1;
  if(distance >= 200 || distance <= 0)
    Serial.println("out of range");
  else{
    Serial.print(distance);
    Serial.println(" cm");
  delay(500);
  }
}
