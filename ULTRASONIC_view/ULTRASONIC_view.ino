#include <AFMotor.h>

#include <NewPing.h>
AF_DCMotor motor1(4);
AF_DCMotor motor2(5);

float distance;
long duration;
int trigpin = 9;
int echopin = 10;
void setup() {
  // put your setup code here, to run once:

  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = duration * 0.034 / 2;
 
 Serial.print(distance,1);
Serial.print("cm");
Serial.println();
  
  if (distance<10){
    Serial.println("turn");
    
  }delay(200);
}




