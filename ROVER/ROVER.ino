#include <Servo.h>

Servo panServo;
Servo tiltServo;

int motorSpeedPin[2] = {6, 5};
int motorDirectionPin[2] = {8, 7};
int panServoPin = 9;
int tiltServoPin = 10;
int irOutputPin = 12;

int motorSpeed[2] = {0, 0}
boolean motorDirection[2] = {LOW, LOW};
int panServoAngle = 0;
int tiltServoAngle = 90;

int encoderValue[2] = {0, 0};
int irValue[4] = {0, 0, 0, 0};

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  panServo.attach(tiltServoPin);
  tiltServo.attach(panServoPin);
}

void loop()
{ 
  digitalWrite(motorSpeedPin[0], motorSpeed[0]);
  digitalWrite(motorSpeedPin[1], motorSpeed[1]);
  digitalWrite(motorDirectionPin[0], motorDirection[0]);
  digitalWrite(motorDirectionPin[1], motorDirection[1]);
  panServo.write(panServoAngle);
  tiltServo.write(tiltServoAngle);
  irOutputPin = HIGH;
  
  encoderValue[0] = analogRead(A0);
  encoderValue[1] = analogRead(A1);
  irData[0] = analogRead(A2);
  irData[1] = analogRead(A3);
  irData[2] = analogRead(A4);
  irData[3] = analogRead(A5);
}
