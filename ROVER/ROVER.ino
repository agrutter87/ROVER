#include <Servo.h>

Servo panServo;
Servo tiltServo;

int motorSpeedPin[2] = {6, 5};
int motorDirectionPin[2] = {8, 7};
int panServoPin = 9;
int tiltServoPin = 10;
int rangefinderPin = 11;
int irOutputPin = 12;

int motorSpeed[2] = {0, 0};
boolean motorDirection[2] = {LOW, LOW};
int panServoAngle = 90;
int tiltServoAngle = 180;

int encoderValue[2] = {0, 0};
int irValue[4] = {0, 0, 0, 0};
int accelerometer_x = 0;
int accelerometer_y = 0;

void sendPing(int pin)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(15);
  digitalWrite(pin, LOW);
  delayMicroseconds(20);
}

long receivePing(int pin)
{
  pinMode(pin, INPUT);
  return pulseIn(pin, HIGH);
}

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  panServo.attach(panServoPin);
  tiltServo.attach(tiltServoPin);
  Serial.begin(9600);
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
  irValue[0] = analogRead(A2);
  irValue[1] = analogRead(A3);
  irValue[2] = analogRead(A4);
  irValue[3] = analogRead(A5);
  accelerometer_x = analogRead(A6);
  accelerometer_y = analogRead(A7);
}
