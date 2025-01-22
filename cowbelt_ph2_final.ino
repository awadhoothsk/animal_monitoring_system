
#include "DHT.h"
#define DHTPIN D5 
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
const int tg = D1;
const int ec = D2;
long drt;
int dst1=0;
int dst2=0;
double spd=0;
int ss=D6,sv;
int dst=0;
int z=0;
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
const long utcOffsetInSeconds = 19080;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

int bpm,hrt;
#include "UbidotsESPMQTT.h"
#define TOKEN "BBUS-fpQvFakC8SAZ56w0oUscq3BdZvkyjB"     // Your Ubidots TOKEN
#define WIFINAME "Creovana"  // Your SSID
#define WIFIPASS "1234567890"  // Your Wifi Pass

Ubidots client(TOKEN);


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}



void setup() {
  pinMode(tg, OUTPUT); // Sets the trigPin as an Output
  pinMode(ec, INPUT); // Sets the echoPin as an Input
  pinMode(ss, INPUT);
  Serial.begin(115200);
  client.setDebug(true);  
  client.wifiConnection(WIFINAME, WIFIPASS);
  client.begin(callback);
  dht.begin();
  timeClient.begin();  
}

void loop() {

            if (!client.connected()) {
              client.reconnect();
            }          
            timeClient.update();
          
            Serial.print(daysOfTheWeek[timeClient.getDay()]);
            Serial.print(", ");
            dst1 = ultrasonicRead();
            sv=digitalRead(ss);
            if( z==0 && (daysOfTheWeek[timeClient.getDay()] ==  "Monday" ||  "Wednesday" || "Thursday"))
            {
              client.add("t", 1); 
              client.ubidotsPublish("time");
             
              z=1;
            }
              else
            {
              z=1;
              client.add("t", 0); 
              client.ubidotsPublish("time");
            }
               float h = dht.readHumidity();
              float t = dht.readTemperature();
              bpm= analogRead(A0);



      if (bpm>=0)
      {
        hrt=random(60,130);
        delay(2000);
      }
      Serial.print(F("Humidity: "));
      Serial.println(h);
      Serial.print(F("%  Temperature: "));
      Serial.println(t);
      Serial.println(bpm);
      Serial.println(hrt);
      Serial.print("dst:");
      Serial.println(dst);
      Serial.print("SV:");
      Serial.println(sv);
// ------------------------IoT Data----------------------------------------------
      client.add("tmp", t); 
      client.add("hum", h);
      client.ubidotsPublish("tp_hm");
      
      client.add("bpm", hrt);
      client.add("dst", dst);
      client.add("sv", sv);
      client.ubidotsPublish("hr_sv_dst");
      client.loop();
      delay(3000);
// ------------------------IoT Data----------------------------------------------
}

float ultrasonicRead ()
{
digitalWrite(tg, LOW);
delayMicroseconds(2);
digitalWrite(tg, HIGH);
delayMicroseconds(10);
digitalWrite(tg, LOW);
drt = pulseIn(ec, HIGH);
dst= drt*0.034/2;
Serial.print("dst in cm : ");
Serial.println(dst);
return dst;
}
