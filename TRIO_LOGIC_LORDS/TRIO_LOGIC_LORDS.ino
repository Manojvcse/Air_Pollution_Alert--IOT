#define BLYNK_TEMPLATE_ID "TMPL3rceQmNUT"
#define BLYNK_TEMPLATE_NAME "TRIO LOGIC LORDS"
#define BLYNK_AUTH_TOKEN "XJp4Le2wRg86e5e2PtawoSa2Y6AVtAE8"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "";  // type your wifi name vivo Y15
char pass[] = "";  // type your wifi password  kavya2006
int smokeA0 = A0;
int data = 0;
int sensorThres = 100;


BlynkTimer timer;

void sendSensor(){
 
 int data = analogRead(smokeA0);
 Blynk.virtualWrite(V0, data);
  Serial.print("Pin A0: ");
  Serial.println(data);


  if(data > 700){
   
    Blynk.logEvent("gas_alert","Gas Leakage Detected");
  }
}

void setup(){
  pinMode(smokeA0, INPUT);
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}
