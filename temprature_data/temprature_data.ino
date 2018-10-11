double x;
void setup() {
  // put your setup code here, to run once:
pinMode(7,INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.begin(9600);
x=analogRead(7);
Serial.write(x);
delay(100);
}
