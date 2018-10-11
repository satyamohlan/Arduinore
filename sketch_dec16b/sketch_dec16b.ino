#include <NewPing.h>

#include <AFMotor.h>
AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);
int sensor[3] = {0, 0, 0};
int echopin = 22;
int trigpin = 24;
int distance;
int duration;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(echopin, INPUT);
  pinMode(trigpin, OUTPUT);

}

void loop() {

  int i = 0;
  digitalWrite(trigpin, HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);
  distance = (duration / 2 * 0.034);
  Serial.println(distance);


  sensor[0] = digitalRead(A0);
  sensor[1] = digitalRead(A1);
  sensor[2] = digitalRead(A2);
  for (i = 0; i < 5; i++)



    if ((sensor[0] == 1) && (sensor[1] == 0) && sensor[2] == 1) //STRAIGHT FW
    { motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor1.setSpeed(190);
      motor2.setSpeed(190);
    }
  if ((sensor[0] == 1) && (sensor[1] == 1) && sensor[2] == 1) //STRAIGHT FW
  { motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor1.setSpeed(190);
    motor2.setSpeed(190);
  }
  if ((sensor[0] == 0) && (sensor[1] == 0) && sensor[2] == 0) //STRAIGHT FW
  { motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor1.setSpeed(190);
    motor2.setSpeed(190);
  }
  if ((sensor[0] == 1) && (sensor[1] == 0) && sensor[2] == 0) //right
  { motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor1.setSpeed(225);
    motor2.setSpeed(225);
  }
  if ((sensor[0] == 0) && (sensor[1] == 0) && sensor[2] == 1) //left
  { motor1.run(BACKWARD);
    motor2.run(FORWARD);
    motor1.setSpeed(225);
    motor2.setSpeed(225);
  }
  if ((sensor[0] == 0) && (sensor[1] == 1) && sensor[2] == 1) //left
  { motor1.run(BACKWARD);
    motor2.run(FORWARD);
    motor1.setSpeed(125);
    motor2.setSpeed(125);
  } if ((sensor[0] == 1) && (sensor[1] == 1) && sensor[2] == 0) //right
  { motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor1.setSpeed(125);
    motor2.setSpeed(125);
  }
  if ((distance < 16)&&(distance>6)) {
    avoid();
  }
}
void avoid() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor1.setSpeed(190);
  motor2.setSpeed(190);
  delay(500);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor1.setSpeed(190);
  motor2.setSpeed(190);
  delay(1500);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(190);
  motor2.setSpeed(190);
  delay(2000);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(190);
  motor2.setSpeed(190);
  delay(1500);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(190);
  motor2.setSpeed(190);
  delay(1700);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(190);
  motor2.setSpeed(190);
  
   motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(190);
  motor2.setSpeed(190);
  delay(1500);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(190);
  motor2.setSpeed(190);
  delay(1000);
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor1.setSpeed(190);
  motor2.setSpeed(190);
  delay(100);
}
