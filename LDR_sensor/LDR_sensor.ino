
const int led = D4;
void setup() {
  // put your setup code here, to run once:
 pinMode (led, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int cahaya;
 cahaya = analogRead(A0);
 Serial.print("Cahaya LDR: ");
 Serial.println(cahaya);
 delay(1000);
 if (cahaya < 650){//nilai dari tegangan dikeluarkan sensor LDR
  digitalWrite(led, HIGH);
  Serial.println("LED ON");
  
 } else {

   digitalWrite(led, LOW);
   Serial.println("LED OFF");

 }
 
 
}
