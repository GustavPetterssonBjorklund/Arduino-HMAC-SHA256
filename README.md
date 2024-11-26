# Arduino-HMAC-SHA256
### This library was made by GustavPetterssonBjorklund to simplify the use of the ArduinoBearSSL library for HMAC sha256 hashing.
### This library was only and tested on the esp8266 hardware, but should work on other hardware (ex. esp32, Arduino UNO, etc.)

### How to install: 
- Clone the repository into your Arduino/libraries folder

## REQUIREMENTS
- ArduinoBearSSL : https://github.com/arduino-libraries/ArduinoBearSSL.git

## Example use case:
```cpp
// include the Arduino-HMAC-SHA256.h
#include <Arduino-HMAC-SHA256.h>

// message, secretKey do not need to be static
#define message "Hello world!"
#define secretKey "safehashsalt"

void setup() {
  // make instance of the library handler
  HMAC_SHA256 hmac;
  // get the hashHex (lowercase) with the given message and secretKey 
  String hashHex = hmac.GET_HMAC_SHA_256_HASH(message, secretKey);
  // print hashHex
  Serial.println(hashHex);
}

void loop() {
  // nothing to loop
}
```

