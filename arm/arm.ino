#include <Servo.h>

int ports[6] = {3,5,6,9,10,11};

const int NUM_SERVOS = 5;
Servo servos[NUM_SERVOS];

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < NUM_SERVOS; ++i){
    servos[i].attach(ports[i]);
  }
  servos[0].write(90);
}

void loop() {
  // put your main code here, to run repeatedly:

}
