#include <Servo.h>

Servo panServo;
Servo tiltServo;

int panServoPin = 9;
int tiltServoPin = 10;

int panServoAngle = 0;
int tiltServoAngle = 90;

void setup()
{
  panServo.attach(tiltServoPin);
  tiltServo.attach(panServoPin);
}

void loop()
{ 
  panServo.write(panServoAngle);
  tiltServo.write(tiltServoAngle);
}
