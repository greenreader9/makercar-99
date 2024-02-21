#include <ESP8266WiFi.h>
#include <DNSServer.h> 
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
#include "index_html.h"
#include "Motor.h"

//char* ssid = "SSID3";
//char* password = "password";
//ESP8266WebServer server;
//WebSocketsServer webSocket = WebSocketsServer(81);

#define SSID_NAME "DGS Maker Car v2"
#define SSID_PASSWORD "12345678"
#define WIFI_CHANNEL 6           // only use 1, 6, or 11
const byte DNS_PORT = 53;
int  n=0;

IPAddress APIP(192, 168, 4, 1);  //Gateway
IPAddress netmask(255, 255, 255, 0);
DNSServer dnsServer;
ESP8266WebServer server(80); //Port 80
WebSocketsServer webSocket = WebSocketsServer(81); //Port81

void setup()
{
  Serial.begin(115200);
  Serial.println("\nStart");
//  WiFi.begin(ssid,password);
//  while(WiFi.status()!=WL_CONNECTED)
//  {
//    Serial.print(".");
//    delay(500);
//  }

  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(APIP, APIP, netmask);
  WiFi.softAP(SSID_NAME,SSID_PASSWORD, WIFI_CHANNEL);
  dnsServer.start(DNS_PORT, "*", APIP); // DNS spoofing (Only HTTP)

  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

// set pinmode for pins going to the motor driver
  pinMode(A1Pin,OUTPUT);
  digitalWrite(A1Pin, LOW);      
  pinMode(A2Pin,OUTPUT);
  digitalWrite(A2Pin, LOW);      
  pinMode(B1Pin,OUTPUT);
  digitalWrite(B1Pin, LOW);      
  pinMode(B2Pin,OUTPUT);
  digitalWrite(B2Pin, LOW);  

  server.onNotFound([]() { 
    server.send(200, "text/html", webpage); 
  });
    
  server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void loop()
{
  webSocket.loop();
  server.handleClient();
  dnsServer.processNextRequest();
  processCarMovement(n);
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length){
    char buffer[4];
  if(type == WStype_TEXT){
    for(int i = 0; i < length; i++){
      buffer[i] = payload[i];    
    }
    buffer[length] = '\0';
    n = atoi(buffer);
//    Serial.println(n);
  }    
}
