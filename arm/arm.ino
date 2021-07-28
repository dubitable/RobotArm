#include <Servo.h>

const int SERVOS = 5;
int pins [SERVOS] = {3,5,6,9,11};
String names [SERVOS] = {"Base", "Joint1", "Joint2", "Joint3", "Claw"};
Servo servos [SERVOS];

void rotation(int index, int amount){
  amount = index + amount;
  for (int i = index; i < amount; i++){
    servos[i].write(0);
  }
  delay(1000);
  for (int i = index; i < amount; i++){
    servos[i].write(left(&servos[i], 90));
  }
  delay(1000);
  for (int i = index; i < amount; i++){
    servos[i].write(left(&servos[i], 90));
  }
  delay(1000);
}


int left(Servo *servo, int degrees){
  return servo->read() + degrees;
}

int right(Servo *servo, int degrees){
  return servo->read() - degrees;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < SERVOS; i++){
    servos[i].attach(pins[i]);
  }
  rotation(0,  1);
}

void loop() {
  // put your main code here, to run repeatedly:
}
