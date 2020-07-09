#include <Wire.h>
// The I2C LCD library
#include <LiquidCrystal_I2C.h>
// The menu wrapper library
#include <LCDMenuLib2.h>

// settings for LCD MENU
#define _LCDML_DISP_cols  20
#define _LCDML_DISP_rows  4

#define _LCDML_DISP_cfg_cursor                     0x7E   // cursor Symbol
#define _LCDML_DISP_cfg_scrollbar                  1      // enable a scrollbar

// The I2C LCD object
LiquidCrystal_I2C lcd(0x27,_LCDML_DISP_cols,_LCDML_DISP_rows); //0x27 on arduino uno v3 // 0x17 on teensy using pins 18,19 (scl0,sda0)

// LCDML
const uint8_t scroll_bar[5][8] = {
  {B10001, B10001, B10001, B10001, B10001, B10001, B10001, B10001}, // scrollbar top
  {B11111, B11111, B10001, B10001, B10001, B10001, B10001, B10001}, // scroll state 1
  {B10001, B10001, B11111, B11111, B10001, B10001, B10001, B10001}, // scroll state 2
  {B10001, B10001, B10001, B10001, B11111, B11111, B10001, B10001}, // scroll state 3
  {B10001, B10001, B10001, B10001, B10001, B10001, B11111, B11111}  // scrollbar bottom
};
void lcdml_menu_display();
void lcdml_menu_clear();
void lcdml_menu_control();
LCDMenuLib2_menu LCDML_0 (255, 0, 0, NULL, NULL); // root menu element (do not change)
LCDMenuLib2 LCDML(LCDML_0, _LCDML_DISP_rows, _LCDML_DISP_cols, lcdml_menu_display, lcdml_menu_clear, lcdml_menu_control);

// Rotary Encoder
//#define encoder0PinA  2
//#define encoder0PinB  3
//volatile unsigned int encoder0Pos = 0;

// Regular variables
const int photoTransistor = A0;
const int photoTransistorLED = 11;
const int switchPin = 2;
const int cameraFocusPin = 8;
const int cameraShutterPin = 7;
const int flashPin = 9;
const int solenoidPin = 10;
const int integratedLed = 13;
unsigned int cameraShutterDelay = 400;
unsigned int cameraShutterCloseDelay = 500; // 1000ms / shutter speed = ms  [20ms = 1/50, 16ms = 1/60]
unsigned int solenoidDelay = 150;
unsigned int dropDelay = 10; // how long to wait for the drop to fall into frame
String currentStatus = "";

int switchState = 0;
int enableDrop = 0;
int cameraState = 0;
int flashState = 0;
int integratedLedState = 0;
int solenoidState = 0;
int dropState = 0;
// drop detector
int dropCount = 0;
int dropMin = 1023;
int dropMax = 0;
int dropFound = 0; // did we catch a drop?

unsigned long previousMillis = 0;


// LCDML_0        => layer 0
// LCDML_0_X      => layer 1
// LCDML_0_X_X    => layer 2
// LCDML_0_X_X_X  => layer 3
// LCDML_0_...      => layer ...

// LCDML_add(id, prev_layer, new_num, lang_char_array, callback_function)
// Menu Setup
LCDML_add         (0  , LCDML_0         , 1  , "Delay"               , NULL);       // this menu function can be found on "LCDML_display_menuFunction" tab
LCDML_add         (1  , LCDML_0_1       , 1  , "Drop Delay"          , mFunc_drop_delay);                      // NULL = no menu function
LCDML_add         (2  , LCDML_0_1       , 2  , "Shutter Delay"       , mFunc_shutter_delay);                      // NULL = no menu function
LCDML_add         (3  , LCDML_0_1       , 3  , "Shutter Close Delay" , mFunc_shutter_close_delay);                      // NULL = no menu function
LCDML_add         (4  , LCDML_0_1       , 4  , "Solenoid Delay"      , mFunc_solenoid_delay);                      // NULL = no menu function
//LCDML_add         (3  , LCDML_0_2_1     , 2  , "P1 Settings"       , NULL);                    // NULL = no menu function
//LCDML_add         (4  , LCDML_0_2_1_2   , 1  , "Warm"              , NULL);                    // NULL = no menu function
//LCDML_add         (5  , LCDML_0_2_1_2   , 2  , "Cold"              , NULL);                    // NULL = no menu function
//LCDML_add         (6  , LCDML_0_2_1_2   , 3  , "Back"              , mFunc_back);              // this menu function can be found on "LCDML_display_menuFunction" tab
//LCDML_add         (7  , LCDML_0_2_1     , 3  , "Back"              , mFunc_back);              // this menu function can be found on "LCDML_display_menuFunction" tab
//LCDML_add         (8  , LCDML_0_2       , 2  , "Program 2"         , mFunc_p2);                // this menu function can be found on "LCDML_display_menuFunction" tab
//LCDML_add         (9  , LCDML_0_2       , 3  , "Back"              , mFunc_back);              // this menu function can be found on "LCDML_display_menuFunction" tab
//LCDML_add         (2 , LCDML_0         , 2  , "Screensaver"        , mFunc_screensaver);       // this menu function can be found on "LCDML_display_menuFunction" tab
LCDML_add         (5 , LCDML_0         , 3  , "Status"               , mFunc_status);       // this menu function can be found on "LCDML_display_menuFunction" tab
  // menu element count - last element id
  // this value must be the same as the last menu element
  #define _LCDML_DISP_cnt    5
  // create menu
  LCDML_createMenu(_LCDML_DISP_cnt);


void setup() {
//  250000;
//1000000
  // disable when not debugging
 // Serial.begin(1000000);
  // put your setup code here, to run once:
  pinMode(photoTransistor,INPUT);
  pinMode(photoTransistorLED,OUTPUT);
  
  pinMode(integratedLed, OUTPUT);
  pinMode(cameraFocusPin, OUTPUT);
  pinMode(cameraShutterPin, OUTPUT);
  pinMode(flashPin, OUTPUT);
  pinMode(solenoidPin, OUTPUT);
  //pinMode(switchPin, INPUT);
  // This is the I2C LCD object initialization.
  lcd.init();
  lcd.backlight();
  // Menu initialization.
  // set special chars for scrollbar
  lcd.createChar(0, (uint8_t*)scroll_bar[0]);
  lcd.createChar(1, (uint8_t*)scroll_bar[1]);
  lcd.createChar(2, (uint8_t*)scroll_bar[2]);
  lcd.createChar(3, (uint8_t*)scroll_bar[3]);
  lcd.createChar(4, (uint8_t*)scroll_bar[4]);
  
  // LCDMenuLib Setup
  LCDML_setup(_LCDML_DISP_cnt);
      
  
  // Some settings which can be used
  
  // Enable Menu Rollover
  LCDML.MENU_enRollover();
  
  // Enable Screensaver (screensaver menu function, time to activate in ms)
//  LCDML.SCREEN_enable(mFunc_screensaver, 10000); // set to 10 seconds

//  //pwm the ir led , this just makes it dimmer
//  analogWrite(photoTransistorLED, 127);
     digitalWrite(photoTransistorLED, HIGH);
}

void loop() {
  unsigned long currentMillis = millis();
//  switchState = digitalRead(switchPin);
//  Serial.print((String)"led state"+  digitalRead(integratedLed));
//  Serial.print((String)" camera state"+  digitalRead(cameraShutterPin));
//  Serial.print((String)" flash state"+  digitalRead(flashPin));
//  Serial.print((String)" Solenoid state"+  solenoidState + "\n");

//    delay(2);
//    digitalWrite(photoTransistorLED, LOW);
//    delay(2);
    
//  enableDrop = HIGH;
//  Serial.println((String)"switchState"+ switchState);
  if (enableDrop == HIGH){
    currentMillis = millis();
    // Check if drop crossed sensor
    int photovalue = analogRead(photoTransistor);
    //Serial.println((String)photovalue + ", dropCount" + (String)dropCount+ ", dropMin" + (String)dropMin+ ", dropMax" + (String)dropMax );
    if (photovalue > dropMax){
      dropMax = photovalue;
    }
    if (photovalue < dropMin){
      dropMin = photovalue;
    }
    if (photovalue <= 970 ){
      //Serial.println("we got one");
      dropFound = 1;
      dropCount++;
    }
    // reset everything first
    digitalWrite(cameraShutterPin, LOW);
    digitalWrite(cameraFocusPin, LOW); // Set focus to low as well to reset shutter
    digitalWrite(flashPin, LOW);
    digitalWrite(integratedLed, LOW);
    digitalWrite(solenoidPin, LOW);
    cameraState = 0;
    flashState = 0;
    integratedLedState = 0;
    solenoidState = 0;
    dropState = 0;
        
    // let camera reset
    if(currentMillis - previousMillis > 4000) {
      if(cameraState != 1){
        previousMillis = currentMillis;
//        Serial.println((String)"shutter currentMilis"+ currentMillis);
        currentStatus = (String)"shutter";
        digitalWrite(integratedLed, HIGH);
        digitalWrite(cameraShutterPin, HIGH);
        digitalWrite(cameraFocusPin, HIGH);
        cameraState = 1;
        integratedLedState = 1;
      }
    }
    // wait for shutter to open before trigger Solenoid water drop
    if((currentMillis - previousMillis) > cameraShutterDelay) {
      if (cameraState == 1 && solenoidState != 1 && flashState != 1 && dropState == 0){
//        Serial.println((String)"dropping water open currentMilis"+ currentMillis);
        currentStatus =(String)"dropping water open";
        previousMillis = currentMillis;   
        digitalWrite(solenoidPin, HIGH);
        solenoidState = 1;
        dropState = 1;
      }
    }
   // wait for solenoid delay miliseconds before shutting the solenoid so that we only get one drop
    if(currentMillis - previousMillis > (solenoidDelay)) {
      if (cameraState == 1 && solenoidState == 1 && flashState != 1 && dropState == 1){
        //Serial.println((String)"dropping water close currentMilis"+ currentMillis + (String)" total delay"+(cameraShutterDelay+solenoidDelay+dropDelay) );
        currentStatus = (String)"dropping water close";
        previousMillis = currentMillis;   
        digitalWrite(solenoidPin, LOW);
        solenoidState = 0;
      }
    }

    //check if we got a drop via sensor
    if (cameraState == 1 && solenoidState == 0 && flashState != 1 && dropState == 1){
      if(dropFound == 1){
        //reset the counter
        previousMillis = currentMillis;
        // set status
        currentStatus = (String)"Got one";
        dropFound = 1;
      }
    }
    
//    wait for shutter to open and drop to be dropped before trigger flash, we also wait for sensor to trigger then start the dropDelay "timer"
    //if(currentMillis - previousMillis > (cameraShutterDelay+solenoidDelay+dropDelay)) {
    if(currentMillis - previousMillis > (dropDelay)) {
      if (cameraState == 1 && solenoidState == 0 && flashState != 1 && dropState == 1 && dropFound == 1){
//        Serial.println((String)"flashing currentMilis"+ currentMillis);
        currentStatus = (String)"flashing";
        previousMillis = currentMillis;   
        digitalWrite(flashPin, HIGH);
        flashState = 1;
      }
    }
    // reset delay // so that the pin doesnt go high->low instantanenously
    // and in bulb mode how long we want the shutter open
    if(currentMillis - previousMillis > (cameraShutterCloseDelay+solenoidDelay+dropDelay)) {
        if( cameraState == 1 && flashState == 1 && dropState == 1 ){
          //Serial.println((String)"reset currentMilis"+ currentMillis);
          currentStatus = (String)"reset";
          previousMillis = currentMillis;  
          // reset
          digitalWrite(cameraShutterPin, LOW);
          digitalWrite(cameraFocusPin, LOW); // Set focus to low as well to reset shutter
          digitalWrite(flashPin, LOW);
          digitalWrite(integratedLed, LOW);
          digitalWrite(solenoidPin, LOW);
          cameraState = 0;
          flashState = 0;
          integratedLedState = 0;
          solenoidState = 0;
          dropState = 0;
          dropFound = 0;
      }
    }
  }
  else{
    digitalWrite(cameraShutterPin, LOW);
    digitalWrite(cameraFocusPin, LOW);
    digitalWrite(flashPin, LOW);
    digitalWrite(integratedLed, LOW);
    digitalWrite(solenoidPin, LOW);
  }

  // MENU LOOP
    LCDML.loop();
}
