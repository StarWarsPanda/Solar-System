#pragma once

#include <tice.h>
#include <ti/real.h>

extern int8_t _sin[255];

int sin(uint16_t x);

void intToString(int value, char* str);
void floatToString(float value, char* str);