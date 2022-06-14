const int LDR_sensor = 22; //pin D2
int LDR_data;

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR_sensor, INPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
 LDR_data = digitalRead(LDR_sensor);
 Serial.print("LDR Sensor : ");Serial.println(LDR_data);
 delay(1000);

}
