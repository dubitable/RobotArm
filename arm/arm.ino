#include <Servo.h>

int pins[6] = {3,5,6,9,10,11};
//

void setup() {
  // put your setup code here, to run once:
  Servo servo;
  servo.attach(3);
  servo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
