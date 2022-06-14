#include<AntaresESP32HTTP.h>
#define ACCESSKEY "eaa004f588aae95e:3a0abb142e3eafdd" //define accesskey
#define WIFISSID "rangga"//define SSID name
#define PASSWORD "rangga123"     // Ganti dengan password WiFi anda
#define projectName "PPI_tubes" //define project name
#define deviceName "sensor"    // Ganti dengan device Antares yang telah dibuat

AntaresESP32HTTP antares(ACCESSKEY);

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
  antares.setDebug(true);// Nyalakan debug. Set menjadi "false" jika tidak ingin pesan-pesan tampil di Serial monitor
  antares.wifiConnection(WIFISSID,PASSWORD);

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
      

  antares.add("Ada cahaya", LDR_data);
  antares.add("Soil value", nilai_kelembaban);
  antares.add("Kondisi LED", led_indikator);
  antares.add("Kondisi keran air (1 menyala 0 mati)", keran_indikator);

  antares.send(projectName, deviceName);

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

    antares.add("Ada cahaya", LDR_data);
    antares.add("Soil value", nilai_kelembaban);
    antares.add("Kondisi LED", led_indikator);
    antares.add("Kondisi keran air (1 menyala 0 mati)", keran_indikator);

    antares.send(projectName, deviceName);
      
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
    antares.add("Ada cahaya", LDR_data);
    antares.add("Soil value", nilai_kelembaban);
    antares.add("Kondisi LED", led_indikator);
    antares.add("Kondisi keran air (1 menyala 0 mati)", keran_indikator);

    antares.send(projectName, deviceName);
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

      antares.add("Ada cahaya", LDR_data);
      antares.add("Soil value", nilai_kelembaban);
      antares.add("Kondisi LED", led_indikator);
      antares.add("Kondisi keran air (1 menyala 0 mati)", keran_indikator);

      antares.send(projectName, deviceName);
      delay(10000);
    }

    digitalWrite(keran, LOW);
    

}
