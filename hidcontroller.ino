#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_MULTI_AXIS, 128, 0, true, true, true, true, true, true, true, true, true, true, true);

#include "definitions.h"
#include "functions.h"

void setup() 
{
  Serial.begin(9600);

  pinMode(PIN_PARALLEL_LOAD, OUTPUT);
  pinMode(PIN_CLOCK_ENABLE, OUTPUT);
  pinMode(PIN_CLOCK, OUTPUT);
  pinMode(PIN_DATA, INPUT);

  Joystick.begin();
}

void loop() 
{
  HandlePots();
  SendClockLoadPulse();
  
  for(uint i = 0; i < NUMBER_OF_SHIFT_REGISTERS; i++)
  {
    uint bitVal = 0;
    uint shiftValues  = 0;
    
    for(uint j = 0; j < SHIFT_DATA_WIDTH; j++)
    {
        bitVal = digitalRead(PIN_DATA);
        shiftValues |= (bitVal << j);
        
        SendRisingEdge(PIN_CLOCK, PULSE_WIDTH_USEC);
    }

    if(shiftValues != cachedShiftValues[i])
    {
      for(uint k = 0; k < SHIFT_DATA_WIDTH; k++)
      {
        auto bitValue = (shiftValues >> k) & 1;
        
        //Only process the changed bits
        if(bitValue != ((cachedShiftValues[i] >> k) & 1))
        {
          ProcessBitChange(k, bitValue ? HIGH : LOW, i);
        }
      }
      
      cachedShiftValues[i] = shiftValues;
    }
  }
  
  delay(POLL_DELAY_MSEC);
}
