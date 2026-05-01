## Description
The pulse generator is designed to synchronize different devices in the Codelab.<br>
Synchronization is based on a simple principle: all devices receive a pulse every 60 seconds.

## Hardware description
The device currently provides ports for Brain Products (3 ports), DVXplorer (1 port), Muse (2 ports), and Spare (2 ports).<br>
Different voltage levels (3.3V or 5V) are supported. For the Spare ports, the voltage can be configured by placing the appropriate resistors on the PCB.<br>
The device is powered by an internal rechargeable Li-ion battery.

## Operation
After powering up, the device sends **three pulses** to indicate startup.<br>
A manual pulse can be triggered by pressing the button; this generates **two pulses**.<br>
Every 60 seconds, a synchronization **one pulse** is sent automatically.<br>
It is also possible to send **5 to 9** pulses via the serial port for special events.<br>

## Serial events
Serial communication requires an Arduino driver. On modern Windows systems, this driver is usually installed automatically.<br>
The serial port must be opened with the following settings: 9600 baud, 8 data bits, no parity, 1 stop bit (9600, 8N1).<br>
Send ASCII characters 5, 6, 7, 8, or 9 to generate the corresponding number of pulses.<br>

## Pulse timing
Each pulse has a width of 100 ms.<br>
If multiple pulses are sent, the interval between pulses is 150 ms.<br>

## Serial Connection
The serial port must be opened with the following settings: 9600 baud, 8 data bits, no parity, 1 stop bit (9600, 8N1)<br>
Send ASCII characters 5, 6, 7, 8, or 9 to generate the corresponding number of pulses.<br>

The UsbParMarker can operate in two modes: **Data Mode** and **Command Mode**. In Command mode, it can execute various functions. Changing between functions is done by (re)opening the serial port using different baud rates:

 - **Data Mode**: 9600 baud.
 - **Command Mode**: 4800 baud.

### Command Mode
In command mode, the UsbParMarker can execute various commands:

| Function | Command | Returns | Type |Note
| ------------- | ------------- | ------------- | ------------- | ------------- |
| Version  | V |Json String with device info   |string| |
| Ping  | P    | Pong,Device | string ||



