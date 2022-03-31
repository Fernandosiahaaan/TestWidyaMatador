#include <DHT.h>
#include <WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
#define variabel_label "DHTSensor"
#define variabel_subscribe "relay"
#define device_label "Demo"


const char* ssid = "Siahaan Family";
const char* password = "Tulusmaju123";
const char* mqtt_server = "broker.mqtt-dashboard.com";
const char* token = "BBFF-2W0UlrMced1fiuvefsiISw2QHrMXLw";


WiFiClient ubidots;
PubSubClient client(ubidots);
long lastMsg = 0;
char msg[50];
char topic[50];
char payload[50];
int value = 0;
int relay = 13;
int sensordht;

DHT dht(2,11);
void setup() {
  pinMode(relay, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(relay, LOW);   
  } else {
    digitalWrite(relay, HIGH);
    }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("BelajarMQTT", token,"")) {
      Serial.println("connected");
      client.publish("TopikKeluar", "hello world");
      client.subscribe("TopikMasuk");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  snprintf (topic, "%s%s","/v1.6/devices/", device_label);
  snprintf (payload, "{\"%s\":", variabel_label);
  

  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    sensordht = dht.readTemperature();
    snprintf (msg, 75, "Temperatur internal : #%ld", sensordht);
    Serial.print(sensordht);
    client.publish("outTopic", msg);
  }}
