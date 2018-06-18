
////////////////////////////////////////////////////////////////////////////////////

int projectorDistToGo() {
  return projectorTarget - projectorPos;
}

// Calculates degrees to PWM Signal
int calcProjectorDegree(int inVal) {
  return map(inVal, 0, 180, 720, 2380);
}
