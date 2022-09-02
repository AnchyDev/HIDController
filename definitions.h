#ifndef DEFINITIONS_h
#define DEFINITIONS_h

#define uint unsigned int

  enum PROGMEM PINS : uint
  {
    PARALLEL_LOAD = 7,
    CLOCK_ENABLE = 4,
    CLOCK = 6,
    DATA = 5,
    ANALOG_0 = A0,
    ANALOG_1 = A1,
    ANALOG_2 = A2,
    ANALOG_3 = A3,
    ANALOG_4 = A4,
    ANALOG_5 = A5
  };

  enum PROGMEM DEF_VALUES
  {
    NUMBER_OF_SHIFT_REGS = 16,
    SHIFT_DATA_WIDTH = 8,
    DATA_WIDTH = (NUMBER_OF_SHIFT_REGS * SHIFT_DATA_WIDTH),
    PULSE_WIDTH_USEC = 5,
    POLL_DELAY_MSEC = 1
  };

  enum PROGMEM SW_TYPES
  {
    SWITCH,
    MOMENTARY,
    ROTARY
  };
#endif
