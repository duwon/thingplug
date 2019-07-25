
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "./libok/thingplug.h"
#include "./libok/temperature.h"
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
    if(!mqttCreateMgmtCmd(&client)) {
        printf("5. mqtt create mgmt cmd failed\n");
        return FALSE;
    }

    //if(!mqttCreateContentInstance(&client, "30")) {
    //printf("6. mqtt create content instance failed\n");
    //return FALSE;
    //}
    //printf("Send Fake Data Success\n");

    for (int i = 0; i < 3; i++)
    {
        float temp = getTempData();
        char strTemp[100];
        sprintf(strTemp, "%f", temp);
        //print(temp);
        mqttCreateContentInstance(&client, strTemp);
        sleep(1);
    }

    mqttDisconnect(&client);

    return TRUE;
}

