
////////////////////////////////////////////////////////////////////////////////////

// Set acceleration value
void setAccel(CommandParameter &Parameters) {
  int val = Parameters.NextParameterAsInteger();
  Serial.println("setting accel: " + String(val));
  mdSetAcc(val);
}

// Set motorspeed 1
void setVel1(CommandParameter &Parameters) {
  int val = Parameters.NextParameterAsInteger();
  if (!remoteOn) {
    mdSetVel(val, 1);
  }
}

// Set motorspeed 2
void setVel2(CommandParameter &Parameters) {
  int val = Parameters.NextParameterAsInteger();
  if (!remoteOn) {
    mdSetVel(val, 2);
  }
}

// Get encoder value 1
void getEnc1(CommandParameter &Parameters) {
  mdGetEnc(1);
}

// Reset encoders
void resetEnc(CommandParameter &Parameters) {
  int val = Parameters.NextParameterAsInteger();
  softSerial.write(CMD);
  softSerial.write(RESET_ENC);
}

// Get encoder value 2
void getEnc2(CommandParameter &Parameters) {
  mdGetEnc(2);

}

// Stop both motors
void stopMotors(CommandParameter &Parameters) {
  mdSetVel(128, 1);
  mdSetVel(128, 2);
}

// Move projector
void moveProjector(CommandParameter &Parameters) {
  projectorTarget = Parameters.NextParameterAsInteger();
  Serial.println(projectorPos);
  projector.write(projectorTarget);
}

// Discard all data on software serial port
void cleanSoftSerial() {
  while (softSerial.available()) {
    softSerial.read();
  }
}

