/*
//antares
#include <AntaresESP8266MQTT.h>     // Inisiasi library MQTT Antares
#define ACCESSKEY "eaa004f588aae95e:3a0abb142e3eafdd" //define accesskey
#define WIFISSID "mylaptop"//define SSID name
#define PASSWORD "senyumdulu"     // Ganti dengan password WiFi anda
#define projectName "NodeMCU_MQTT_PPI" //define project name
#define deviceName "Nilai_sensor"    // Ganti dengan device Antares yang telah dibuat
AntaresESP8266MQTT antares(ACCESSKEY); 
*/
//include servo
//#include<Servo.h>

//relay variable
const int relay_pin = D2;

//variable led dan ldr
const int led = D4;
int cahaya;

//sensor soil pin
int sensorPin = A0;  
const int limit = 300; 
int soilValue;

//servo
int nilai_keran;
//Servo servoku;

void setup() {
  // put your setup code here, to run once:

//Antares
  //Serial.begin(115200);     // Buka komunikasi serial dengan baudrate 115200
  /*antares.setDebug(true);   // Nyalakan debug. Set menjadi "false" jika tidak ingin pesan-pesan tampil di serial monitor
  antares.wifiConnection(WIFISSID,PASSWORD);  // Mencoba untuk menyambungkan ke WiFi
  antares.setMqttServer();  // Inisiasi server MQTT Antares
  */
  
 pinMode (led, OUTPUT);
 pinMode (relay_pin, OUTPUT);
 Serial.begin(9600);
// servoku.attach(D1);

}

void loop() {
  // put your main code here, to run repeatedly:
  //antares
 // antares.checkMqttConnection();
  

  cahaya = digitalRead(D2);
  Serial.print("LDR : ");Serial.println(cahaya);
 // antares.add("Ada cahaya:", cahaya);
  soilValue = analogRead(sensorPin);
  Serial.print("Analog Read: ");Serial.println(soilValue);
 // antares.add("Soil value:", soilValue);

  if(cahaya > 0){
    digitalWrite(led, HIGH);
    Serial.println("LED on");
    }
  
  if(soilValue < limit){
    //servoku.write(10);
    digitalWrite(relay_pin, HIGH);
    delay(10000);
    digitalWrite(relay_pin, LOW);
    //servoku.write(100);
    //delay(1000);
    nilai_keran = 1;
    //antares.add("Kondisi servo (1 menyala 0 mati):", nilai_keran);
  }
  else{
    Serial.println("Tanah belum kering");
    nilai_keran = 0;
    //antares.add("Kondisi servo (1 menyala 0 mati):", nilai_keran);
    }

 // antares.publish(projectName, deviceName);
  delay(10000);
  
}
