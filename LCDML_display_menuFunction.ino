/* ===================================================================== *
 *                                                                       *
 * Menu Callback Function                                                *
 *                                                                       *
 * ===================================================================== *
 *
 * EXAMPLE CODE:

// *********************************************************************
void your_function_name(uint8_t param)
// *********************************************************************
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // setup
    // is called only if it is started

    // starts a trigger event for the loop function every 100 milliseconds
    LCDML.FUNC_setLoopInterval(100);
  }

  if(LCDML.FUNC_loop())           // ****** LOOP *********
  {
    // loop
    // is called when it is triggered
    // - with LCDML_DISP_triggerMenu( milliseconds )
    // - with every button status change

    // check if any button is pressed (enter, up, down, left, right)
    if(LCDML.BT_checkAny()) {
      LCDML.FUNC_goBackToMenu();
    }
  }

  if(LCDML.FUNC_close())      // ****** STABLE END *********
  {
    // loop end
    // you can here reset some global vars or delete it
  }
}


 * ===================================================================== *
 */

// *********************************************************************
void mFunc_drop_delay(uint8_t param)
// *********************************************************************
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // update LCD content
    lcd.setCursor(0, 0); // set cursor
    lcd.print("drop delay:"); // print change content
  }

  if(LCDML.FUNC_loop())
  {
    if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
    {
      //LCDML.FUNC_goBackToMenu();  // leave this function
       if (LCDML.BT_checkDown()){
          dropDelay = dropDelay - 1;
       }
       if (LCDML.BT_checkUp()){
       dropDelay = dropDelay + 1;
       } 
    }
    lcd.setCursor(11, 0); // set cursor
    lcd.print("      ");
    lcd.setCursor(11, 0); // set cursor
    lcd.print(dropDelay);
  }

  if(LCDML.FUNC_close())
  {
    LCDML.FUNC_goBackToMenu();
  }
}

// *********************************************************************
void mFunc_shutter_delay(uint8_t param)
// *********************************************************************
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // update LCD content
    lcd.setCursor(0, 0); // set cursor
    lcd.print("shutter delay:"); // print change content
  }

  if(LCDML.FUNC_loop())
  {
    if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
    {
      //LCDML.FUNC_goBackToMenu();  // leave this function
       if (LCDML.BT_checkDown()){
          cameraShutterDelay = cameraShutterDelay - 1;
       }
       if (LCDML.BT_checkUp()){
       cameraShutterDelay = cameraShutterDelay + 1;
       } 
    }
    lcd.setCursor(15, 0); // set cursor
    lcd.print("      ");
    lcd.setCursor(15, 0); // set cursor
    lcd.print(cameraShutterDelay);
  }

  if(LCDML.FUNC_close())
  {
    LCDML.FUNC_goBackToMenu();
  }
}
// *********************************************************************
void mFunc_shutter_close_delay(uint8_t param)
// *********************************************************************
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // update LCD content
    lcd.setCursor(0, 0); // set cursor
    lcd.print("close delay:"); // print change content
  }

  if(LCDML.FUNC_loop())
  {
    if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
    {
      //LCDML.FUNC_goBackToMenu();  // leave this function
       if (LCDML.BT_checkDown()){
          cameraShutterCloseDelay = cameraShutterCloseDelay - 1;
       }
       if (LCDML.BT_checkUp()){
       cameraShutterCloseDelay = cameraShutterCloseDelay + 1;
       } 
    }
    lcd.setCursor(12, 0); // set cursor
    lcd.print("      ");
    lcd.setCursor(12, 0); // set cursor
    lcd.print(cameraShutterCloseDelay);
  }

  if(LCDML.FUNC_close())
  {
    LCDML.FUNC_goBackToMenu();
  }
}
// *********************************************************************
void mFunc_solenoid_delay(uint8_t param)
// *********************************************************************
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // update LCD content
    lcd.setCursor(0, 0); // set cursor
    lcd.print("solenoid delay:"); // print change content
  }

  if(LCDML.FUNC_loop())
  {
    if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
    {
      //LCDML.FUNC_goBackToMenu();  // leave this function
       if (LCDML.BT_checkDown()){
          solenoidDelay = solenoidDelay - 1;
       }
       if (LCDML.BT_checkUp()){
       solenoidDelay = solenoidDelay + 1;
       } 
    }
    lcd.setCursor(15, 0); // set cursor
    lcd.print("      ");
    lcd.setCursor(15, 0); // set cursor
    lcd.print(solenoidDelay);
  }

  if(LCDML.FUNC_close())
  {
    LCDML.FUNC_goBackToMenu();
  }
}

// *********************************************************************
void mFunc_camera_reset_delay(uint8_t param)
// *********************************************************************
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // update LCD content
    lcd.setCursor(0, 0); // set cursor
    lcd.print("camera reset delay:"); // print change content
  }

  if(LCDML.FUNC_loop())
  {
    if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
    {
      //LCDML.FUNC_goBackToMenu();  // leave this function
       if (LCDML.BT_checkDown()){
          resetCameraDelay = resetCameraDelay - 1;
       }
       if (LCDML.BT_checkUp()){
       resetCameraDelay = resetCameraDelay + 1;
       } 
    }
    lcd.setCursor(15, 0); // set cursor
    lcd.print("      ");
    lcd.setCursor(15, 0); // set cursor
    lcd.print(resetCameraDelay);
  }

  if(LCDML.FUNC_close())
  {
    LCDML.FUNC_goBackToMenu();
  }
}

// *********************************************************************
unsigned long g_timer_3 = 0;    // timer variable (global variable)
// *********************************************************************
void mFunc_status(uint8_t param)
// *********************************************************************
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    enableDrop = 1;
    // setup function
    lcd.setCursor(0, 0);
    lcd.print(F("Drop Delay:"));
    lcd.print(dropDelay);
    lcd.setCursor(0, 1);
    lcd.print(F("Current Status:"));
    lcd.setCursor(0, 2);
    lcd.print(currentStatus);
    
//    LCDML.TIMER_msReset(g_timer_3);
//    LCDML.FUNC_setLoopInterval(1000);  // starts a trigger event for the loop function every 100 milliseconds
  }

//  if(LCDML.FUNC_loop())           // ****** LOOP *********
//  {
//    if(LCDML.TIMER_ms(g_timer_3, 500)) {
//      lcd.setCursor(0, 3);
//      lcd.print("                    "); //20 spaces to reset line
//      lcd.setCursor(0, 3);
//      lcd.print(currentStatus);
//    }
    // loop function, can be run in a loop when LCDML_DISP_triggerMenu(xx) is set
    // the quit button works in every DISP function without any checks; it starts the loop_end function
//    if(LCDML.BT_checkAny()) { // check if any button is pressed (enter, up, down, left, right)
      // LCDML_goToMenu stops a running menu function and goes to the menu
//      LCDML.FUNC_goBackToMenu();
//    }
//  }

  if(LCDML.FUNC_close())      // ****** STABLE END *********
  {
    // you can here reset some global vars or do nothing
    enableDrop = 0;
  }
}

// *********************************************************************
// *********************************************************************
void mFunc_dump(uint8_t param)
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // setup function
    lcd.setCursor(0, 0);
    lcd.print(F("Hold to dump water:"));
    enableDump = 1;
    //    LCDML.TIMER_msReset(g_timer_3);
    //LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 milliseconds
  }

  if(LCDML.FUNC_loop())           // ****** LOOP *********
  {
    // loop function, can be run in a loop when LCDML_DISP_triggerMenu(xx) is set
    // the quit button works in every DISP function without any checks; it starts the loop_end function
    if(LCDML.BT_checkAny()) { // check if any button is pressed (enter, up, down, left, right)
      // LCDML_goToMenu stops a running menu function and goes to the menu
        LCDML.FUNC_goBackToMenu();
      }
  }

  if(LCDML.FUNC_close())      // ****** STABLE END *********
  {
    enableDump = 0;
    // you can here reset some global vars or do nothing
    
  }
}
// *********************************************************************
// *********************************************************************
void mFunc_sensor(uint8_t param)
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // setup function
    lcd.setCursor(0, 0);
    lcd.print(F("sensor is: "));
    //    LCDML.TIMER_msReset(g_timer_3);
    LCDML.FUNC_setLoopInterval(10);  // starts a trigger event for the loop function every 100 milliseconds
  }

  if(LCDML.FUNC_loop())           // ****** LOOP *********
  {
    lcd.setCursor(11,0);
    lcd.print("    ");
    lcd.setCursor(11,0);
     int photovalue = analogRead(A0); //int photovalue = analogRead(photoTransistor);
     lcd.print(photovalue);
     
    // loop function, can be run in a loop when LCDML_DISP_triggerMenu(xx) is set
    // the quit button works in every DISP function without any checks; it starts the loop_end function
    if(LCDML.BT_checkAny()) { // check if any button is pressed (enter, up, down, left, right)
      // LCDML_goToMenu stops a running menu function and goes to the menu
        LCDML.FUNC_goBackToMenu();
      }
  }

  if(LCDML.FUNC_close())      // ****** STABLE END *********
  {
    // you can here reset some global vars or do nothing
  }
}
// *********************************************************************
// *********************************************************************
void mFunc_test(uint8_t param)
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // setup function
    enableTest  = 1;
    lcd.setCursor(0, 0);
//    lcd.print(F("sensor is: "));
    //    LCDML.TIMER_msReset(g_timer_3);
    LCDML.FUNC_setLoopInterval(1000);  // starts a trigger event for the loop function every 100 milliseconds
  }

  if(LCDML.FUNC_loop())           // ****** LOOP *********
  {
    lcd.setCursor(0,0);
    lcd.print(F("                            "));
    lcd.setCursor(0,0);
    lcd.print(currentStatus);
    lcd.setCursor(0,1);
    lcd.print(F("                             "));
    lcd.setCursor(0,1);
    lcd.print(dropTotal);
    lcd.print(F(" / "));
    lcd.print(dropCount);
    float percentage = (float)dropCount/(float)dropTotal;
    percentage = (percentage*100);
    lcd.print(F(" = "));
    lcd.print(percentage);
//    lcd.setCursor(11,0);
     
    // loop function, can be run in a loop when LCDML_DISP_triggerMenu(xx) is set
    // the quit button works in every DISP function without any checks; it starts the loop_end function
    if(LCDML.BT_checkAny()) { // check if any button is pressed (enter, up, down, left, right)
      // LCDML_goToMenu stops a running menu function and goes to the menu
        LCDML.FUNC_goBackToMenu();
      }
  }

  if(LCDML.FUNC_close())      // ****** STABLE END *********
  {
    // you can here reset some global vars or do nothing
    enableTest  = 0;
    dropCount = 0;
    dropTotal = 0;
  }
}


// *********************************************************************
//uint8_t g_func_timer_info = 0;  // time counter (global variable)
//unsigned long g_timer_1 = 0;    // timer variable (global variable)
//void mFunc_timer_info(uint8_t param)
//// *********************************************************************
//{
//  if(LCDML.FUNC_setup())          // ****** SETUP *********
//  {
//    lcd.print(F("20 sec wait")); // print some content on first row
//    g_func_timer_info = 20;       // reset and set timer
//    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 milliseconds
//
//    LCDML.TIMER_msReset(g_timer_1);
//  }
//
//
//  if(LCDML.FUNC_loop())           // ****** LOOP *********
//  {
//    // loop function, can be run in a loop when LCDML_DISP_triggerMenu(xx) is set
//    // the quit button works in every DISP function without any checks; it starts the loop_end function
//
//    // reset screensaver timer
//    LCDML.SCREEN_resetTimer();
//
//    // this function is called every 100 milliseconds
//
//    // this method checks every 1000 milliseconds if it is called
//    if(LCDML.TIMER_ms(g_timer_1, 1000)) {
//      g_func_timer_info--;                // increment the value every second
//      lcd.setCursor(0, 0);                // set cursor pos
//      lcd.print(F("  "));
//      lcd.setCursor(0, 0);                // set cursor pos
//      lcd.print(g_func_timer_info);       // print the time counter value
//    }
//
//    // this function can only be ended when quit button is pressed or the time is over
//    // check if the function ends normally
//    if (g_func_timer_info <= 0)
//    {
//      // leave this function
//      LCDML.FUNC_goBackToMenu();
//    }
//  }
//
//  if(LCDML.FUNC_close())      // ****** STABLE END *********
//  {
//    // you can here reset some global vars or do nothing
//  }
//}


// *********************************************************************
//uint8_t g_button_value = 0; // button value counter (global variable)
//void mFunc_p2(uint8_t param)
//// *********************************************************************
//{
//  if(LCDML.FUNC_setup())          // ****** SETUP *********
//  {
//    // setup function
//    // print LCD content
//    // print LCD content
//    lcd.setCursor(0, 0);
//    lcd.print(F("press left or up"));
//    lcd.setCursor(0, 1);
//    lcd.print(F("count: 0 of 3"));
//    // Reset Button Value
//    g_button_value = 0;
//
//    // Disable the screensaver for this function until it is closed
//    LCDML.FUNC_disableScreensaver();
//
//  }
//
//  if(LCDML.FUNC_loop())           // ****** LOOP *********
//  {
//    // the quit button works in every DISP function without any checks; it starts the loop_end function
//    if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
//    {
//      if (LCDML.BT_checkLeft() || LCDML.BT_checkUp()) // check if button left is pressed
//      {
//        LCDML.BT_resetLeft(); // reset the left button
//        LCDML.BT_resetUp(); // reset the left button
//        g_button_value++;
//
//        // update LCD content
//        // update LCD content
//        lcd.setCursor(7, 1); // set cursor
//        lcd.print(g_button_value); // print change content
//      }
//    }
//
//    // check if button count is three
//    if (g_button_value >= 3) {
//      LCDML.FUNC_goBackToMenu();      // leave this function
//    }
//  }
//
//  if(LCDML.FUNC_close())     // ****** STABLE END *********
//  {
//    // you can here reset some global vars or do nothing
//  }
//}



// *********************************************************************
//void mFunc_screensaver(uint8_t param)
//// *********************************************************************
//{
//  if(LCDML.FUNC_setup())          // ****** SETUP *********
//  {
//    // update LCD content
//    lcd.setCursor(0, 0); // set cursor
//    lcd.print("screensaver"); // print change content
//    lcd.setCursor(0, 1); // set cursor
//    lcd.print("press any key");
//    lcd.setCursor(0, 2); // set cursor
//    lcd.print("to leave it");
//    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 milliseconds
//  }
//
//  if(LCDML.FUNC_loop())
//  {
//    if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
//    {
//      LCDML.FUNC_goBackToMenu();  // leave this function
//    }
//  }
//
//  if(LCDML.FUNC_close())
//  {
//    // The screensaver go to the root menu
//    LCDML.MENU_goRoot();
//  }
//}



// *********************************************************************
void mFunc_back(uint8_t param)
// *********************************************************************
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // end function and go an layer back
    LCDML.FUNC_goBackToMenu(1);      // leave this function and go a layer back
  }
}


// *********************************************************************
void mFunc_goToRootMenu(uint8_t param)
// *********************************************************************
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // go to root and display menu
    LCDML.MENU_goRoot();
  }
}


// *********************************************************************
//void mFunc_jumpTo_timer_info(uint8_t param)
//// *********************************************************************
//{
//  if(LCDML.FUNC_setup())          // ****** SETUP *********
//  {
//    // Jump to main screen
//    LCDML.OTHER_jumpToFunc(mFunc_timer_info);
//  }
//}
