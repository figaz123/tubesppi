//gabungan

//keran
const int keran = 24; //D4

//nilai tanah
int soilValue = 15; //D26 pin
const int limit = 300; 
int nilai_kelembaban;

//LDR sensor
const int LDR_sensor = 22;
int LDR_data;

//LED
const int LED = 20;

//variable kondisi
int keran_indikator;
int led_indikator;

void setup() {
  // put your setup code here, to run once:
    pinMode(keran, OUTPUT);
    pinMode(LED, OUTPUT);
    
    Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  nilai_kelembaban = analogRead(soilValue);
  LDR_data = analogRead(LDR_sensor);

  if(nilai_kelembaban > 500 && LDR_data > 500){
      keran_indikator = 0;
      led_indikator = 0;
      Serial.print("nilai kelembaban ");Serial.println(nilai_kelembaban);
      Serial.print("LDR_data ");Serial.println(LDR_data);
      Serial.print("Lampu(0 mati 1 nyala)");Serial.println(led_indikator);
      Serial.print("keran(0 mati 1 nyala)");Serial.println(keran_indikator);
      digitalWrite(LED, LOW);
      digitalWrite(keran, LOW);
      delay(10000);
    
    }
    
   else if(nilai_kelembaban < 500 && LDR_data > 500){
      keran_indikator = 1;
      led_indikator = 0;
      Serial.print("nilai kelembaban ");Serial.println(nilai_kelembaban);
      Serial.print("LDR_data ");Serial.println(LDR_data);
      Serial.print("Lampu(0 mati 1 nyala)");Serial.println(led_indikator);
      Serial.print("keran(0 mati 1 nyala)");Serial.println(keran_indikator);
      digitalWrite(LED, LOW);
      digitalWrite(keran, HIGH);
      delay(10000);
    }
    else if(nilai_kelembaban < 500 && LDR_data < 500){
      keran_indikator = 1;
      led_indikator = 1;
      Serial.print("nilai kelembaban ");Serial.println(nilai_kelembaban);
      Serial.print("LDR_data ");Serial.println(LDR_data);
      Serial.print("Lampu(0 mati 1 nyala)");Serial.println(led_indikator);
      Serial.print("keran(0 mati 1 nyala)");Serial.println(keran_indikator);
      digitalWrite(LED, HIGH);
      digitalWrite(keran, HIGH);
      delay(10000);
    }
    else if(nilai_kelembaban > 500 && LDR_data < 500){
      keran_indikator = 0;
      led_indikator = 1;
      Serial.print("nilai kelembaban ");Serial.println(nilai_kelembaban);
      Serial.print("LDR_data ");Serial.println(LDR_data);
      Serial.print("Lampu(0 mati 1 nyala)");Serial.println(led_indikator);
      Serial.print("keran(0 mati 1 nyala)");Serial.println(keran_indikator);
      digitalWrite(LED, HIGH);
      digitalWrite(keran, LOW);
      delay(10000);
    }
  
  
}
