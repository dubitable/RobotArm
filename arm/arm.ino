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

int pin_to_index(int pin){
  for (int i = 0; i < SERVOS; i++){
    if (servos[i].pin == pin){
      return i;
    }
  }
  return -1;
}

void initialize_servo_wrappers(){
  for (int i = 0; i < SERVOS; i++){
    struct ServoWrapper servo_wrapper;

    servo_wrapper.name = names[i];
    servo_wrapper.pin = pins[i];

    Servo servo; servo.attach(pins[i]);
    servo_wrapper.servo = servo;

    servos[i] = servo_wrapper;
  }
}

void setup() {
  initialize_servo_wrappers();
}

void loop() {
}
