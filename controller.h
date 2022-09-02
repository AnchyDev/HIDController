#include <Joystick.h>
#include "definitions.h"

#ifndef CONTROLLER_h
#define CONTROLLER_h

class Controller
{
private:
  Joystick_ joystick;
  uint cachedShiftValues[NUMBER_OF_SHIFT_REGS];
  
  const uint swDefs[128]
  {
    SWITCH, // 1
    SWITCH, // 2
    SWITCH, // 3
    SWITCH, // 4
    SWITCH, // 5
    SWITCH, // 6
    SWITCH, // 7
    SWITCH, // 8
    SWITCH, // 9
    SWITCH, // 10
    SWITCH, // 11
    SWITCH, // 12
    SWITCH, // 13
    SWITCH, // 14
    SWITCH, // 15
    SWITCH, // 16
    SWITCH, // 17
    SWITCH, // 18
    SWITCH, // 19
    SWITCH, // 20
    SWITCH, // 21
    SWITCH, // 22
    SWITCH, // 23
    SWITCH, // 24
    SWITCH, // 25
    SWITCH, // 26
    SWITCH, // 27
    SWITCH, // 28
    SWITCH, // 29
    SWITCH, // 30
    SWITCH, // 31
    SWITCH, // 32
    SWITCH, // 33
    SWITCH, // 34
    SWITCH, // 35
    SWITCH, // 36
    SWITCH, // 37
    SWITCH, // 38
    SWITCH, // 39
    SWITCH, // 40
    SWITCH, // 41
    SWITCH, // 42
    SWITCH, // 43
    SWITCH, // 44
    SWITCH, // 45
    SWITCH, // 46
    SWITCH, // 47
    SWITCH, // 48
    SWITCH, // 49
    SWITCH, // 50
    SWITCH, // 51
    SWITCH, // 52
    SWITCH, // 53
    SWITCH, // 54
    SWITCH, // 55
    SWITCH, // 56
    SWITCH, // 57
    SWITCH, // 58
    SWITCH, // 59
    SWITCH, // 60
    SWITCH, // 61
    SWITCH, // 62
    SWITCH, // 63
    SWITCH, // 64
    SWITCH, // 65
    SWITCH, // 66
    SWITCH, // 67
    SWITCH, // 68
    SWITCH, // 69
    SWITCH, // 70
    SWITCH, // 71
    SWITCH, // 72
    SWITCH, // 73
    SWITCH, // 74
    SWITCH, // 75
    SWITCH, // 76
    SWITCH, // 77
    SWITCH, // 78
    SWITCH, // 79
    SWITCH, // 80
    SWITCH, // 81
    SWITCH, // 82
    SWITCH, // 83
    SWITCH, // 84
    SWITCH, // 85
    SWITCH, // 86
    SWITCH, // 87
    SWITCH, // 88
    SWITCH, // 89
    SWITCH, // 90
    SWITCH, // 91
    SWITCH, // 92
    SWITCH, // 93
    SWITCH, // 94
    SWITCH, // 95
    SWITCH, // 96
    SWITCH, // 97
    SWITCH, // 98
    SWITCH, // 99
    SWITCH, // 100
    SWITCH, // 101
    SWITCH, // 102
    SWITCH, // 103
    SWITCH, // 104
    SWITCH, // 105
    SWITCH, // 106
    SWITCH, // 107
    SWITCH, // 108
    SWITCH, // 109
    SWITCH, // 110
    SWITCH, // 111
    SWITCH, // 112
    SWITCH, // 113
    SWITCH, // 114
    SWITCH, // 115
    SWITCH, // 116
    SWITCH, // 117
    SWITCH, // 118
    SWITCH, // 119
    SWITCH, // 120
    SWITCH, // 121
    SWITCH, // 122
    SWITCH, // 123
    SWITCH, // 124
    SWITCH, // 125
    SWITCH, // 126
    SWITCH, // 127
    SWITCH  // 128
  };
  
public:
  void HandlePots();
  void ProcessBitChange(uint value, uint state, uint registerNo);
  void SendClockLoadPulse();
  void SendRisingEdge(uint pin, uint delayUSec);
  void ReadShiftRegisters();
  Joystick_ GetJoystick();
  void Init();
  
private:
  void HandleSwitch(uint value, uint state, uint registerNo);
  void HandleMomentary(uint value, uint state, uint registerNo);
  void HandleRotary(uint value, uint state, uint registerNo);
  
};

#endif
