#include <Servo.h>

struct ServoWrapper{
  String name;
  int pin;
  Servo servo;
};

struct info{
  int direction;
  int net_degrees;
  int degrees;
  int currentDegrees;
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

int name_to_index(String name){
  for (int i = 0; i < SERVOS; i++){
    if (servos[i].name == name){
      return i;
    }
  }
  return -1;
}

struct info getInfo(struct ServoWrapper servo, int degrees){
  int currentDegrees = servo.servo.read();
  struct info movementInfo;
  movementInfo.degrees = degrees;
  movementInfo.currentDegrees = currentDegrees;
  if (degrees > currentDegrees){
    movementInfo.direction = 1;
    movementInfo.net_degrees = degrees - currentDegrees;
  }
  else if (currentDegrees > degrees){
    movementInfo.direction = -1;
    movementInfo.net_degrees = currentDegrees - degrees;
  }
  else{
    movementInfo.direction = 0;
    movementInfo.net_degrees = 0;
  }
  return movementInfo;
}

void gradual_write(struct ServoWrapper servo, int degrees, int delay_amt){
  struct info movementInfo = getInfo(servo, degrees);
  unsigned long inter_delay = (unsigned long) delay_amt / movementInfo.net_degrees;
  for (int i = movementInfo.currentDegrees + movementInfo.direction; i = degrees; i += movementInfo.direction){
    servo.servo.write(i);
    delay(inter_delay);
  }
  servo.servo.write(degrees);
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

void displayInfo(struct info movementInfo){
  Serial.println(movementInfo.direction);
  Serial.println(movementInfo.net_degrees);
  Serial.println(movementInfo.currentDegrees);
  Serial.println(movementInfo.degrees);
}

void setup() {
  Serial.begin(9600);
  initialize_servo_wrappers();
}

void loop() {
}
