#include <AFMotor.h>
AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);
int sensor[3]={0, 0,0};


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
}

void loop() {
int i=0;
  sensor[0]=digitalRead(A0);
  sensor[1]=digitalRead(A1);
  sensor[2]=digitalRead(A2);
  for(i=0;i<5;i++)
  {   
   Serial.print(sensor[i]    );
  Serial.print("\n");}
    
        if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==1)) //STRAIGHT FW
 {  motor1.run(FORWARD);
     motor2.run(FORWARD);
     motor1.setSpeed(200);
    motor2.setSpeed(200);}
     if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)) //STRAIGHT FW
 {  motor1.run(FORWARD);
     motor2.run(FORWARD);
     motor1.setSpeed(200);
    motor2.setSpeed(200);}
 if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)) //STRAIGHT FW
 {  motor1.run(FORWARD);
     motor2.run(FORWARD);
     motor1.setSpeed(200);
    motor2.setSpeed(200);
    }
 if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)) //right
 {  motor1.run(FORWARD);
     motor2.run(BACKWARD);
      motor1.setSpeed(255);  
      motor2.setSpeed(255);
      }
 if((sensor[0]==0)&&(sensor[1]==0)&&sensor[2]==1) //left
 {  motor1.run(BACKWARD);
     motor2.run(FORWARD);
     motor1.setSpeed(255);
    motor2.setSpeed(255);} 
    if((sensor[0]==0)&&(sensor[1]==1)&&sensor[2]==1) //left
 {  motor1.run(BACKWARD);
     motor2.run(FORWARD);
     motor1.setSpeed(255);
    motor2.setSpeed(255);} 
    if((sensor[0]==1)&&(sensor[1]==1)&&sensor[2]==0) //right
 {  motor1.run(FORWARD);
     motor2.run(BACKWARD);
     motor1.setSpeed(255);
    motor2.setSpeed(255);}
}
