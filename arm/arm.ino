#include <Servo.h>

int pins[6] = {3,5,6,9,10,11};
Servo servo1;
//

void full_rotation() {
  //do a full counter-clockwise rotation
  servo1.write(0);
  delay(1000);
  servo1.write(90);
  delay(1000);
  servo1.write(180);
  delay(1000);
}
void setup() {
  // put your setup code here, to run once:
  servo1.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  full_rotation();
}
