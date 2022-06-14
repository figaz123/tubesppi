const int keran = 24; //D4

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(115200);
  pinMode(keran, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(keran, HIGH);
  Serial.print("keran nyala");
  delay(1000);
  digitalWrite(keran, LOW);
  delay(10000);

}
