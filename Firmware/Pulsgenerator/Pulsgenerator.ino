/*
Puls Generato Arko Ghosh Codelab for HW version 1
Adafruit Feather 32u4 @ 8Mhz
No need to disable the TXLED must in the Feather, already done by Adafruit

 20260420  1.0 Initial release

*/

#include <EEPROM.h>
#include <ButtonDebounce.h>

//define
#define MANUAL_PULSE_BUTTON 4  //PD4
#define LED_PULSE 30           //PD5
#define ENABLE_STEPUP 12       //PD6
#define ENABLE_BUFFER 6        //PD7
#define V_BAT A5               //ADC0


//Globals
const String SwVer = "SW1.0";
const String Version;
const String Serialno;
const String HwVer;
unsigned long time_now = 0;
unsigned int PULSE_INTERVAL = 10000;  //ms

//Instance
ButtonDebounce button(MANUAL_PULSE_BUTTON, 10);

void setup() {
  //writeStringToEEPROM(10, "S12345");  //Use ones to program te serial number in the eeprom of the device
  //writeStringToEEPROM(20, "HW1");     //Use ones to program the hardware version in the eeprom of the device
  pinMode(LED_PULSE, OUTPUT);
  pinMode(ENABLE_STEPUP, OUTPUT);
  pinMode(ENABLE_BUFFER, OUTPUT);

  DDRB = 0xFF;  //PortD all pins output
  PORTB = 0x00;
  Serial.begin(9600);  // opens serial port, sets data rate to 115200 bps
  Serialno = readStringFromEEPROM(10);
  HwVer = readStringFromEEPROM(20);
  Version = String(HwVer + ":" + SwVer);  // Set HW version always
  button.setCallback(buttonChanged);      //callback switch for marker sending
  delay(2000);
  digitalWrite(ENABLE_STEPUP, HIGH);
  digitalWrite(ENABLE_BUFFER,LOW); //Inverted LOW=on, HIGH=off
  delay(2000);
  sendPulses(3);  // 3 pulses indicating start up of this device
}



void loop() {
  time_now = millis();

  while (millis() < time_now + PULSE_INTERVAL) {  //Main loop, non blocking
    button.update();                              //scan Trigger button

    if (Serial.baud() == 9600) {  //data mode
      if (Serial.available() > 0) {
        int temp = Serial.read();
        if (temp > 52 && temp < 58) {  //Data betweeen ascii-53 (5) and ascii-57 (9).
          sendPulses(temp - 48);       //Convert ascii to int and send pulses 5~9
        }
      }
    } else if (Serial.baud() == 4800) {  //command mode

      if (Serial.available() > 0) {
        handlecommands();
      }
    }
  }
  sendPulses(1);  // Send every PULSE_INTERVAL 1 puls, 1 puls only
}

void sendPulses(byte Pulses) {
  for (int i = 1; i <= Pulses; i++) {
    digitalWrite(LED_PULSE, HIGH);
    PORTB = 255;
    delay(100);
    digitalWrite(LED_PULSE, LOW);
    PORTB = 0;
    delay(150);
  }
}
