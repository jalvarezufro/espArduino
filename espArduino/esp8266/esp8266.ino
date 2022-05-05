#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>


#define ssid "DCISALA201"
#define password "DCI.2022"

void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);

  Serial.begin(19200);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());


 

}

void loop(){
  int alerta;

   if (Serial.available()) 
   { // If data is available to read,
     alerta = Serial.read(); // read it and store it in val
     if(alerta == 1){
    WiFiClient client;
    HTTPClient http;  //Declare an object of class HTTPClient
 
    http.begin(client,"http://maker.ifttt.com/trigger/esp8266/json/with/key/nXj55Zo1M4sR2JiuyOpCi");  //Specify request destination
    int httpCode = http.GET();                                  //Send the request
 
    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);             //Print the response payload
 
    }
 
    http.end();   //Close connection
    delay(5000);
   }
 }

}
