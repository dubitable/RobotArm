#include <Servo.h>

struct ServoWrapper{
  String name;
  int pin;
  Servo servo;
};

const int SERVOS = 5;

ServoWrapper servos [SERVOS]; 
int pins [SERVOS] = {3,5,6,9,11};
String names [SERVOS] = {"Base", "Joint1", "Joint2", "Joint3", "Claw"};


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  /*
  // put your main code here, to run repeatedly:
  
  
  */
}
