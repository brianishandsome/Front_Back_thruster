#include <Arduino.h>
#include <Servo.h>
#include <String.h> //three library added
/* 2 1
   4 3
*/
Servo thruster1, thruster2, thruster3, thruster4; // four thruster added to the library "Servo.h"

int Servodegrees = 1500; // the thruster don't move
int ServodegreesG = 1500; // the thruster don't move
int ServodegreesB = 1500; // the thruster don't move
int Thruster1speed, Thruster2speed, Thruster3speed, Thruster4speed; // 4 thruster speed
int thrusterpin1 = 10; 
int thrusterpin2;
int thrusterpin3;
int thrusterpin4;
constexpr uint16_t JOYSTICK_Y_UPPER_THRESHOLD = 920; // Joystick Y direction holding position
constexpr uint16_t JOYSTICK_Y_MID_UPPER_THRESHOLD = 520;
constexpr uint16_t JOYSTICK_Y_MID_LOWER_THRESHOLD = 460;
constexpr uint16_t JOYSTICK_Y_LOWER_THRESHOLD = 120;

constexpr uint16_t JOYSTICK_X_UPPER_THRESHOLD = 600; // Joystick X direction holding position
constexpr uint16_t JOYSTICK_X_MID_UPPER_THRESHOLD = 335;
constexpr uint16_t JOYSTICK_X_MID_LOWER_THRESHOLD = 320;
constexpr uint16_t JOYSTICK_X_LOWER_THRESHOLD = 73;
void thrusterinit(Servo thruster, int thrusterpin){
  thruster.attach(thrusterpin);
  thruster.writeMicroseconds(1500);
  delay(1000);
  thruster.writeMicroseconds(2000);
  delay(1000);
  thruster.writeMicroseconds(1500);
  delay(100);
} // initing the thruster, you should not chnage the init because all these kind of thruster should the same init
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  thrusterinit(thruster1, thrusterpin1);
  thrusterinit(thruster2, thrusterpin2);
  thrusterinit(thruster3, thrusterpin3);
  thrusterinit(thruster4, thrusterpin4); // setting up the thruster
  // fruster1.attach(frusterpin1);
  // fruster1.writeMicroseconds(1500);
  // delay(1000);
  // fruster1.writeMicroseconds(2000);
  // delay(1000);
  // fruster1.writeMicroseconds(1500);
  // delay(100);
}

void loop() {
  uint16_t joystickY = analogRead(A0); // reading the analog pin (A0)
  uint16_t joystickX = analogRead(A1); // reading the analog pin (A1)
  if(joystickY > JOYSTICK_Y_MID_UPPER_THRESHOLD){

  ServodegreesG = map(joystickY, JOYSTICK_Y_MID_UPPER_THRESHOLD, JOYSTICK_Y_UPPER_THRESHOLD, 1500, 2000);
  ServodegreesB = map(joystickY, JOYSTICK_Y_MID_UPPER_THRESHOLD, JOYSTICK_Y_UPPER_THRESHOLD, 1500, 1000);
  Thruster1speed = ServodegreesG;
  Thruster2speed = ServodegreesG;
  Thruster3speed = ServodegreesB;
  Thruster4speed = ServodegreesB;
  } //joystick mid upper position 520 
  else if(joystickY < JOYSTICK_Y_MID_LOWER_THRESHOLD){

  ServodegreesG = map(joystickY, JOYSTICK_Y_MID_LOWER_THRESHOLD, JOYSTICK_Y_LOWER_THRESHOLD, 1500, 1000);
  ServodegreesB = map(joystickY, JOYSTICK_Y_MID_LOWER_THRESHOLD, JOYSTICK_Y_LOWER_THRESHOLD, 1500, 2000);
  Thruster1speed = ServodegreesG;
  Thruster2speed = ServodegreesG;
  Thruster3speed = ServodegreesB;
  Thruster4speed = ServodegreesB;
  } // joystick mid lower position 460
  else{
    Servodegrees = 1500;
    ServodegreesG = 1500;
    ServodegreesB = 1500;

  }
  thruster1.writeMicroseconds(Thruster1speed);
  thruster2.writeMicroseconds(Thruster2speed);
  thruster3.writeMicroseconds(Thruster3speed);
  thruster4.writeMicroseconds(Thruster4speed);// all thruster will move using the Thuster1speed, Thruster2speed, Thruster3speed, Thruster4speed
  Serial.print(joystickY);
  Serial.print(" ");
  Serial.print(joystickX);
  Serial.print(" ");
  Serial.print(ServodegreesG);
  Serial.print(" ");
  Serial.println(ServodegreesB); // printing all the joystick dgrees
}
