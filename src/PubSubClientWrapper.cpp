#include "PubSubClientWrapper.h"

PubSubClientWrapper::PubSubClientWrapper(Client& espc) : PubSubClient(espc){
}

bool PubSubClientWrapper::subscribe(String topic) {
  return PubSubClient::subscribe(topic.c_str());
}

bool PubSubClientWrapper::subscribe(String topic, uint8_t qos) {
  return PubSubClient::subscribe(topic.c_str(), qos);
}

bool PubSubClientWrapper::publish(String topic, String str) {
  return publish(topic.c_str(), str);
}

bool PubSubClientWrapper::publish(String topic, uint8_t num) {
  return publish(topic.c_str(), num);
}

bool PubSubClientWrapper::publish(String topic, uint16_t num) {
  return publish(topic.c_str(), num);
}

bool PubSubClientWrapper::publish(String topic, uint32_t num) {
  return publish(topic.c_str(), num);
}

bool PubSubClientWrapper::publish(String topic, float num) {
  return publish(topic.c_str(), num);
}

bool PubSubClientWrapper::publish(const char* topic, String str) {
  return publish(topic, str, false);
}

bool PubSubClientWrapper::publish(const char* topic, uint8_t num) {
  return publish(topic, num, false);
}

bool PubSubClientWrapper::publish(const char* topic, uint16_t num) {
  return publish(topic, num, false);
}

bool PubSubClientWrapper::publish(const char* topic, uint32_t num) {
  return publish(topic, num, false);
}

bool PubSubClientWrapper::publish(const char* topic, float num) {
  return publish(topic, num, false);
}

bool PubSubClientWrapper::publish(String topic, String str, bool retain) {
  return publish(topic.c_str(), str, retain);
}

bool PubSubClientWrapper::publish(String topic, uint8_t num, bool retain) {
  return publish(topic.c_str(), num, retain);
}

bool PubSubClientWrapper::publish(String topic, uint16_t num, bool retain) {
  return publish(topic.c_str(), num, retain);
}

bool PubSubClientWrapper::publish(String topic, uint32_t num, bool retain) {
  return publish(topic.c_str(), num, retain);
}

bool PubSubClientWrapper::publish(String topic, float num, bool retain) {
  return publish(topic.c_str(), num, retain);
}

bool PubSubClientWrapper::publish(const char* topic, String str, bool retain) {
  char buf[128];
  if(str.length() >= 128) return false;
  str.toCharArray(buf, 128);
  return PubSubClient::publish(topic, buf, retain);
}

bool PubSubClientWrapper::publish(const char* topic, uint8_t num, bool retain) {
  char buf[4];
  dtostrf(num, 0, 0, buf);
  return PubSubClient::publish(topic, buf, retain);
}

bool PubSubClientWrapper::publish(const char* topic, uint16_t num, bool retain) {
  char buf[6];
  dtostrf(num, 0, 0, buf);
  return PubSubClient::publish(topic, buf, retain);
}

bool PubSubClientWrapper::publish(const char* topic, uint32_t num, bool retain) {
  char buf[11];
  dtostrf(num, 0, 0, buf);
  return PubSubClient::publish(topic, buf, retain);
}

bool PubSubClientWrapper::publish(const char* topic, float num, bool retain) {
  char buf[10];
  dtostrf(num, 0, 3, buf);
  return PubSubClient::publish(topic, buf, retain);
}

uint8_t PubSubClientWrapper::rssiToPercentage(int32_t rssi) {
  //@author Marvin Roger - https://github.com/marvinroger/homie-esp8266/blob/ad876b2cd0aaddc7bc30f1c76bfc22cd815730d9/src/Homie/Utils/Helpers.cpp#L12
  uint8_t quality;
  if (rssi <= -100) {
    quality = 0;
  } else if (rssi >= -50) {
    quality = 100;
  } else {
    quality = 2 * (rssi + 100);
  }

  return quality;
}

void PubSubClientWrapper::ipToString(const IPAddress& ip, char * str) {
  //@author Marvin Roger - https://github.com/marvinroger/homie-esp8266/blob/ad876b2cd0aaddc7bc30f1c76bfc22cd815730d9/src/Homie/Utils/Helpers.cpp#L82
  snprintf(str, 16, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
}
