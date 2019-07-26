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
printf("1. mqtt connect failed\n");
return FALSE;
}

if(!mqttCreateNode(&client, devicePw)) {
printf("2. mqtt create node failed\n");
return FALSE;
}

if(!mqttCreateRemoteCSE(&client)) {
printf("3. mqtt create remote cse failed\n");
return FALSE;
}
if(!mqttCreateContainer(&client, container)) {
printf("4. mqtt create container failed\n");
return FALSE;
}
if(!mqttCreateMgmtCmd(&client, "turnOn")) {
printf("5. mqtt create mgmt cmd failed\n");
return FALSE;
}


mqttDisconnect(&client);

return TRUE;
}

