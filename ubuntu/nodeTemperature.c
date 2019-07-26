#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "./libok/thingplug.h"
#include "./libok/temperature.h"

void myFunction(char * strCon);

int main()
{
    MQTTClient client;

    char addr[]		    = "tcp://mqtt.sktiot.com:1883";
    char id[]		    = "duwonet";
    char pw[]		    = "aGo4RldEQmc4SHRWZWtSMG82WHZjMnU0Sk9ZNkpJZGkxWGw0eDdweHJ1T0dvNWlER2pvSWE5djdOVWM5RjRDcg==";
    char deviceId[]	    = "duwonet_190724lab";
    char devicePw[] 	= "123456";
    char container[]	= "temperature";
    char passCode[] 	= "RC00000000000000386151";
    char strExt[]       = "ND00000000000000007413";
    char strDkey[]      = "eWdKZUJLUkFzMGhHZ2t2d1oxcU9ENENLM2oyMGZoYVhxd1dqd0VsMWtDL3pVb0pqeFZZNUVNMGRFSmkxRHQ3WA==";

    
    if(!mqttConnect(&client, addr, id, pw, deviceId)) {
        printf("1. mqtt connect failed\n");
        return FALSE;
    }

    for (int i = 0; i < 3; i++)
    {
        float temp = getTempData();
        char strTemp[100];
        sprintf(strTemp, "%f", temp);

        MQTTClient_deliveryToken token;
        MQTTClient_message pubmsg = MQTTClient_message_initializer;
        int rc = 0;
        step = CREATE_CONTENT_INSTANCE_REQUESTED;

        char strRi[128] = "";
        generateRi(strRi);

        strcpy(dataName, "text");	// data type
        //sprintf(mqttRemoteCSE, frameMqttRemoteCSE, APP_EUI, deviceId);
        sprintf(mqttContainer, frameMqttContainer, mqttRemoteCSE, container);

        sprintf(bufRequest, frameCreateContentInstance, 
        mqttContainer, deviceId, strRi, strDkey, dataName, (char *)&strTemp);

        printf("5. Create Content Instance :\n payload=%s\n", bufRequest);
        pubmsg.payload 	    = bufRequest;
        pubmsg.payloadlen 	= strlen(bufRequest);
        pubmsg.qos 		    = QOS;
        pubmsg.retained 	= 0;
        MQTTClient_publishMessage(client, mqttPubPath, &pubmsg, &token);
        

        printf("Waiting for publication\n");
        rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
        if(rc!=MQTTCLIENT_SUCCESS) {
            printf("Publish Failed\n\n"); 
        }
        else
        {
            printf("Publish Success\n\n");
        }

        sleep(10);
    }

    mqttDisconnect(&client);

    return TRUE;
}

void myFunction(char * strCon)
{
	printf("notificaion arrived : %s\n",strCon);
}