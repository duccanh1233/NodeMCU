#include <Arduino.h>
#include "main.h"
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char *ssid = "AVITA";
const char *password = "12345678";

const int output = 2;
const int LM35 = A0;
float temp;

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Not found");
}
AsyncWebServer server(80);

String readDHTTemperature()
{
  int reading = analogRead(LM35);
  float voltage = reading * 5.0 / 1024.0;
  temp = voltage * 100.0;

  if (isnan(temp))
  {
    Serial.println("Failed to read from DHT sensor!");
    return "--";
  }
  else
  {
    Serial.println(temp);
    return String(temp);
  }
}
String readDHTHumidity()
{
  float h = (temp * 9.0 / 5.0) + 32.0;
  if (isnan(h))
  {
    Serial.println("Failed to read from DHT sensor!");
    return "--";
  }
  else
  {
    Serial.println(h);
    return String(h);
  }
}

String processor(const String &var)
{
  if (var == "TEMPERATURE")
  {
    return readDHTTemperature();
  }
  else if (var == "HUMIDITY")
  {
    return readDHTHumidity();
  }
  return String();
}

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.println("WiFi Failed!");
    return;
  }
  Serial.println();
  Serial.print("ESP IP Address: http://");
  Serial.println(WiFi.localIP());

  pinMode(output, OUTPUT);
  pinMode(LM35, OUTPUT);
  digitalWrite(output, LOW);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/html", index_html); });

  server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    digitalWrite(output, LOW);
    request->send(200, "text/plain", "ok"); });

  server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    digitalWrite(output, HIGH);
    request->send(200, "text/plain", "ok"); });

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", readDHTTemperature().c_str()); });

  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", readDHTHumidity().c_str()); });
  server.onNotFound(notFound);
  server.begin();
}

void loop()
{
}