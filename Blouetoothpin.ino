#include <SoftwareSerial.h>
SoftwareSerial mySerial(1, 2); // RX, TX

void setup() {
  mySerial.begin(9600);
}

void loop() {

   mySerial.print("test");
   mySerial.print("\n");

}
