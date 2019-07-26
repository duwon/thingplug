from urllib2 import Request, urlopen



headers = {

  'Accept': 'application/xml',

  'locale': 'en',

  'X-M2M-RI': 'duwonet_190724fan_1564118890',

  'X-M2M-Origin': 'duwonet_190724fan'

}

request = Request('http://thingplugtest.sktiot.com:9000/thingplug/v1_0/mgmtCmd-duwonet_190724fan_turnOff', headers=headers)

request.get_method = lambda: 'DELETE'



response_body = urlopen(request).read()

print response_body