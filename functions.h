#include "definitions.h"

#ifndef FUNCTIONS_h
#define FUNCTIONS_h

void HandlePots()
{
  if(PIN_ANALOG_ENABLE_0)
  {
    uint32_t analog_0 = analogRead(PIN_ANALOG_0);
    Joystick.setRzAxis(analog_0 / 64);
  }
 
  uint32_t analog_1 = analogRead(PIN_ANALOG_1);
  uint32_t analog_2 = analogRead(PIN_ANALOG_2);
  uint32_t analog_3 = analogRead(PIN_ANALOG_3);
  uint32_t analog_4 = analogRead(PIN_ANALOG_4);
  uint32_t analog_5 = analogRead(PIN_ANALOG_5);

  //set (analog_#); for 10k  /  (analog_# / 64); for 50k
  Joystick.setXAxis(analog_1 / 64);
  Joystick.setYAxis(analog_2 / 64);
  Joystick.setZAxis(analog_3 / 64);
  Joystick.setRxAxis(analog_4 / 64);
  Joystick.setRyAxis(analog_5 / 64);
}

void HandleSwitch(uint value, uint state, uint registerNo)
{
  Serial.println(F("Handling as switch."));

  Joystick.pressButton(value);
  Serial.println(F("JOYSTICK PRESS_BUTTON"));
  delay(100);
  Joystick.releaseButton(value);
  Serial.println(F("JOYSTICK RELEASE_BUTTON"));
}

void HandleMomentary(uint value, uint state, uint registerNo)
{
  Serial.println(F("Handling as momentary."));

  if (state == HIGH)
  {
    Joystick.pressButton(value);
    Serial.println(F("JOYSTICK PRESS_BUTTON"));
  }
  else
  {
    Joystick.releaseButton(value);
    Serial.println(F("JOYSTICK RELEASE_BUTTON"));
  }
}

void HandleRotary(uint value, uint state, uint registerNo)
{
  Serial.println(F("Handling as rotary."));

  if (state == HIGH)
  {
    Joystick.pressButton(value);
    Serial.println(F("JOYSTICK PRESS_BUTTON"));
    delay(100);
    Joystick.releaseButton(value);
    Serial.println(F("JOYSTICK RELEASE_BUTTON"));
  }
}

void ProcessBitChange(uint value, uint state, uint registerNo)
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
    case SW_SWITCH:
      HandleSwitch(swIndex, state, registerNo);
      break;

    case SW_MOMENTARY:
      HandleMomentary(swIndex, state, registerNo);
      break;

    case SW_ROTARY:
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

void SendClockLoadPulse()
{
  digitalWrite(PIN_CLOCK_ENABLE, HIGH);
  digitalWrite(PIN_PARALLEL_LOAD, LOW);
  delayMicroseconds(PULSE_WIDTH_USEC);
  digitalWrite(PIN_PARALLEL_LOAD, HIGH);
  digitalWrite(PIN_CLOCK_ENABLE, LOW);
}

void SendRisingEdge(uint pin, uint delayUSec)
{
  digitalWrite(pin, HIGH);
  delayMicroseconds(delayUSec);
  digitalWrite(pin, LOW);
}

#endif
