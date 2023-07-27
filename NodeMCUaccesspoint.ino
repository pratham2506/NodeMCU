#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

// #define led D5

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.softAP("NodeMCU", "pppppppp");
  Serial.println();
  Serial.println("NodeMCU Started!");
  Serial.println(WiFi.softAPIP());
  server.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  client = server.available();  //Gets a client that is connected to the server and has data available for reading.    
  if (client == 1)
  {  
    String request =  client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /ledoff HTTP/1.1")
    {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    if(request == "GET /ledon HTTP/1.1")
    {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}