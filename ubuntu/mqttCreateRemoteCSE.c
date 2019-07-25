#include <stdio.h>
#include <string.h>
#include "./libok/thingplug.h"

int main()
{
    MQTTClient client;

    if(!mqttConnect(&client, addr, id, pw, deviceId)) {
        printf("0. mqtt connect failed\n");
        return FALSE;
    }

    if(!mqttCreateNode(&client, devicePw)) {
        printf("1. mqtt create node failed\n");
        return FALSE;
    }

    if(!mqttCreateRemoteCSE(&client)) {
        printf("2. mqtt create remote cse failed\n");
        return FALSE;
    }

    printf("Create Remote CSE Success\n");

    mqttDisconnect(&client);

return TRUE;
}

