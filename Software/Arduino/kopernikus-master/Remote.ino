
////////////////////////////////////////////////////////////////////////////////////

boolean rcValid(){
  boolean ch1valid = ((rc_values[RC_CH1] > 0) && (rc_values[RC_CH1] < 2200));
  boolean ch2valid = ((rc_values[RC_CH2] > 0) && (rc_values[RC_CH2] < 2200));
  boolean ch3valid = ((rc_values[RC_CH3] > 0) && (rc_values[RC_CH3] < 2200));
  boolean ch4valid = ((rc_values[RC_CH4] > 0) && (rc_values[RC_CH4] < 2200));
  return (ch1valid && ch2valid && ch3valid && ch4valid);
}

void resetRcValues(){
  noInterrupts();

  rc_shared[RC_CH1] = 0;
  rc_shared[RC_CH2] = 0;
  rc_shared[RC_CH3] = 0;
  rc_shared[RC_CH4] = 0;
  
  rc_values[RC_CH1] = 0;
  rc_values[RC_CH2] = 0;
  rc_values[RC_CH3] = 0;
  rc_values[RC_CH4] = 0;
  
  interrupts();
  }

void processRemote() {
    int speedScale = map(rc_values[RC_CH2],992,2008,0,128);
    speedScale = max(0, speedScale);
    speedScale = min(128, speedScale);
    
    //int speedScale = (int)(((rc_values[RC_CH2] - 992) / 2008.0) * 127);

    // remove noise around the min and max values
    int totalSpeed = map(rc_values[RC_CH1], 1004, 2000, 128-speedScale, 128+speedScale);
    totalSpeed = max(0, totalSpeed);
    totalSpeed = min(255, totalSpeed);

    // remove noise around position zero (128)
    if (abs(totalSpeed - 128) < 5) {
      totalSpeed = 128;
    }


    // remove noise around the min and max values
    int turnSpeed = map(rc_values[RC_CH3], 989, 1980, 128-speedScale, 128+speedScale);
    turnSpeed = max(0, turnSpeed);
    turnSpeed = min(255, turnSpeed);

    // remove noise around position zero (128)
    if (abs(turnSpeed - 128) < 5) {
      turnSpeed = 128;
    }

    int projectorTargetTemp = map(rc_values[RC_CH4],960,2000,0,180);
    projectorTargetTemp = max(0, projectorTargetTemp);
    projectorTargetTemp = min(180, projectorTargetTemp);
    projectorTarget = projectorTargetTemp;

    mdSetVel(totalSpeed,1);
    mdSetVel(turnSpeed,2);
    
    Serial.print("turn: ");
    Serial.println(turnSpeed);
    Serial.print("total: ");
    Serial.println(totalSpeed);
    Serial.print("scale: ");
    Serial.println(speedScale);
}

