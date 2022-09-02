#include "controller.h"

Controller controller;

void setup() 
{
  Serial.begin(9600);

  controller.Init();
}

void loop() 
{
  controller.HandlePots();
  controller.SendClockLoadPulse();
  controller.ReadShiftRegisters();
  
  delay(POLL_DELAY_MSEC);
}
