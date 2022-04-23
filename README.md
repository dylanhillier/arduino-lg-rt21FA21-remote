# arduino-lg-rt21FA31-remote

![alt text](doc/LG_6710V00090D.jpg?raw=true "LG 6710V00090D Remote")


Arduino sketch for remote control of LG RT-21FA31 CRT TV.
The part number for the remote control is 6710V00090D.
There is an lircd.conf file which is associated with this remote, however it would need to be expanded to include equivalent functionality found within this sketch. The config file can be found here: http://lirc.sourceforge.net/remotes/lg/6710V00090D

This remote control appears to use Phillips RC5 with address 0 on carrier of 38kHz, _*NOT 36kHz*_.
For this to work you either need to locally modify Arduino-IRremote to run at 38kHz, or use the fork found here: https://github.com/dylanhillier/Arduino-IRremote which allows you to configure the carrier frequency as shown in the following snippet:


```
#define RC5_ADDRESS 0x00
#define RC5_CARRIER_FREQUENCY_KHZ 38

#include <IRremote.h>

```

