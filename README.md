# Requirements

Trigger box: something that generates intermittent TTL pulses (say every minute) to help synchronize the clocks of our various tools
1.	Box to LED light flash for Muse 
2.	Box to BNC  - for brain products 
3.	Box to Audio - for brain products [3-pin 2.5 mm phone jack; TTL (LVTTL) signals, 0 to +5 V (+ 3.3 V); active low]
4.	Box to DVXplorer  
i.	https://docs.inivation.com/hardware/hardware-advanced-usage/external-camera-sync.html
[The INPUT_SIGNAL port can be configured to detect rising edges, falling edges and pulses originating from another camera or electronic system, and when it detects such an occurence, a special data point is inserted into the data stream coming from the iniVation camera, with a very precise timestamp, allowing data from the camera to be put in relation with events happening externally.]
ii.	The pin lay out is also in the link above - our camera is DVXplorer 

# Hardware description
Hardware is based on the Adafruit Feather 32u4 operating add 3.3V.<br />
Battery power operated with buildin charger.<br />
Step up convertor 3.3V to 5V.<br />
Buffered 3.3V and 5V output's for pulse.

# Arduino ide
Add [board package](https://adafruit.github.io/arduino-board-index/package_adafruit_index.json) to the arduino ide.<br />
Source: [Adafruit](https://learn.adafruit.com/adafruit-feather-32u4-basic-proto/arduino-ide-setup)


