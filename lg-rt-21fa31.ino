#include <Arduino.h>


#define RC5_ADDRESS 0x00
#define RC5_CARRIER_FREQUENCY_KHZ 38

#include <IRremote.h>

// The following table of defines was determined through experimentation rather than
// being derived from the original remote, which in my case was broken.
#define BTN_DIGIT_0              0x00                                            
#define BTN_DIGIT_1              0x01
#define BTN_DIGIT_2              0x02
#define BTN_DIGIT_3              0x03
#define BTN_DIGIT_4              0x04
#define BTN_DIGIT_5              0x05
#define BTN_DIGIT_6              0x06
#define BTN_DIGIT_7              0x07
#define BTN_DIGIT_8              0x08
#define BTN_DIGIT_9              0x09
#define BTN_UNKNOWN_0A           0x0A
#define BTN_UNKNOWN_0B           0x0B
#define BTN_STANDBY              0x0C  // Toggles power on/off
#define BTN_MUTE                 0x0D  // Toggles mute on/off
#define BTN_PSM                  0x0E  // PSM (Picture Status Memory): Cycles between Picture: Dynamic | Standard | Mild | Game | User
#define BTN_LIST                 0x0F  // Opens quick channel select
#define BTN_VOLUME_UP            0x10  // Volume Up
#define BTN_VOLUME_DOWN          0x11  // Volume Down
#define BTN_PICTURE              0x13  // Picture Button: Shows an unusual picture of the screen. (degause?)
#define BTN_AV                   0x15  // Puts TV in component mode.
#define BTN_SSM                  0x16  // SSM, shows "flat" on the scren.
#define BTN_UNKNOWN_17           0x17
#define BTN_UNKNOWN_18           0x18
#define BTN_UNKNOWN_19           0x19
#define BTN_UNKNOWN_1A           0x1A
#define BTN_UNKNOWN_1B           0x1B
#define BTN_UNKNOWN_1C           0x1C
#define BTN_UNKNOWN_1D           0x1D
#define BTN_UNKNOWN_1E           0x1E
#define BTN_UNKNOWN_1F           0x1F
#define BTN_CHANNEL_UP           0x20  // Channel Up
#define BTN_CHANNEL_DOWN         0x21  // Channel Down 
#define BTN_CHANNEL_PREVIOUS     0x22  // Channel Previous
#define BTN_UNKNOWN_23           0x23
#define BTN_SOUND                0x24  // Sound 
#define BTN_OK                   0x25  // OK
#define BTN_SLEEP                0x26  // Sleep
#define BTN_UNKNOWN_27           0x27
#define BTN_UNKNOWN_28           0x28
#define BTN_UNKNOWN_29           0x29
#define BTN_UNKNOWN_2A           0x2A
#define BTN_UNKNOWN_2B           0x2B
#define BTN_UNKNOWN_2C           0x2C
#define BTN_UNKNOWN_2D           0x2D
#define BTN_UNKNOWN_2E           0x2E
#define BTN_UNKNOWN_2F           0x2F
#define BTN_UNKNOWN_30           0x30
#define BTN_UNKNOWN_31           0x31
#define BTN_YELLOW_QVIEW         0x32   // (YELLOW) Q-view                       | SERVICE MODE: Cycle between options
#define BTN_UNKNOWN_33           0x33
#define BTN_BLUE_LIST            0x34   // (BLUE) List
#define BTN_UNKNOWN_35           0x35
#define BTN_GREEN_LANGUAGE       0x36   // (GREEN) Language Select (I/II/*)
#define BTN_RED_EYE              0x37   // (RED) Eye                             | SERVICE MODE: Changes to picture test mode
#define BTN_TV_AV                0x38   // Cycles between TV/AV/Component Mode.  | SERVICE MODE: Exit
#define BTN_UNKNOWN_3A           0x3A
#define BTN_MENU                 0x3B   // Menu - Cycle down between menu items. | SERVICE MODE: Switches input signals
#define BTN_TV                   0x3C   // Switch to TV input
#define BTN_SERVICE_MODE         0x3D   // Enter Service Mode                    | SERVICE MODE: Start service mode
#define BTN_UNKNOWN_3E           0x3E
#define BTN_UNKNOWN_3F           0x3F   // MAX: Commands are 6 bits. No value large than this works or should work with RC5?


#define IR_SEND_PIN 13


void setup() {
  
  Serial.begin(115200);
  delay(4000);
  IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK);
  Serial.print(F("Ready to send IR signals at pin "));
  Serial.println(IR_SEND_PIN);

  //IrSender.enableIROut(38); // Call it with 38 kHz to initialize the values printed below
  Serial.print(F("Send signal mark duration is "));
  Serial.print(IrSender.periodOnTimeMicros);
  Serial.print(F(" us, pulse correction is "));
  Serial.print(IrSender.getPulseCorrectionNanos());
  Serial.print(F(" ns, total period is "));
  Serial.print(IrSender.periodTimeMicros);
  Serial.println(F(" us"));
}

void loop() {

  while(Serial.available()){
    String command = Serial.readString();
    int commandInt = strtol(command.c_str(), 0, 16);
    Serial.print(F("Received string: "));
    Serial.print(command);
    Serial.print(F(" converted to int: "));
    Serial.println(commandInt);

    IrSender.sendRC5(RC5_ADDRESS, commandInt, 1, true);    
  }
}
