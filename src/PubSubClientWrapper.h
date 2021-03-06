#pragma once
#include <PubSubClient.h>

class PubSubClientWrapper : public PubSubClient{
  private:
  public:
    PubSubClientWrapper(Client& espc);

//    void sendStatsBoot(void);

    bool publish(String topic, String str);
    bool publish(String topic, unsigned int num);
    bool publish(const char* topic, String str);
    bool publish(const char* topic, unsigned int num);

    bool publish(String topic, String str, bool retain);
    bool publish(String topic, unsigned int num, bool retain);
    bool publish(const char* topic, String str, bool retain);
    bool publish(const char* topic, unsigned int num, bool retain);
    uint8_t rssiToPercentage(int32_t rssi);
    void ipToString(const IPAddress& ip, char * str);
};
