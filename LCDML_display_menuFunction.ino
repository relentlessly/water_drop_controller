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
  }

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
