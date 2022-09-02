#ifndef DEFINITIONS_h
#define DEFINITIONS_h

#define uint unsigned int

const uint PROGMEM PIN_PARALLEL_LOAD = 7;
const uint PROGMEM PIN_CLOCK_ENABLE = 4;
const uint PROGMEM PIN_CLOCK = 6;
const uint PROGMEM PIN_DATA = 5;

const uint PROGMEM PIN_ANALOG_0 = A0;
const bool PROGMEM PIN_ANALOG_ENABLE_0 = true;
const uint PROGMEM PIN_ANALOG_1 = A1;
const bool PROGMEM PIN_ANALOG_ENABLE_1 = true;
const uint PROGMEM PIN_ANALOG_2 = A2;
const bool PROGMEM PIN_ANALOG_ENABLE_2 = true;
const uint PROGMEM PIN_ANALOG_3 = A3;
const bool PROGMEM PIN_ANALOG_ENABLE_3 = true;
const uint PROGMEM PIN_ANALOG_4 = A4;
const bool PROGMEM PIN_ANALOG_ENABLE_4 = true;
const uint PROGMEM PIN_ANALOG_5 = A5;
const bool PROGMEM PIN_ANALOG_ENABLE_5 = true;

const uint PROGMEM NUMBER_OF_SHIFT_REGISTERS = 16;
const uint PROGMEM SHIFT_DATA_WIDTH = 8;
const uint PROGMEM DATA_WIDTH = (NUMBER_OF_SHIFT_REGISTERS * SHIFT_DATA_WIDTH);

const uint PROGMEM PULSE_WIDTH_USEC = 5;
const uint PROGMEM POLL_DELAY_MSEC = 1;

const uint PROGMEM SW_SWITCH = 1;
const uint PROGMEM SW_MOMENTARY = 2;
const uint PROGMEM SW_ROTARY = 3;

uint cachedShiftValues[NUMBER_OF_SHIFT_REGISTERS];

const uint PROGMEM swDefs[128]
{
    SW_SWITCH, // 1
    SW_SWITCH, // 2
    SW_SWITCH, // 3
    SW_SWITCH, // 4
    SW_SWITCH, // 5
    SW_SWITCH, // 6
    SW_SWITCH, // 7
    SW_SWITCH, // 8
    SW_SWITCH, // 9
    SW_SWITCH, // 10
    SW_SWITCH, // 11
    SW_SWITCH, // 12
    SW_SWITCH, // 13
    SW_SWITCH, // 14
    SW_SWITCH, // 15
    SW_SWITCH, // 16
    SW_SWITCH, // 17
    SW_SWITCH, // 18
    SW_SWITCH, // 19
    SW_SWITCH, // 20
    SW_SWITCH, // 21
    SW_SWITCH, // 22
    SW_SWITCH, // 23
    SW_SWITCH, // 24
    SW_SWITCH, // 25
    SW_SWITCH, // 26
    SW_SWITCH, // 27
    SW_SWITCH, // 28
    SW_SWITCH, // 29
    SW_SWITCH, // 30
    SW_SWITCH, // 31
    SW_SWITCH, // 32
    SW_SWITCH, // 33
    SW_SWITCH, // 34
    SW_SWITCH, // 35
    SW_SWITCH, // 36
    SW_SWITCH, // 37
    SW_SWITCH, // 38
    SW_SWITCH, // 39
    SW_SWITCH, // 40
    SW_SWITCH, // 41
    SW_SWITCH, // 42
    SW_SWITCH, // 43
    SW_SWITCH, // 44
    SW_SWITCH, // 45
    SW_SWITCH, // 46
    SW_SWITCH, // 47
    SW_SWITCH, // 48
    SW_SWITCH, // 49
    SW_SWITCH, // 50
    SW_SWITCH, // 51
    SW_SWITCH, // 52
    SW_SWITCH, // 53
    SW_SWITCH, // 54
    SW_SWITCH, // 55
    SW_SWITCH, // 56
    SW_SWITCH, // 57
    SW_SWITCH, // 58
    SW_SWITCH, // 59
    SW_SWITCH, // 60
    SW_SWITCH, // 61
    SW_SWITCH, // 62
    SW_SWITCH, // 63
    SW_SWITCH, // 64
    SW_SWITCH, // 65
    SW_SWITCH, // 66
    SW_SWITCH, // 67
    SW_SWITCH, // 68
    SW_SWITCH, // 69
    SW_SWITCH, // 70
    SW_SWITCH, // 71
    SW_SWITCH, // 72
    SW_SWITCH, // 73
    SW_SWITCH, // 74
    SW_SWITCH, // 75
    SW_SWITCH, // 76
    SW_SWITCH, // 77
    SW_SWITCH, // 78
    SW_SWITCH, // 79
    SW_SWITCH, // 80
    SW_SWITCH, // 81
    SW_SWITCH, // 82
    SW_SWITCH, // 83
    SW_SWITCH, // 84
    SW_SWITCH, // 85
    SW_SWITCH, // 86
    SW_SWITCH, // 87
    SW_SWITCH, // 88
    SW_SWITCH, // 89
    SW_SWITCH, // 90
    SW_SWITCH, // 91
    SW_SWITCH, // 92
    SW_SWITCH, // 93
    SW_SWITCH, // 94
    SW_SWITCH, // 95
    SW_SWITCH, // 96
    SW_SWITCH, // 97
    SW_SWITCH, // 98
    SW_SWITCH, // 99
    SW_SWITCH, // 100
    SW_SWITCH, // 101
    SW_SWITCH, // 102
    SW_SWITCH, // 103
    SW_SWITCH, // 104
    SW_SWITCH, // 105
    SW_SWITCH, // 106
    SW_SWITCH, // 107
    SW_SWITCH, // 108
    SW_SWITCH, // 109
    SW_SWITCH, // 110
    SW_SWITCH, // 111
    SW_SWITCH, // 112
    SW_SWITCH, // 113
    SW_SWITCH, // 114
    SW_SWITCH, // 115
    SW_SWITCH, // 116
    SW_SWITCH, // 117
    SW_SWITCH, // 118
    SW_SWITCH, // 119
    SW_SWITCH, // 120
    SW_SWITCH, // 121
    SW_SWITCH, // 122
    SW_SWITCH, // 123
    SW_SWITCH, // 124
    SW_SWITCH, // 125
    SW_SWITCH, // 126
    SW_SWITCH, // 127
    SW_SWITCH  // 128
};

#endif
