//dummy antares
#include<AntaresESP32HTTP.h>
#define ACCESSKEY "eaa004f588aae95e:3a0abb142e3eafdd" //define accesskey
#define WIFISSID "rangga"//define SSID name
#define PASSWORD "rangga123"     // Ganti dengan password WiFi anda
#define projectName "PPI_tubes" //define project name
#define deviceName "sensor"    // Ganti dengan device Antares yang telah dibuat

AntaresESP32HTTP antares(ACCESSKEY); 

int soilValue;
int LDRValue;
const int ldr = 1;
const int keran = 0;


void setup() {
  // put your setup code here, to run once:
  antares.setDebug(true);// Nyalakan debug. Set menjadi "false" jika tidak ingin pesan-pesan tampil di Serial monitor
  antares.wifiConnection(WIFISSID,PASSWORD);  // Mencoba untuk menyambungkan ke WiFi
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  soilValue = random(100,300);
  LDRValue = random(500,1025);
  Serial.println(soilValue);
  Serial.println(LDRValue);

  //antares add
  antares.add("Ada cahaya", LDRValue);
  antares.add("Soil value", soilValue);
  antares.add("Kondisi LED", ldr);
  antares.add("Kondisi keran air (1 menyala 0 mati)", keran);

  antares.send(projectName, deviceName);
  delay(10000);
  

}
