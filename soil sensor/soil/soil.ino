//sensor soil pin
int soilValue = 15; //D26 pin
const int limit = 300; 
int nilai_kelembaban;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  nilai_kelembaban = analogRead(soilValue);
  Serial.print("nilai kelembaban ");Serial.println(nilai_kelembaban);
  delay(1000);
}
