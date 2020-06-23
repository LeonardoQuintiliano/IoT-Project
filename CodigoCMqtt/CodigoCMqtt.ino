#include <WiFi.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <ArduinoJson.h>
#include <WebServer.h>
#include <WiFiManager.h>

const String ORG = "c4yqpu";
const String DEVICE_TYPE = "ESP8266";
const String DEVICE_ID = "001";
#define DEVICE_TOKEN "wYh9pi5qjfwS?a_TMJ"
const char* ssid  = "MomoNet2.4"; // Nome do Wi-Fi
const char* pass  = "12551103843";  // Senha do Wi-Fi

#define pinSENSOR 4                           //D2/4 pin do nodemcu //Sinal do sensor DS18B20
#define pinRELE 12

const String CLIENT_ID = "" + ORG + ":" + DEVICE_TYPE + ":" + DEVICE_ID;
const String MQTT_SERVER = ORG + ".messaging.internetofthings.cloud.ibm.com";
void connectMQTTServer();
#define COMMAND_TOPIC_R1 "iot-2/cmd/commandR1/fmt/json"
WiFiClient wifiClient;
PubSubClient client(MQTT_SERVER.c_str(), 1883, wifiClient);

OneWire oneWire(pinSENSOR);
DallasTemperature sensors(&oneWire);            // Pass the oneWire reference to Dallas Temperature.
DeviceAddress sensor;

float temp_desejada = 24;
float temperatura = 0;
boolean chamou = true;

void setup()
{
  Serial.begin(115200);
  pinMode(12, OUTPUT);
  pinMode(4, OUTPUT);
  sensors.begin();
  Serial.println("Localizando sensor DS18B20...");
  Serial.print("Foi encontrado  ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.print(" endereço do sensor: ");

  WiFiManager wifiManager;
  wifiManager.setAPCallback(configModeCallback);
  wifiManager.setSaveConfigCallback(saveConfigCallback);
  wifiManager.autoConnect("PROJ-ESP8266");

  connectMQTTServer();
}
void loop() {
  //client.loop();
  LeituraSensor();
  verificaTemperatura();
}
void connectMQTTServer() {
  Serial.println("Conectando ao servidor MQTT...");
  if (client.connect (CLIENT_ID.c_str(), "use-token-auth", DEVICE_TOKEN)) {
    Serial.println("Conectado ao Broker MQTT...");
    client.setCallback(callback);

    client.subscribe(COMMAND_TOPIC_R1);
  }
  else {
    Serial.print("erro = ");
    Serial.println(client.state());
    connectMQTTServer();
  }
}
void callback(char* topic, unsigned char* payload, unsigned int length) {
  Serial.print("topico");
  Serial.println(topic);

  StaticJsonDocument<30> doc;
  
  DeserializationError error = deserializeJson(doc, payload);

  if (error) {
    Serial.println("Erro no Json Parse");
    return;
  }
  int value = doc["value"];
  if (strcmp(topic, COMMAND_TOPIC_R1) == 0) {
    digitalWrite( pinRELE, value);
  }
}
void configModeCallback( WiFiManager *myWiFiManager) {
  Serial.println("Entrou no modo de config");
  
  Serial.println(myWiFiManager->getConfigPortalSSID());
}
void saveConfigCallback() {
  Serial.println("Configuração salva");
  
}
void LeituraSensor()

{ if (chamou = true) {


    if (!sensors.getAddress(sensor, 0)) {
      Serial.println("Sensor não encontrado !");
    }


    Serial.println();
    Serial.println();


    sensors.requestTemperatures();
    Serial.println("Temperature is: ");
    Serial.println(sensors.getTempC(sensor));
    delay(500);
  }
  chamou = false;
}

void verificaTemperatura() {
  if (sensors.getTempC(sensor) >= 25) {
    digitalWrite(12, HIGH);
    delay(100);
    Serial.println("Rele desligado");
    Serial.print("Temperatura do sensor ");
    Serial.println(sensors.getTempC(sensor));
    Serial.print("Temperatura desejada ");
    Serial.println(temp_desejada);
  }
  if (sensors.getTempC(sensor) <= 23) {
    digitalWrite(12, LOW);
    delay(100);
    Serial.println("Rele ligado");
    Serial.print("Temperatura do sensor ");
    Serial.println(sensors.getTempC(sensor));
    Serial.print("Temperatura desejada ");
    Serial.println(temp_desejada);
  }
}
