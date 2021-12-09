#include <ArduinoBearSSL.h>
#include <ArduinoECCX08.h>
#include <ArduinoMqttClient.h>
#include <ArduinoJson.h>
#include <WiFiNINA.h>
#include "DHT.h"
#include "SparkFun_SGP40_Arduino_Library.h"
#include <Wire.h>

#include "arduino_secrets.h"

/////// Enter your sensitive data in arduino_secrets.h
const char ssid[]        = SSID;
const char pass[]        = PASS;
const char broker[]      = AWS_BROKER;
const char* certificate  = SECRET_CERTIFICATE;


#define DHTPIN 0     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
SGP40 mySensor; //create an object of the SGP40 class

WiFiClient    wifiClient;            // Used for the TCP socket connection
BearSSLClient sslClient(wifiClient); // Used for SSL/TLS connection, integrates with ECC508
MqttClient    mqttClient(sslClient);

unsigned long lastMillis = 0;
unsigned int waitForSensors = 2500;

byte mac[6];

void setup() {
  Serial.begin(115200);
  while (!Serial);

  dht.begin();
  Wire.begin();

  //Initialize SGP40
  if (mySensor.begin() == false)
  {
    Serial.println(F("SGP40 not detected. Check connections. Freezing..."));
    while (1)
      ; // Do nothing more
  }

  if (!ECCX08.begin()) {
    Serial.println("No ECCX08 present!");
    while (1);
  }

  // Set a callback to get the current time
  // used to validate the servers certificate
  ArduinoBearSSL.onGetTime(getTime);

  // Set the ECCX08 slot to use for the private key
  // and the accompanying public certificate for it
  sslClient.setEccSlot(0, certificate);

  // Optional, set the client id used for MQTT,
  // each device that is connected to the broker
  // must have a unique client id. The MQTTClient will generate
  // a client id for you based on the millis() value if not set
  //
  // mqttClient.setId("clientId");

  // Set the message callback, this function is
  // called when the MQTTClient receives a message
  mqttClient.onMessage(onMessageReceived);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }

  if (!mqttClient.connected()) {
    // MQTT client is disconnected, connect
    connectMQTT();
  }

  // poll for new MQTT messages and send keep alives
  mqttClient.poll();

  getDHT_Values();
}



void getDHT_Values() {
  float temp = dht.readTemperature();
  float rh = dht.readHumidity();

  if (millis() - lastMillis > waitForSensors) {
    lastMillis = millis();

    generateVOC_Index(rh,temp);
  }
}

void generateVOC_Index(float rh, float temp) {
  uint8_t VOC = mySensor.getVOCindex(rh, temp);
  delay(1000);
  
  generateJsonObject(rh, temp, VOC);
}

void generateJsonObject(float rh, float temp, uint8_t VOC) {
  char payload[256]; 
  String mac = "7C:9E:BD:3A:69:7C";

  StaticJsonDocument<256> doc;

  doc["macId"] = mac;
  doc["temperature"] = temp;
  doc["humidity"] = rh;
  doc["voc"] = VOC;
  doc["timeStamp"] = getTime();

  serializeJson(doc, payload);

  publishMessage(payload);

}

unsigned long getTime() {
  // get the current time from the WiFi module  
  return WiFi.getTime();
}

void connectWiFi() {
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(5000);
  }
  Serial.println();

  Serial.println("You're connected to the network");
  Serial.println();
}

void connectMQTT() {
  Serial.print("Attempting to MQTT broker: ");
  Serial.print(broker);
  Serial.println(" ");

  while (!mqttClient.connect(broker, 8883)) {
    // failed, retry
    Serial.print(".");
    delay(5000);
  }
  Serial.println();

  Serial.println("You're connected to the MQTT broker");
  Serial.println();

  // subscribe to a topic
  mqttClient.subscribe("arduino/incoming");
}

void publishMessage(char *payload) {
  Serial.println(payload);

  // send message, the Print interface can be used to set the message contents
  mqttClient.beginMessage("outTopic");
  mqttClient.print(payload);
  mqttClient.endMessage();
}

void onMessageReceived(int messageSize) {
  // we received a message, print out the topic and contents
  Serial.print("Received a message with topic '");
  Serial.print(mqttClient.messageTopic());
  Serial.print("', length ");
  Serial.print(messageSize);
  Serial.println(" bytes:");

  // use the Stream interface to print the contents
  while (mqttClient.available()) {
    Serial.print((char)mqttClient.read());
  }
  Serial.println();

  Serial.println();
}