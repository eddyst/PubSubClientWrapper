#pragma once
#include <PubSubClient.h>

class PubSubClientWrapper : public PubSubClient{
  private:
  public:
    PubSubClientWrapper(Client& espc);

//    void sendStatsBoot(void);

    bool subscribe(String topic);
    bool subscribe(String topic, uint8_t qos);

    bool publish(     String topic, String   str);
    bool publish(     String topic, uint8_t  num);
    bool publish(     String topic, uint16_t num);
    bool publish(     String topic, uint32_t num);
    bool publish(     String topic, float    num);
    bool publish(const char* topic, String   str);
    bool publish(const char* topic, uint8_t  num);
    bool publish(const char* topic, uint16_t num);
    bool publish(const char* topic, uint32_t num);
    bool publish(const char* topic, float    num);
    bool publish(     String topic, String   str, bool retain);
    bool publish(     String topic, uint8_t  num, bool retain);
    bool publish(     String topic, uint16_t num, bool retain);
    bool publish(     String topic, uint32_t num, bool retain);
    bool publish(     String topic, float    num, bool retain);
    bool publish(const char* topic, String   str, bool retain);
    bool publish(const char* topic, uint8_t  num, bool retain);
    bool publish(const char* topic, uint16_t num, bool retain);
    bool publish(const char* topic, uint32_t num, bool retain);
    bool publish(const char* topic, float    num, bool retain);

    uint8_t rssiToPercentage(int32_t rssi);
    void ipToString(const IPAddress& ip, char * str);
};
