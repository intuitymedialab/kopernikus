
////////////////////////////////////////////////////////////////////////////////////

void mdSetAcc(int acc) {
  softSerial.write(CMD);                        // command byte
  softSerial.write(SET_ACCEL);
  softSerial.write(5);
}

void mdSetVel(int vel, int mot) {
  softSerial.write(CMD);
  if (mot == 1) softSerial.write(SET_SPEED1);
  if (mot == 2) softSerial.write(SET_SPEED2);
  softSerial.write(vel);
}

void mdGetVer(byte *v) {
  softSerial.write(CMD);
  softSerial.write(GET_VER);                    // Recieve version back
  delay(50);
  if (softSerial.available() > 0) *v = softSerial.read();
}

void mdGetErr(byte *err) {
  softSerial.write(CMD);
  softSerial.write(GET_ERROR);                  // Recieve error byte back
  delay(50);
  if (softSerial.available() > 0) *err = softSerial.read();
}

void mdGetBat(byte *bv, byte *c1, byte *c2) {
  softSerial.write(CMD);
  softSerial.write(GET_VI);                     // Recieve battery volts and both motor currents back
  delay(50);
  if (softSerial.available() > 2)
  {
    *bv = softSerial.read();
    *c1 = softSerial.read();
    *c2 = softSerial.read();
  }
}

void mdGetEnc(int enr) {
  
  softSerial.write(CMD);
  if (enr == 1) softSerial.write(GET_ENC1);                // Recieve encoder 1 value
  if (enr == 2) softSerial.write(GET_ENC2);
  delay(50);
  long res = 0;
  while (softSerial.available() < 4) {}
  res =  softSerial.read();
  res  <<= 8;
  res += softSerial.read();
  res  <<= 8;
  res += softSerial.read();
  res  <<= 8;
  res += softSerial.read();
  Serial.print(res);
  if (enr == 1) {
    enc1 = res;
  }
  else if (enr == 2) {
    enc2 = res;
  }
}

void mdPrint() {
  Serial.println("------------Motor Info");
  Serial.println();
  Serial.print("Rev: ");                     // Display data to the screen
  Serial.println(ver, DEC);
  Serial.print("Battery V: ");
  Serial.println(bat_volt, DEC);
  Serial.println();

  Serial.print("Mot 1 I: ");
  Serial.print(mot1_cur);
  Serial.print("Mot 2 I: ");
  Serial.print(mot2_cur);
  Serial.println();
}

void clearSoftSerial(){
  while(softSerial.available()){
    softSerial.read();
  }
}


void mdSetDriveMode(int mode){
  softSerial.write(CMD);
  softSerial.write(SET_MODE);
  softSerial.write(mode);
}

