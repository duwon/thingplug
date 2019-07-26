from urllib2 import Request, urlopen



values = """
<?xml version="1.0" encoding="UTF-8"?>
<m2m:mgc 
    xmlns:m2m="http://www.onem2m.org/xml/protocols" 
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
    <exe>true</exe>
    <cmt>turnOn</cmt>
    <ext>ND00000000000000007424</ext>
    <exra>0x00</exra>
</m2m:mgc>"""



headers = {

  'Accept': 'application/xml',

  'locale': 'en',

  'X-M2M-RI': 'duwonet_190724fan_1564118890',

  'X-M2M-Origin': 'duwonet_190724fan',

  'Content-Type': 'application/vnd.onem2m-prsp+xml',

  'uKey': 'aGo4RldEQmc4SHRWZWtSMG82WHZjMnU0Sk9ZNkpJZGkxWGw0eDdweHJ1T0dvNWlER2pvSWE5djdOVWM5RjRDcg=='

}

request = Request('http://thingplugtest.sktiot.com:9000/thingplug/v1_0/mgmtCmd-duwonet_190724fan_turnOff', data=values, headers=headers)

request.get_method = lambda: 'PUT'



response_body = urlopen(request).read()

print response_body