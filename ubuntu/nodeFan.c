#include <stdio.h>
#include <string.h>
#include "./libok/thingplug.h"

void myFunction(char * strCon);

int main()
{
MQTTClient client;

    char addr[]		    = "tcp://mqtt.sktiot.com:1883";
    char id[]		    = "duwonet";
    char pw[]		    = "aGo4RldEQmc4SHRWZWtSMG82WHZjMnU0Sk9ZNkpJZGkxWGw0eDdweHJ1T0dvNWlER2pvSWE5djdOVWM5RjRDcg==";
    char deviceId[]	    = "duwonet_190724fan";
    char devicePw[] 	= "123456";
    //char container[]	= "temperature";
    char targetDeviceId[] = "duwonet_190724lab";
    char targetContainer[] = "temperature";
    char notificationName[] = "Noti_3";

    strcpy(passCode, "RC00000000000000386162");
    strcpy(strExt, "ND00000000000000007424");
    strcpy(strDkey, "b0JtNVZnUUNkVEc0b1NxbnoxaEtGZHc1dWpudHNIVDFvbmlxQjZiNjRsQno5Y1pqL1FVMkFNYnBpTldENXQrcQ==");


    if(!mqttConnect(&client, addr, id, pw, deviceId)) {
    printf("1. mqtt connect failed\n");
    return FALSE;
    }
/* 
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
*/
/* 
    if(!mqttCreateMgmtCmd(&client, "turnOn")) {
        printf("5. mqtt create mgmt cmd failed\n");
        return FALSE;
    }

    if(!mqttCreateMgmtCmd(&client, "turnOff")) {
        printf("5. mqtt create mgmt cmd failed\n");
        return FALSE;
    }
*/
#if 1 //Creat subscription
    if(!mqttSubscribe(&client, targetDeviceId, targetContainer, notificationName, myFunction)){
        printf("7. mqtt subscribe failed\n");
        return FALSE;
    }
#else //Delet subcsription
    if(!mqttDeleteSubscribe(&client, targetDeviceId, notificationName, targetContainer)){
        printf("8. mqtt delete subscribe failed\n");
        return FALSE;
    }
#endif


    while(1){
        step = UPDATE_MGMT_CMD;
        
    }
    mqttDisconnect(&client);

    return TRUE;
}

void myFunction(char * strCon)
{
	printf("notificaion arrived : %s\n",strCon);
}