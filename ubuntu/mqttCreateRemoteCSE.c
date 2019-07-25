#include <stdio.h>
#include <string.h>
#include "./libok/thingplug.h"
#include "./libok/secret.h"

int main()
{
    MQTTClient client;

    char addr[]		    = "tcp://mqtt.sktiot.com:1883";
    char id[]		    = ID;
    char pw[]		    = KEY;
    char deviceId[]	    = DEVICEID;
    char devicePw[] 	= DEVICEPW;
    char container[]	= "temperature";

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

