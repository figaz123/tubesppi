//antares
#include <AntaresESP32HTTP.h>
//#include <AntaresESP8266HTTP.h>     // Inisiasi library MQTT Antares
#define ACCESSKEY "eaa004f588aae95e:3a0abb142e3eafdd" //define accesskey
#define WIFISSID "RAFASTORE"//define SSID name
#define PASSWORD "rafa1234"     // Ganti dengan password WiFi anda
#define applicationName "NodeMCU_HTTP_PPI" //define project name
#define deviceName "Sensor"    // Ganti dengan device Antares yang telah dibuat

AntaresESP32HTTP antares(ACCESSKEY); 


//include servo
//#include<Servo.h>

//relay variable
const int relay_pin = 25;

//variable led dan ldr
const int led = 26;
int cahaya = 15;
int indikator_LED;

//sensor soil pin
int sensorPin = 4;  
const int limit = 300; 
int soilValue;

//keran air
int nilai_keran;
int keran;
//Servo servoku;

void setup() {
  // put your setup code here, to run once:

//Antares
  //Serial.begin(115200);     // Buka komunikasi Serial dengan baudrate 115200
  antares.setDebug(true);   // Nyalakan debug. Set menjadi "false" jika tidak ingin pesan-pesan tampil di Serial monitor
  antares.wifiConnection(WIFISSID,PASSWORD);  // Mencoba untuk menyambungkan ke WiFi
  //antares.setMqttServer();  // Inisiasi server MQTT Antares
  
 pinMode(cahaya, INPUT);
 pinMode(led, OUTPUT);
 pinMode(relay_pin, OUTPUT);
 Serial.begin(9600);
// servoku.attach(D1);

}

void loop() {
  // put your main code here, to run repeatedly:
  //antares
 // antares.checkMqttConnection();
  
  cahaya = digitalRead(cahaya);
  Serial.print("LDR : ");
  Serial.println(cahaya);
  soilValue = analogRead(sensorPin);
  Serial.print("Soil value: ");
  Serial.println(soilValue);

  if(cahaya > 0 && soilValue < limit){//tanah kering dan cahaya nggak ada
    digitalWrite(led, LOW);
    Serial.println("LED off");
    Serial.println("Keran menyala");
    digitalWrite(relay_pin, HIGH);
    delay(10000);
    digitalWrite(relay_pin, LOW);
    nilai_keran = 1;
    indikator_LED = 0;

    Serial.print("ada cahaya: ");Serial.println(cahaya);
    Serial.print("soil value: ");Serial.println(soilValue);
    Serial.print("kondisi LED: ");Serial.println(indikator_LED);
    Serial.print("kondisi keran air (1 menyala 0 mati): ");Serial.println(nilai_keran);
    
    antares.add("Ada cahaya",cahaya);
    antares.add("Soil value", soilValue);
    antares.add("Kondisi LED", indikator_LED);
    antares.add("Kondisi keran air (1 menyala 0 mati)", nilai_keran);
    }
    else if(cahaya > 0 && soilValue > limit){//tanah nggak kering dan cahaya gak ada
    
    digitalWrite(led, LOW);
    Serial.println("LED off");
    Serial.println("Keran mati");
    digitalWrite(relay_pin, LOW);
    delay(10000);
    //digitalWrite(relay_pin, LOW);
    nilai_keran = 0;
    indikator_LED = 0;

    Serial.print("ada cahaya: ");Serial.println(cahaya);
    Serial.print("soil value: ");Serial.println(soilValue);
    Serial.print("kondisi LED: ");Serial.println(indikator_LED);
    Serial.print("kondisi keran air (1 menyala 0 mati");Serial.println(nilai_keran);

    antares.add("Ada cahaya",cahaya);
    antares.add("Soil value", soilValue);
    antares.add("Kondisi LED", indikator_LED);
    antares.add("Kondisi keran air (1 menyala 0 mati)", nilai_keran);
      }
    else if(cahaya <= 0 && soilValue > limit){//led nyala keran mati
    digitalWrite(led, HIGH);
    Serial.println("LED ON");
    Serial.println("Keran mati");
    digitalWrite(relay_pin, LOW);
    delay(10000);
    //digitalWrite(relay_pin, LOW);
    nilai_keran = 0;
    indikator_LED = 1;

    Serial.print("ada cahaya: ");Serial.println(cahaya);
    Serial.print("soil value: ");Serial.println(soilValue);
    Serial.print("kondisi LED: ");Serial.println(indikator_LED);
    Serial.print("kondisi keran air (1 menyala 0 mati): ");Serial.println(nilai_keran);

    antares.add("Ada cahaya",cahaya);
    antares.add("Soil value", soilValue);
    antares.add("Kondisi LED", indikator_LED);
    antares.add("Kondisi keran air (1 menyala 0 mati)", nilai_keran);
      }
   else if(cahaya <= 0 && soilValue < limit){//led nyala keran nyala
    digitalWrite(led, HIGH);
    Serial.println("LED on");
    Serial.println("Keran menyala");
    digitalWrite(relay_pin, HIGH);
    delay(10000);
    digitalWrite(relay_pin, LOW);
    nilai_keran = 1;
    indikator_LED = 1;

    Serial.print("ada cahaya: ");Serial.println(cahaya);
    Serial.print("soil value: ");Serial.println(soilValue);
    Serial.print("kondisi LED: ");Serial.println(indikator_LED);
    Serial.print("kondisi keran air (1 menyala 0 mati): ");Serial.println(nilai_keran);
    
    antares.add("Ada cahaya",cahaya);
    antares.add("Soil value", soilValue);
    antares.add("Kondisi LED", indikator_LED);
    antares.add("Kondisi keran air (1 menyala 0 mati)", nilai_keran);
    }
    
  else{
    Serial.println("Tak ada yang terbaca");
    }
    
  antares.send(applicationName, deviceName);
  delay(10000);
  
}
