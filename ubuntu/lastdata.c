
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "./libok/thingplug.h"
#include "./libok/temperature.h"



int main()
{
MQTTClient client;

    char addr[]		    = "tcp://mqtt.sktiot.com:1883";
    char id[]		    = "duwonet";
    char pw[]		    = "aGo4RldEQmc4SHRWZWtSMG82WHZjMnU0Sk9ZNkpJZGkxWGw0eDdweHJ1T0dvNWlER2pvSWE5djdOVWM5RjRDcg==";
    char deviceId[]	    = "duwonet_190724fan";
    char devicePw[] 	= "123456";

    strcpy(passCode, "RC00000000000000386162");
    strcpy(strExt, "ND00000000000000007424");
    strcpy(strDkey, "b0JtNVZnUUNkVEc0b1NxbnoxaEtGZHc1dWpudHNIVDFvbmlxQjZiNjRsQno5Y1pqL1FVMkFNYnBpTldENXQrcQ==");


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

if(!mqttCreateLatest(&client)){
printf("7. mqtt Latest failed\n");
return FALSE;
}

for(int i = 0; i < 10; i++){
sleep(1);
}


mqttDisconnect(&client);

return TRUE;
}

