#include "controller.h"

void Controller::HandlePots()
{
  uint32 analog_0 = analogRead(ANALOG_0);
  uint32 analog_1 = analogRead(ANALOG_1);
  uint32 analog_2 = analogRead(ANALOG_2);
  uint32 analog_3 = analogRead(ANALOG_3);
  uint32 analog_4 = analogRead(ANALOG_4);
  uint32 analog_5 = analogRead(ANALOG_5);

  //set (analog_#); for 10k  /  (analog_# / 64); for 50k
  joystick.setRzAxis(analog_0 / 64);
  joystick.setXAxis(analog_1 / 64);
  joystick.setYAxis(analog_2 / 64);
  joystick.setZAxis(analog_3 / 64);
  joystick.setRxAxis(analog_4 / 64);
  joystick.setRyAxis(analog_5 / 64);
}

void Controller::HandleSwitch(uint value, uint state, uint registerNo)
{
  Serial.println(F("Handling as switch."));

  joystick.pressButton(value);
  Serial.println(F("JOYSTICK PRESS_BUTTON"));
  delay(100);
  joystick.releaseButton(value);
  Serial.println(F("JOYSTICK RELEASE_BUTTON"));
}

void Controller::HandleMomentary(uint value, uint state, uint registerNo)
{
  Serial.println(F("Handling as momentary."));

  if (state == HIGH)
  {
    joystick.pressButton(value);
    Serial.println(F("JOYSTICK PRESS_BUTTON"));
  }
  else
  {
    joystick.releaseButton(value);
    Serial.println(F("JOYSTICK RELEASE_BUTTON"));
  }
}

void Controller::HandleRotary(uint value, uint state, uint registerNo)
{
  Serial.println(F("Handling as rotary."));

  if (state == HIGH)
  {
    joystick.pressButton(value);
    Serial.println(F("JOYSTICK PRESS_BUTTON"));
    delay(100);
    joystick.releaseButton(value);
    Serial.println(F("JOYSTICK RELEASE_BUTTON"));
  }
}

void Controller::ProcessBitChange(uint value, uint state, uint registerNo)
{
  Serial.print(F("Changed Input: ["));
  Serial.print(value);
  Serial.print(F("] on shift register ["));
  Serial.print(registerNo);
  Serial.print(F("] to "));
  Serial.print(state ? "HIGH" : "LOW");
  Serial.print(F("\r\n"));

  uint swIndex = (registerNo * SHIFT_DATA_WIDTH) + value;
  uint swType = pgm_read_word(&swDefs[swIndex]);

  Serial.print(F("Processing index "));
  Serial.print(swIndex);
  Serial.print(F("\r\n"));

  switch (swType)
  {
    case SWITCH:
      HandleSwitch(swIndex, state, registerNo);
      break;

    case MOMENTARY:
      HandleMomentary(swIndex, state, registerNo);
      break;

    case ROTARY:
      HandleRotary(swIndex, state, registerNo);
      break;

    default:
      Serial.print(F("Could not find SW type with index of "));
      Serial.print(swIndex);
      Serial.print(F(" and type "));
      Serial.print(swType);
      Serial.print(F("\r\n"));
      break;
  }
}

void Controller::SendClockLoadPulse()
{
  digitalWrite(CLOCK_ENABLE, HIGH);
  digitalWrite(PARALLEL_LOAD, LOW);
  delayMicroseconds(PULSE_WIDTH_USEC);
  digitalWrite(PARALLEL_LOAD, HIGH);
  digitalWrite(CLOCK_ENABLE, LOW);
}

void Controller::SendRisingEdge(uint pin, uint delayUSec)
{
  digitalWrite(pin, HIGH);
  delayMicroseconds(delayUSec);
  digitalWrite(pin, LOW);
}

void Controller::ReadShiftRegisters()
{
  for(uint i = 0; i < NUMBER_OF_SHIFT_REGS; i++)
  {
    uint bitVal = 0;
    uint shiftValues  = 0;
    
    for(uint j = 0; j < SHIFT_DATA_WIDTH; j++)
    {
        bitVal = digitalRead(DATA);
        shiftValues |= (bitVal << j);
       
        SendRisingEdge(CLOCK, PULSE_WIDTH_USEC);
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
}

Joystick_ Controller::GetJoystick()
{
  return joystick;
}

void Controller::Init()
{
  pinMode(PARALLEL_LOAD, OUTPUT);
  pinMode(CLOCK_ENABLE, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, INPUT);
  
  joystick.begin();
}
