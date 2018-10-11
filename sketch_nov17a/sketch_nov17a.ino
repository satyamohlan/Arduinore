
int state=0;
int left1=4;
int left2=5;
int right1=6;
int right2=7;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


 pinMode(right2,OUTPUT);
 pinMode(right1,OUTPUT);
  pinMode(left1,OUTPUT);
  pinMode(left2,OUTPUT);

}

void loop() {

  // put your main code here, to run repeatedly:
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
 }}
 
      

    
  


