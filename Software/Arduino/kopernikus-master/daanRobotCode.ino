
////////////////////////////////////////////////////////////////////////////////////

#include <ServoTimer2.h>
#include <CommandHandler.h>
#include <EnableInterrupt.h>
#include <AltSoftSerial.h>

////////////////////////////////////////////////////////////////////////////////////

// PWM Pin for projector

#define PROJECTORPIN     11

// The projector servo is handled by Timer 2 to avoid jitter
ServoTimer2 projector;

unsigned long lastProjectorTime;
int projectorTarget = 90;
int projectorPos = 90;
int projectorDeltaTime = 10;

////////////////////////////////////////////////////////////////////////////////////

// MD 25 (Motor driver)

#define CMD        (byte)0x00            // MD49 command address of 0                                 
#define GET_VER          0x29
#define GET_ENC1         0x23
#define GET_ENC2         0x24
#define GET_VI           0x2C
#define GET_ERROR        0x2D
#define SET_ACCEL        0x33
#define SET_SPEED1       0x31
#define SET_SPEED2       0x32
#define SET_MODE         0x34
#define RESET_ENC        0x35

byte bat_volt, mot1_cur, mot2_cur = 0;
byte ver = 0;
byte error = 0;
float vel_l, vel_r;

long enc1 = 0;
long enc2 = 0;

////////////////////////////////////////////////////////////////////////////////////

// RC REMOTE

// Pins for receiving remote control commands
#define RC_NUM_CHANNELS  4

// channels:
// 1 - right stick vertical -> speed
// 2 - right potentiometer -> speed scale
// 3 - left stick horizontal -> turn
// 4 - left potentiometer -> projector

#define RC_CH1  0
#define RC_CH2  1
#define RC_CH3  2
#define RC_CH4  3

#define RC_CH1_INPUT  5
#define RC_CH2_INPUT  6
#define RC_CH3_INPUT  7
#define RC_CH4_INPUT  4


uint16_t rc_values[RC_NUM_CHANNELS];
uint32_t rc_start[RC_NUM_CHANNELS];
volatile uint16_t rc_shared[RC_NUM_CHANNELS];

// used to track whether remote has been used before in this session
boolean remoteOn = false;
unsigned long rcLastTime;

////////////////////////////////////////////////////////////////////////////////////

CommandHandler<> SerialCommandHandler;
AltSoftSerial softSerial;

////////////////////////////////////////////////////////////////////////////////////

void setup() {

  // USB connection
  Serial.begin(38400);
  SerialCommandHandler.AddCommand(F("setAccel"), setAccel);
  SerialCommandHandler.AddCommand(F("setVel1"), setVel1);
  SerialCommandHandler.AddCommand(F("setVel2"), setVel2);
  SerialCommandHandler.AddCommand(F("getEnc1"), getEnc1);
  SerialCommandHandler.AddCommand(F("getEnc2"), getEnc2);
  SerialCommandHandler.AddCommand(F("stopMotors"), stopMotors);
  SerialCommandHandler.AddCommand(F("setProj"), moveProjector);
  SerialCommandHandler.AddCommand(F("rstEnc"), resetEnc);

  // Connection to MD25 (Pins 8 & 9)
  softSerial.begin(19200);
  softSerial.write(RESET_ENC);
  cleanSoftSerial();

  // Inputs from remote control
  pinMode(RC_CH1_INPUT, INPUT);
  pinMode(RC_CH2_INPUT, INPUT);
  pinMode(RC_CH3_INPUT, INPUT);
  pinMode(RC_CH4_INPUT, INPUT);

  enableInterrupt(RC_CH1_INPUT, calc_ch1, CHANGE);
  enableInterrupt(RC_CH2_INPUT, calc_ch2, CHANGE);
  enableInterrupt(RC_CH3_INPUT, calc_ch3, CHANGE);
  enableInterrupt(RC_CH4_INPUT, calc_ch4, CHANGE);

  // Initialize and reset projector (center position)
  pinMode(PROJECTORPIN, OUTPUT);
  projector.attach(PROJECTORPIN);
  projector.write(calcProjectorDegree(projectorPos));

  // Reset timers
  lastProjectorTime = millis();
  rcLastTime = millis();

  Serial.println("Ready");
  Serial.println("Waiting for commands...");
}

void loop() {
  SerialCommandHandler.Process();

  if (rcLastTime + 200 < millis()) {
    rcLastTime = millis();
    rc_read_values();
    if (rcValid()) {
      Serial.println("valid");
      if (!remoteOn) {
        remoteOn = true;
        Serial.println("Remote control connected - disabling Serial control");
        remoteOn = true;
        mdSetDriveMode(2);
      }
      processRemote();
      Serial.println(rc_values[RC_CH1]);
      Serial.println(rc_values[RC_CH2]);
      Serial.println(rc_values[RC_CH3]);
      Serial.println(rc_values[RC_CH4]);
      Serial.println("---");
      resetRcValues();
    }
    else if (remoteOn) {
      remoteOn = false;
      mdSetDriveMode(0);
      Serial.println("Remote control disconnected - enabling Serial control");
    }
  }

  if (projectorPos != projectorTarget) {

    if (lastProjectorTime + projectorDeltaTime < millis()) {
      lastProjectorTime = millis();

      if (projectorPos < projectorTarget) {
        projectorPos++;
      }
      else {
        projectorPos--;
      }
      Serial.println(projectorPos);
      projector.write(calcProjectorDegree(projectorPos));
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////


