#pragma once
#include <PubSubClient.h>

class PubSubClientWrapper : public PubSubClient{
  private:
  public:
    PubSubClientWrapper(Client& espc);

//    void sendStatsBoot(void);

    bool publish(StringSumHelper topic, String str);
    bool publish(StringSumHelper topic, unsigned int num);
    bool publish(const char* topic, String str);
    bool publish(const char* topic, unsigned int num);

    bool publish(StringSumHelper topic, String str, bool retain);
    bool publish(StringSumHelper topic, unsigned int num, bool retain);
    bool publish(const char* topic, String str, bool retain);
    bool publish(const char* topic, unsigned int num, bool retain);
    uint8_t rssiToPercentage(int32_t rssi);
    void ipToString(const IPAddress& ip, char * str);
};
