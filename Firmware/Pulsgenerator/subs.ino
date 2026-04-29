void writeStringToEEPROM(int addrOffset, const String &strToWrite) {
  byte len = strToWrite.length();
  EEPROM.write(addrOffset, len);
  for (int i = 0; i < len; i++) {
    EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
  }
}

String readStringFromEEPROM(int addrOffset) {
  int newStrLen = EEPROM.read(addrOffset);
  char data[newStrLen + 1];
  for (int i = 0; i < newStrLen; i++) {
    data[i] = EEPROM.read(addrOffset + 1 + i);
  }
  data[newStrLen] = '\0';  // the character may appear in a weird way, you should read: 'only one backslash and 0'
  return String(data);
}

void DumpMyInfo() {
  Serial.print("{\"Version\":\"");
  Serial.print(Version);
  Serial.print("\",");
  Serial.print("\"Serialno\":\"");
  Serial.print(Serialno);
  Serial.print("\",");
  Serial.println("\"Device\":\"Pulsgenerator\"}");
  //Serial.write(ETX);
}

void handlecommands() {
  switch (Serial.read()) {
    case 'V':
      DumpMyInfo();
      break;
    case 'P':
      Serial.println("Pong,Pulsgenerator");
      break;

    default:
      Serial.println("Unknown command");
      break;
  }
}


void buttonChanged(int state) {  //Manual button trigger handeling

  if (state == 0) {  //Button pressed
    sendPulses(2);  //Manual pulse
  }
   else {
  }
}

float batteryvoltage(){         //It doesn't make much sense to measure battery voltage when connected to pc over usb. 
  float measuredvbat = analogRead(V_BAT);
  measuredvbat *= 2;    // Multiply by 2 because of the voltage divider
  measuredvbat *= 3.3;  // Multiply by 3.3V, our reference voltage
  measuredvbat /= 1024; // Convert to voltage
  return measuredvbat;
}