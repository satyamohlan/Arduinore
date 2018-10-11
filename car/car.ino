#include <Servo.h>


int state=0;
int left1=4;
int left2=5;
int right1=6;
int right2=7;
int pos=0;
unsigned long time;
float distance;
long duration;
int trigpin = 9;
int echopin = 10;
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


 pinMode(right2,OUTPUT);
 pinMode(right1,OUTPUT);
  pinMode(left1,OUTPUT);
  pinMode(left2,OUTPUT);  
  myservo.attach(9);  
  
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:
 
  time=millis();
  if(time>10000){
       for (pos = 0; pos <= 180; pos += 1) { 

                  
      digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = duration * 0.034 / 2;
      myservo.write(pos);
 
 Serial.print(distance,1);
Serial.print("cm");
if(distance<10){
  
  }
Serial.println();}
    time=00;
  }
  
if (Serial.available() > 0) {
  state = Serial.read();}    
if(state=='1'){
   digitalWrite(left1,HIGH); 
   }
if(state=='2'){
   digitalWrite(right2,HIGH); 
   
      }
 if(state =='0'){
digitalWrite(left1,LOW);
digitalWrite(left2,LOW);
digitalWrite(right1,LOW);
digitalWrite(right2,LOW);
}
 if(state =='3'){
digitalWrite(left1,HIGH);
digitalWrite(right2,HIGH);
}
 if(state =='4'){
digitalWrite(left2,HIGH);
digitalWrite(right1,HIGH);
 }

 }
 
      

    
  


